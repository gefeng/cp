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
    int longestValidSubstring(std::string word, std::vector<std::string>& forbidden) {
        std::unordered_set<std::string> ban;
        for(std::string& s : forbidden) {
            ban.insert(s);
        }
        
        auto is_valid = [&](int l, int r) {
            for(int i = std::min(10, r - l + 1); i > 0; i--) {
                std::string s = word.substr(r - i + 1, i);
                if(ban.find(s) != ban.end()) {
                    return false;
                }
            }
            
            return true;
        };
        
        int ans = 0;
        int n = word.size();
        for(int l = 0, r = 0; r < n; r++) {
            while(l <= r && !is_valid(l, r)) {
                l += 1;
            }
            
            ans = std::max(ans, r - l + 1);
        }
        
        return ans;
    }
};
