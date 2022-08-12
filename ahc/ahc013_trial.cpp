//big sample: 468pts
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=205;
int n, m, mov, cnt;
int a[N][N], used[N][N];
char ch[N];
struct node {
    int x1, y1, x2, y2;
} movee[20005], ans[20005];
signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    For(i,1,n) {
        scanf("%s", ch+1);
        For(j,1,n) a[i][j]=ch[j]-'0';
    }
    For(i,1,n) {
        int last=0, lastis=0;
        For(j,1,n) {
            if(a[i][j]) {
                if(last==0) {last=j; lastis=a[i][j];}
                else if(lastis==a[i][j]) {
                    For(k,last, j) used[i][k]=a[i][j];
                    last=j;
                    cnt++;
                } else {
                    last=j; lastis=a[i][j];
                }
            }
        }
    }
    For(j,1,n) {
        int last=0, lastis=0;
        For(i,1,n) {
            if(a[i][j]) {
                if(last==0) {last=i; lastis=a[i][j];}
                else if(lastis==a[i][j]) {
                    int ok=1, last_occupied=0x3f3f3f3f;
                    For(k,last+1,i-1) {
                        if(used[k][j]) {ok=0; last_occupied=k;}
                    }
                    // if(ok==1) ans[++cnt]=(node) {last, j, i, j};
                    if(ok==0 && last_occupied+1<=i-1) {
                        // cout<<"debug "<<last<<" "<<last_occupied+1<<" "<<i<<" "<<j<<'\n';
                        if(a[last][j] && mov+(last_occupied-last+1)<=100*m-cnt && used[last][j]==0) {
                            For(k,last+1, last_occupied+1) movee[++mov]=(node) {k-1, j, k, j};
                            swap(a[last][j], a[last_occupied+1][j]);
                        }
                    } else if(ok==1) {
                        cnt++;
                        if(a[last][j] && used[last+1][j]==a[i][j] && a[last+1][j]==0 && mov+1<=100*m-cnt) {
                            movee[++mov]=(node) {last, j, last+1, j};
                            swap(a[last][j], a[last+1][j]);
                        } else if(a[last][j] && used[last-1][j]==a[i][j] && a[last-1][j]==0 && mov+1<=100*m-cnt) {
                            movee[++mov]=(node) {last, j, last-1, j};
                            swap(a[last][j], a[last-1][j]);
                        }
                    }
                } 
                
                last=i; lastis=a[i][j];
            }
        }
    }
    memset(used, 0, sizeof(used));
    cnt/=2;
    For(j,1,n) {
        int last=0, lastis=0;
        For(i,1,n) {
            if(a[i][j]) {
                if(last==0) {last=i; lastis=a[i][j];}
                else if(lastis==a[i][j]) {
                    For(k,last, i) used[k][j]=a[i][j];
                    last=i;
                    cnt++;
                } else {
                    last=i; lastis=a[i][j];
                }
            }
        }
    }
    For(i,1,n) {
        int last=0, lastis=0;
        For(j,1,n) {
            if(a[i][j]) {
                if(last==0) {last=j; lastis=a[i][j];}
                else if(lastis==a[i][j]) {
                    int ok=1, last_occupied=0x3f3f3f3f;
                    For(k,last+1,j-1) {
                        if(used[i][k]) {ok=0; last_occupied=k;}
                    }
                    // if(ok==1) ans[++cnt]=(node) {last, j, i, j};
                    if(ok==0 && last_occupied+1<=j-1) {
                        // cout<<"debug "<<last<<" "<<last_occupied+1<<" "<<i<<" "<<j<<'\n';
                        if(a[i][last] && mov+(last_occupied-last+1)<=100*m-cnt && used[i][last]==0) {
                            For(k,last+1, last_occupied+1) movee[++mov]=(node) {i, k-1, i, k};
                            swap(a[i][last], a[i][last_occupied+1]);
                        }
                    } else if(ok==1) {
                        cnt++;
                        if(a[i][last] && used[i][last+1]==a[i][j] && a[i][last+1]==0 && mov+1<=100*m-cnt) {
                            movee[++mov]=(node) {i, last, i, last+1};
                            swap(a[i][last], a[i][last+1]);
                        }
                        if(a[i][last] && used[i][last-1]==a[i][j] && a[i][last-1]==0 && mov+1<=100*m-cnt) {
                            movee[++mov]=(node) {i, last, i, last-1};
                            swap(a[i][last], a[i][last-1]);
                        }   
                    }
                }

                last=j; lastis=a[i][j];
            }
        }
    }


    cnt=0;
    memset(used, 0, sizeof used);
    // cout<<"Debug "<<a[12][12]<<'\n';
    For(i,1,n) {
        int last=0, lastis=0;
        For(j,1,n) {
            if(a[i][j]) {
                if(last==0) {last=j; lastis=a[i][j];}
                else if(lastis==a[i][j]) {
                    For(k,last, j) used[i][k]=a[i][j];
                    ans[++cnt]=(node){i, last, i, j};
                    last=j;
                } else {
                    last=j; lastis=a[i][j];
                }
            }
        }
    }
    For(j,1,n) {
        int last=0, lastis=0;
        For(i,1,n) {
            if(a[i][j]) {
                if(last==0) {last=i; lastis=a[i][j];}
                else if(lastis==a[i][j]) {
                    int ok=1, last_occupied=0;
                    For(k,last+1, i-1) if(used[k][j]) {ok=0; break;}
                    if(ok==1) ans[++cnt]=(node){last, j, i, j};
                        // cout<<"debug "<<last-1<<" "<<j<<'\n';
                    last=i;
                } else {
                    last=i; lastis=a[i][j];
                }
            }
        }
    }
    cnt=min(cnt, 100*m-mov);
    cout<<mov<<'\n';
    For(i,1,mov) cout<<movee[i].x1-1<<" "<<movee[i].y1-1<<" "<<movee[i].x2-1<<" "<<movee[i].y2-1<<'\n';
    cout<<cnt<<'\n';
    For(i,1,cnt) cout<<ans[i].x1-1<<" "<<ans[i].y1-1<<" "<<ans[i].x2-1<<" "<<ans[i].y2-1<<'\n';
    return 0;
}