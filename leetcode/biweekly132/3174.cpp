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
    std::string clearDigits(std::string s) {
        std::string ans = "";
        
        for(char c : s) {
            if(c >= '0' && c <= '9') {
                if(!ans.empty()) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};
