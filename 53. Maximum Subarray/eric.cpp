class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size(), ans = -1e9;
        if (length == 1) return nums[0];

        int hold = 0;
        for (int i = 0; i < length; i++) {
            hold += nums[i];
            ans = max(ans, hold);

            if (hold < 0) {
                hold = 0;
            }
        }

        return ans;
    }
};
