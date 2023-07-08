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
    int minimumBeautifulSubstrings(std::string s) {
        int n = s.length();
        
        if(s[0] == '0') {
            return -1;
        }
        
        std::set<int> a;
        int p_5 = 1;
        for(int i = 0; i < 8; i++) {
            a.insert(p_5);
            p_5 *= 5;
        }
        
        int ans = n + 1;
        for(int i = 1; i < (1 << n); i++) {
            bool ok = true;
            int x = 0;
            int cnt = 1;
            for(int j = 0; j < n; j++) {
                x = x * 2 + s[j] - '0';
                
                if((i & (1 << j)) || j == n - 1) {
                    if(a.find(x) == a.end()) {
                        ok = false;
                        break;
                    }
                    x = 0;
                    if(j + 1 < n && s[j + 1] == '0') {
                        ok = false;
                        break;
                    }
                    if(j + 1 < n) {
                        cnt += 1;
                    }
                }
            }
            
            if(ok) {
                ans = std::min(ans, cnt);
            }
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};
