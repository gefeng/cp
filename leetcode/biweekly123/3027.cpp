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
        int n = points.size();
        int ans = 0;
        
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        for(int i = 0; i < n; i++) {
            std::set<int> s;
            for(int j = i + 1; j < n; j++) {
                if(points[j][1] <= points[i][1]) {
                    auto it = s.upper_bound(points[i][1]);
                    if(it != s.begin()) {
                        it--;
                        if(*it < points[j][1]) {
                            ans += 1;
                        }
                    } else {
                        ans += 1;
                    }
                }
                s.insert(points[j][1]);
            }
        }
        
        return ans;
    }
};
