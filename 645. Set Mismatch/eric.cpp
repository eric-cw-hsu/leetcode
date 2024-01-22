class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans (2, 0);
        unordered_map<int, int> mp;

        for (auto num: nums) {
            mp[num]++;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (mp.count(i) == 0) {
                ans[1] = i;
            }

            if (mp[i] > 1) {
                ans[0] = i;
            }
        }

        return ans;
    }
};
