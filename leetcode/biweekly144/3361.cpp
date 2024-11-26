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
    long long shiftDistance(std::string s, std::string t, std::vector<int>& nextCost, std::vector<int>& previousCost) {
        int n = s.size();
        
        int64_t ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) {
                continue;
            }
            
            int c_1 = s[i] - 'a';
            int c_2 = t[i] - 'a';
            int64_t cost_1 = 0;
            int64_t cost_2 = 0;
            while(c_1 != c_2) {
                cost_1 += nextCost[c_1];
                c_1 += 1;
                c_1 %= 26;
            }
            
            c_1 = s[i] - 'a';
            while(c_1 != c_2) {
                cost_2 += previousCost[c_1];
                c_1 -= 1;
                c_1 += 26;
                c_1 %= 26;
            }

            ans += std::min(cost_1, cost_2);
        }
        
        return ans;
    }
};
