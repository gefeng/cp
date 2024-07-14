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
    std::string getSmallestString(std::string s) {
        std::string ans = s;
        int n = s.size();
        
        for(int i = 1; i < n; i++) {
            if(s[i] % 2 == s[i - 1] % 2) {
                std::swap(s[i], s[i - 1]);
                ans = std::min(ans, s);
                std::swap(s[i], s[i - 1]);
            }    
        }
        
        return ans;
    }
};
