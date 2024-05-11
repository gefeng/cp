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
    int maxPointsInsideSquare(std::vector<std::vector<int>>& points, std::string s) {
        int n = points.size();
        
        std::vector<std::vector<int>> a(26);
        for(int i = 0; i < n; i++) {
            a[s[i] - 'a'].push_back(std::max(std::abs(points[i][0]), std::abs(points[i][1])));
        }

        int ans = 0;
        int min_len = INF;
        for(int i = 0; i < 26; i++) {
            std::sort(a[i].begin(), a[i].end());

            if(a[i].size() > 1) {
                min_len = std::min(min_len, a[i][1] - 1);
            }
        }

        for(int i = 0; i < 26; i++) {
            if(!a[i].empty() && a[i][0] <= min_len) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
