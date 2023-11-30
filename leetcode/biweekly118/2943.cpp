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
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
        int size1 = hBars.size();
        int size2 = vBars.size();
        
        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());
        
        int ans = 0;
        int max_h = 1;
        int max_w = 1;
        for(int i = 0; i < size1; i++) {
            int j = i;
            while(i + 1 < size1 && hBars[i + 1] - hBars[i] == 1) {
                i += 1;
            }
            max_h = std::max(max_h, i - j + 2);
        }

        for(int i = 0; i < size2; i++) {
            int j = i;
            while(i + 1 < size2 && vBars[i + 1] - vBars[i] == 1) {
                i += 1;
            }
            max_w = std::max(max_w, i - j + 2);
            ans = std::max(ans, std::min(max_h, max_w) * std::min(max_h, max_w));
        }
        
        return ans;
    }
};
