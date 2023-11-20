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
    long long minimumSteps(std::string s) {
        int64_t ans = 0;
        int n = s.size();
        
        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] == '0') {
                ans += i - j;
                j += 1;
            }
        }
        
        return ans;
    }
};
