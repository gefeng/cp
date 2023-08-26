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
    bool isAcronym(std::vector<std::string>& words, std::string s) {
        int n = words.size();
        if(s.size() != n) {
            return false;
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] != words[i][0]) {
                return false;
            }
        }
        
        return true;
    }
};
