// Dynamic Programming
// with bit operation
// dp[i] = dp[i-power] + 1
// ex. 11 (1011): 3 bits = 3 (011): 2 bits + 1 (carry bit)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        
        vector<int> dp(n+1, 0);
        dp[1] = 1;

        int power = 1;
        for (int i = 2; i < n+1; i++) {
            if (power<<1 == i) {
                power <<= 1;
            }
            dp[i] = dp[i-power]+1;
        }

        return dp;
    }
};
