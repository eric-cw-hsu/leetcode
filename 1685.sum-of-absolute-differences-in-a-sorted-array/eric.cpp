class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;

        prefix.push_back(0);
        suffix.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix.back()+nums[i]);
            suffix.push_back(suffix.back()+nums[nums.size()-1-i]);
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int tmp = 0;
            tmp += (prefix.back()-prefix[i+1])-(nums[i]*(nums.size()-i-1));
            tmp += (nums[i]*i)-(suffix.back()-suffix[suffix.size()-i-1]);
            ans.push_back(tmp);
        }

        return ans;
    }
};
