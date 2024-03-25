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
    int maximumLengthSubstring(std::string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            std::array<int, 26> cnt = {};
            for(int j = i; j < n; j++) {
                cnt[s[j] - 'a'] += 1;
                
                bool ok = true;
                for(int k = 0; k < 26; k++) {
                    if(cnt[k] > 2) {
                        ok = false;
                        break;
                    }
                }
                
                if(ok) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
