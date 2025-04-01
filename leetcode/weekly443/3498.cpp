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
    int reverseDegree(std::string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += (26 - s[i] + 'a') * (i + 1);
        }
        
        return ans;
    }
};
