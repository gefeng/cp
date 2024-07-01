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
    int maxHeightOfTriangle(int red, int blue) {
        auto solve = [](int c1, int c2) {
            int res = 0;
            int row = 1;
            while(true) {
                if(row % 2 == 1) {
                    c1 -= row;
                    if(c1 < 0) {
                        break;
                    }
                } else {
                    c2 -= row;
                    if(c2 < 0) {
                        break;
                    }
                }
                res += 1;
                row += 1;
            }

            return res;
        };
        
        return std::max(solve(red, blue), solve(blue, red));
    }
};
