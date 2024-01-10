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
    int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
        int ans = 0;
        int max_d = 0;
        for(auto& v : dimensions) {
            int d = v[0] * v[0] + v[1] * v[1];
            if(d > max_d) {
                max_d = d;
                ans = v[0] * v[1];
            } else if(d == max_d) {
                ans = std::max(ans, v[0] * v[1]);
            }
        }
        
        return ans;
    }
};
