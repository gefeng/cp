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
    bool canBeEqual(std::string s1, std::string s2) {
        for(int i = 0; i < 4; i++) {
            if(s1[i] == s2[i]) {
                continue;
            }
            
            if(i + 2 < 4 && s1[i + 2] == s2[i]) {
                std::swap(s1[i], s1[i + 2]);
            } else {
                return false;
            }
        }
        
        return true;
    }
};
