class Solution {
public:
    // dynamic programming
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        vector<int> dp (s.size()+1, 0);
        dp[0] = dp[1] = 1;

        for(int i = 1; i <= s.size(); i++) {
            int tmp = 0;
            if (s[i-1] >= '1') {
                tmp += dp[i-1];
            }

            if (i >= 2) {
                if ((s[i-2] == '2' && s[i-1] <= '6') || (s[i-2] == '1')) {
                    tmp += dp[i-2];
                }
            }
            dp[i] = tmp;
        }
        return dp[s.size()];
    }
};
