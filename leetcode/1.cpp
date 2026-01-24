class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, vector <int> > mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        for(int i = 0;i < nums.size();i++) {
            int need = target - nums[i];
            if(mp.find(need) != mp.end()) {
                for(auto &j : mp[need]) {
                    if(j != i) return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};