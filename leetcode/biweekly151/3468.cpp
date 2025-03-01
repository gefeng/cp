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
    int countArrays(std::vector<int>& original, std::vector<std::vector<int>>& bounds) {
        int n = original.size();
        int l = bounds[0][0];
        int r = bounds[0][1];
        
        auto overlap = [](int l, int r, int x, int y) {
            if(l > x) {
                std::swap(l, x);
                std::swap(r, y);
            }
            return x >= l && x <= r;
        };
        
        for(int i = 1; i < n; i++) {
            int d = original[i] - original[i - 1];
            
            l += d;
            r += d;
            
            if(overlap(l, r, bounds[i][0], bounds[i][1])) {
                l = std::max(l, bounds[i][0]);
                r = std::min(r, bounds[i][1]);
            } else {
                return 0;
            }
        }
        
        return r - l + 1;
    }
};
