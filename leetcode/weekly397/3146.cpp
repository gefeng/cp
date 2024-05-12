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
    int findPermutationDifference(std::string s, std::string t) {
        int ans = 0;
        
        std::array<int, 26> pos{};
        int n = s.size();
        for(int i = 0; i < n; i++) {
            pos[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < n; i++) {
            ans += std::abs(pos[t[i] - 'a'] - i);
        }
        
        return ans;
    }
};
