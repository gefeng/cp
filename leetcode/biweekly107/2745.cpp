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
    int longestString(int x, int y, int z) {        
        int min_v = std::min(x, std::min(y, z));
        int ans = min_v * 3;
        
        x -= min_v;
        y -= min_v;
        z -= min_v;
        
        if(z == 0) {
            if(x == y) {
                ans += 2 * std::min(x, y);
            } else {
                ans += 2 * std::min(x, y) + 1;
            }
        } else {
            if(x != 0 || y != 0) {
                ans += 1 + z;
            } else {
                ans += z;
            }
        }
        
        return ans * 2;
    }
};
