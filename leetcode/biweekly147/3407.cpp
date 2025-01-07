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
    bool hasMatch(std::string s, std::string p) {
        int n = s.size();
        int m = p.size();
        int pos = -1;
        for(int i = 0; i < m; i++) {
            if(p[i] == '*') {
                pos = i;
                break;
            }
        }
    
        std::string prefix = p.substr(0, pos);
        std::string suffix = p.substr(pos + 1, m - pos - 1);
    
        int first = -1;
        if(s.find(prefix) == std::string::npos) {
            return false;
        }
        
        first = s.find(prefix);
        
        
        if(s.find(suffix) == std::string::npos) {
            return false;
        }
        
        int last = 0;
        int now = 0;
        while(s.find(suffix, now) != std::string::npos) {
            last = s.find(suffix, now);
            now = last + 1;
        }
    
        if(last < first + prefix.size()) {
            return false;
        }
        
        return true;
    }
};
