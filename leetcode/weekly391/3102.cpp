#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    int minimumDistance(std::vector<std::vector<int>>& points) {
        int n = points.size();
        std::vector<int> a(n);
        std::vector<int> b(n);
        for(int i = 0; i < n; i++) {
            a[i] = points[i][0] + points[i][1];
            b[i] = points[i][0] - points[i][1];
        }
        
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        
        /*d = |x1 - x2| + |y1 - y2|
          = (x1 - x2) + (y1 - y2) = (x1 + y1) - (x2 + y2)
          = (x1 - x2) - (y1 - y2) = (x1 - y1) - (x2 - y2) 
          = (x2 - x1) + (y1 - y2) = (x2 - y2) - (x1 - y1)
          = (x2 - x1) - (y1 - y2) = (x2 + y2) - (x1 + y2)*/
        
        int ans = INF;
        for(int i = 0; i < n; i++) {
            int x = points[i][0] + points[i][1];
            int y = points[i][0] - points[i][1];
            
            // max(a.back() - a.front(), b.back() - b.front());
            int max_v = -INF;
            if(x == a.back()) {
                max_v = a[n - 2] - a.front();
            } else if(x == a.front()) {
                max_v = a.back() - a[1];
            } else {
                max_v = a.back() - a.front();
            }
            
            if(y == b.back()) {
                max_v = std::max(max_v, b[n - 2] - b.front());
            } else if(y == b.front()) {
                max_v = std::max(max_v, b.back() - b[1]);
            } else {
                max_v = std::max(max_v, b.back() - b.front());
            }
            
            ans = std::min(ans, max_v);
        }
        
        return ans;
    }
};
