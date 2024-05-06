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
    int minAnagramLength(std::string s) {
        int n = s.size();
        int ans = n;
        
        auto is_ok = [&](int len) {
            std::array<int, 26> pre{};
            for(int i = 0; i < n; i += len) {
                std::array<int, 26> cur{};
                for(int j = 0; j < len; j++) {
                    cur[s[i + j] - 'a'] += 1;
                }
                
                if(i) {
                    for(int j = 0; j < 26; j++) {
                        if(cur[j] != pre[j]) {
                            return false;
                        }
                    }
                }
                std::swap(cur, pre);
            }
            return true;
        };
        
        for(int f = 1; f * f <= n; f++) {
            if(n % f == 0) {
                if(is_ok(f)) {
                    ans = std::min(ans, f);
                }
                if(n / f != f && is_ok(n / f)) {
                    ans = std::min(ans, n / f);
                }
            }
        }
        
        return ans;
    }
};
