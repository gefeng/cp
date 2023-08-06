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
    std::string finalString(std::string s) {
        std::string ans = "";
        
        for(char c : s) {
            if(c == 'i') {
                std::reverse(ans.begin(), ans.end());
            } else {
                ans.push_back(c);
            }
        }
        
        return ans;
    }  
};
