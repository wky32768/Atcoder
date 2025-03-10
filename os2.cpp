#include <iostream>
#include <list>
#include <cstdlib> 
#include <ctime> 

using namespace std;

#define free 0
#define ready 1
#define running 2
#define ts 2 /* time slice */

struct PCB {
    int pid;     /* 进程ID */
    int pstate;  /* 进程状态 */
    char *pname; /* 映象名称 */
    int ptime;   /* 剩余运行时间 */
};

// 全局队列
list<PCB> freeQueue, readyQueue, runningQueue;

// 函数声明
void initFreeQueue(int N);
void createProcess(int n, int times[]);
void schedule();
void printQueues();

void initFreeQueue(int N) { // 初始化空闲队列
    for (int i = 0; i < N; ++i) {
        PCB pcb;
        pcb.pid = i;
        pcb.pstate = free;
        pcb.pname = new char[3];
        sprintf(pcb.pname, "P%d", i);
        pcb.ptime = 0;
        freeQueue.push_back(pcb);
    }
}

void createProcess(int n, int times[]) { // 创建进程
    for (int i = 0; i < n; ++i) {
        PCB pcb = freeQueue.front();
        freeQueue.pop_front();
        pcb.pstate = ready;
        pcb.ptime = times[i];
        readyQueue.push_back(pcb);
    }
}

void schedule() { // 调度
    if (!runningQueue.empty()) {
        PCB &runningPcb = runningQueue.front();
        runningPcb.ptime -= ts;
        if (runningPcb.ptime <= 0) {
            cout << "Sched: " << runningPcb.pname << "(Running -> Finished, T: 0)" << endl;
            runningPcb.pstate = free;
            freeQueue.push_back(runningPcb);
            runningQueue.pop_front();
        } else {
            cout << "Sched: " << runningPcb.pname << "(Running -> Ready, T: " << runningPcb.ptime << ")" << endl;
            runningPcb.pstate = ready;
            readyQueue.push_back(runningPcb);
            runningQueue.pop_front();
        }
    }

    if (!readyQueue.empty()) {
        PCB &readyPcb = readyQueue.front();
        readyQueue.pop_front();
        cout << "Sched: " << readyPcb.pname << "(Ready -> Running,  T: " << readyPcb.ptime << ")" << endl;
        readyPcb.pstate = running;
        runningQueue.push_back(readyPcb);
    }

    printQueues();
}

void printQueues() { // 打印队列
    cout << "Running: ";
    for (const PCB &pcb : runningQueue) {
        cout << pcb.pname << "(" << pcb.ptime << ") ";
    }
    cout << endl;

    cout << "Ready: ";
    for (const PCB &pcb : readyQueue) {
        cout << pcb.pname << "(" << pcb.ptime << ")->";
    }
    if (!readyQueue.empty()) cout << "END";
    cout << endl << endl;
}

int main() {
    int N, n;
    cout << "Enter the number of PCBs in freeQueue: ";
    cin >> N;
    initFreeQueue(N);

    cout << "Enter the number of processes to create: ";
    cin >> n;
    int times[n];
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    createProcess(n, times);

    while (!readyQueue.empty() || !runningQueue.empty()) {
        schedule();
    }

    cout << "All processes finished." << endl;
    return 0;
}
