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
    int minChanges(std::string s) {
        int ans = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i += 2) {
            if(s[i] != s[i + 1]) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
