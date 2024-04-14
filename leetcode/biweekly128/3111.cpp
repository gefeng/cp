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
    int minRectanglesToCoverPoints(std::vector<std::vector<int>>& points, int w) {
        int ans = 0;
        int n = points.size();
        
        std::sort(points.begin(), points.end());
        
        int l = -1;
        for(int i = 0; i < n; i++) {
            int x = points[i][0];
            if(l == -1 || x - l > w) {
                l = x;
                ans += 1;
            } 
        }
        
        return ans;
    }
};
