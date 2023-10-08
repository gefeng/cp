#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

const int INF = (int)2e9;

class Solution {
public:
    int minOperations(std::string s1, std::string s2, int x) {
        int n = s1.size();
        std::vector<int> a;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                a.push_back(i);
            }
        }
        
        int sz = a.size();
        if(sz & 1) {
            return -1;
        }
        if(sz == 0) {
            return 0;
        }
        
        std::vector<std::vector<int>> dp(sz, std::vector<int>(sz, INF));
        
        for(int i = 0; i < sz; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if((i - j) & 1) {
                    if(i - j == 1) {
                        dp[j][i] = std::min(x, a[i] - a[j]);
                    } else {
                        dp[j][i] = std::min(dp[j + 1][i - 1] + std::min(x, a[i] - a[j]), dp[j + 2][i] + std::min(x, a[j + 1] - a[j]));
                        
                        for(int k = j + 3; k < i; k += 2) {
                            dp[j][i] = std::min(dp[j][i], dp[j][k] + dp[k + 1][i]);
                        }
                    }
                }
            }    
        }
        
        return dp[0][sz - 1];
    }
};
