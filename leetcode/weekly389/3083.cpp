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
    bool isSubstringPresent(std::string s) {
        int n = s.size();
        
        std::string t(s);
        std::reverse(t.begin(), t.end());
        
        for(int i = 0; i < n - 1; i++) {
            std::string ss = s.substr(i, 2);
            if(t.find(ss) != std::string::npos) {
                return true;
            }
        }
        
        return false;
    }
};
