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
    std::string clearStars(std::string s) {
        int n = s.size();
        std::vector<std::set<int>> pos(26);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                for(int j = 0; j < 26; j++) {
                    if(!pos[j].empty()) {
                        auto it = pos[j].upper_bound(i);
                        pos[j].erase(std::prev(it));
                        break;
                    }
                }
            } else {
                pos[s[i] - 'a'].insert(i);
            }
        }
        
        std::string t(n, '*');
        std::string ans = "";
        for(int i = 0; i < 26; i++) {
            for(int p : pos[i]) {
                t[p] = (char)(i + 'a');
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(t[i] != '*') {
                ans.push_back(t[i]);
            }
        }
        
        return ans;
    }
};
