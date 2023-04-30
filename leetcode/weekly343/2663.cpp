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
    std::string smallestBeautifulString(std::string s, int k) {
        int n = s.size();

        std::string ans = "";
        std::vector<bool> vis(26, false);
        
        for(int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if(vis[c]) {
                continue;
            }
            
            if(c + 1 >= k) {
                continue;
            }
            
            bool ok = false;
            for(int nc = c + 1; nc < k; nc++) {
                if((i && nc == s[i - 1] - 'a') || (i > 1 && nc == s[i - 2] - 'a')) {
                    continue;
                }
                
                ans = s.substr(0, i);
                ans.push_back((char)(nc + 'a'));
                ok = true;
                    
                for(int j = i + 1; j < n; j++) {
                    for(int cc = 0; cc < k; cc++) {
                        if((j - 1 >= 0 && cc == ans[j - 1] - 'a') || (j - 2 >= 0 && cc == ans[j - 2] - 'a')) {
                            continue;
                        }
                        
                        ans.push_back((char)(cc + 'a'));
                        break;
                    }
                }
                
                break;
            }
            
            if(ok) {
                break;
            }
        }
        
        return ans;
    }
};
