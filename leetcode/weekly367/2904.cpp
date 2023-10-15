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
    std::string shortestBeautifulSubstring(std::string s, int k) {
        std::string ans = "";
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == '1') {
                    cnt += 1;
                }
                
                if(cnt == k) {
                    if(ans.empty() || j - i + 1 < ans.size()) {
                        ans = s.substr(i, j - i + 1);
                    } else if(j - i + 1 == ans.size()) {
                        std::string t = s.substr(i, j - i + 1);
                        if(t < ans) {
                            ans = t;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
