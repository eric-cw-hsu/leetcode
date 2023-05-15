class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (getNumTrees(i-1) * getNumTrees(n-i));
        }

        return ans;
    }

    int getNumTrees(int n) {
        if (!mp[n]) 
            mp[n] = numTrees(n);
        
        return mp[n];
    }
private:
    unordered_map<int, int> mp;
};

