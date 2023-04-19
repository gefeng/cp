#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) {
        int n = s.size();
        
        auto is_balanced = [](const std::string& t) {
            int cnt = 0;
            int n = t.size();
            for(int i = 0; i < n; i++) {
                if(t[i] == '0') {
                    cnt += 1;
                }
                if(i && t[i] == '0' && t[i - 1] == '1') {
                    return false;
                }
            }
            
            return cnt == n - cnt;
        };
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(is_balanced(s.substr(i, j - i + 1))) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
