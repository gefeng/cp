#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int dp[32][1 << 11][2];
    int countSpecialNumbers(int n) {
        vector<int> digits;
        int x = n;
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
        }

        reverse(digits.begin(), digits.end());

        memset(dp, -1, sizeof(dp));
        return dfs(digits, 0, 0, 1);
    }

    int dfs(vector<int> digits, int cur, int mask, int bound) {
        if(cur == digits.size()) {
            return mask == 0 ? 0 : 1;
        }
        if(dp[cur][mask][bound] != -1) {
            return dp[cur][mask][bound];
        }

        int res = 0;
        if(mask == 0) {
            res += dfs(digits, cur + 1, mask, 0);
        }

        int st = mask == 0 ? 1 : 0;
        for(int i = st; i < 10; i++) {
            if(!(mask & (1 << i))) {
                if(bound && i < digits[cur]) {
                    res += dfs(digits, cur + 1, mask | (1 << i), bound ^ 1);
                } else if(!bound || i == digits[cur]) {
                    res += dfs(digits, cur + 1, mask | (1 << i), bound);
                }
            }
        }

        dp[cur][mask][bound] = res;
        return res;
    }
};
