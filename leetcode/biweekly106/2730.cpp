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
    int longestSemiRepetitiveSubstring(std::string s) {
        int ans = 0;
        int n = s.size();
        
        int cnt = 0;
        for(int l = 0, r = 0; r < n; r++) {
            if(r > 0 && s[r] == s[r - 1]) {
                cnt += 1;
            }
            
            while(cnt > 1) {
                if(s[l] == s[l + 1]) {
                    cnt -= 1;
                }
                l += 1;
            }
            
            ans = std::max(ans, r - l + 1);
        }
        
        return ans;
    }
};
