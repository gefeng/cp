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
    int countSeniors(std::vector<std::string>& details) {
        int ans = 0;
        
        for(std::string s : details) {
            int age = (s[11] - '0') * 10 + (s[12] - '0');
            ans += age > 60 ? 1 : 0;
        }
        
        return ans;
    }
};
