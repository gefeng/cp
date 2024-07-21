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
    bool doesAliceWin(std::string s) {
        std::string v = "aeiou";
        for(char c : s) {
            if(v.find(c) != std::string::npos) {
                return true;
            }
        }
        
        return false;
    }
};
