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
    int scoreOfString(std::string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans += std::abs(s[i] - s[i + 1]);
        }
        
        return ans;
    }
};
