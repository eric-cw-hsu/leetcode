class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) return 0;

        int now = 0, reach = nums[0], far = nums[0];
        int ans = 1;

        while (reach < length-1) {
            for (int i = now; i <= reach && i < length; i++) {
                far = max(far, i+nums[i]);
            }

            now = reach+1;
            reach = far;

            ans++;
        }

        return ans;
    }
};
