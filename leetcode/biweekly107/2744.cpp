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
    int maximumNumberOfStringPairs(std::vector<std::string>& words) {
        std::set<std::string> seen;
        for(std::string& s : words) {
            seen.insert(s);
        }
        
        int ans = 0;
        for(std::string& s : words) {
            std::string t = s;
            std::reverse(t.begin(), t.end());
            
            if(s == t) {
                continue;
            }
            
            if(seen.find(t) != seen.end()) {
                ans += 1;
                seen.erase(t);
                seen.erase(s);
            }
        }
        
        return ans;
    }
};
