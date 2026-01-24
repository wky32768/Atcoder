class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // numbers left 00000 right rest
        int left = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                swap(nums[i], nums[left]);
                left++;
            }
        }
    }
};
