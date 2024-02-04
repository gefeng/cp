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
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && points[j][0] >= points[i][0] && points[j][1] <= points[i][1]) { 
                    bool ok = true;
                    for(int k = 0; k < n; k++) {
                        if(i != k && j != k) {
                            int l = std::min(points[i][0], points[j][0]);
                            int r = std::max(points[i][0], points[j][0]);
                            int u = std::max(points[i][1], points[j][1]);
                            int d = std::min(points[i][1], points[j][1]);

                            if(points[k][0] >= l && points[k][0] <= r && points[k][1] >= d && points[k][1] <= u) {
                                ok = false;
                                break;
                            }
                        }
                    }

                    if(ok) {
                        ans += 1;
                    }
                }
            }
        }
        
        return ans;
    }
};
