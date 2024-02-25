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
    long long largestSquareArea(std::vector<std::vector<int>>& bottomLeft, std::vector<std::vector<int>>& topRight) {
        int64_t ans = 0;
        int n = bottomLeft.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int64_t x1 = topRight[i][0] - bottomLeft[i][0];
                int64_t y1 = topRight[i][1] - bottomLeft[i][1];
                int64_t x2 = topRight[j][0] - bottomLeft[j][0];
                int64_t y2 = topRight[j][1] - bottomLeft[j][1];
                
                int64_t x = std::max(topRight[i][0], topRight[j][0]) - std::min(bottomLeft[i][0], bottomLeft[j][0]);
                int64_t y = std::max(topRight[i][1], topRight[j][1]) - std::min(bottomLeft[i][1], bottomLeft[j][1]);
                
                if(x1 + x2 > x && y1 + y2 > y) {
                    int64_t d = std::min(x1 + x2 - x, y1 + y2 - y);
                    ans = std::max(ans, d * d);
                }
            }
        }
        
        return ans;
    }
};
