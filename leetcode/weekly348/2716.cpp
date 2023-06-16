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
    int minimizedStringLength(std::string s) {
        std::array<int, 26> seen = {};
        
        for(char c : s) {
            seen[c - 'a'] = 1;
        }
        
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += seen[i];
        }
        
        return ans;
    }
};
