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
    bool canMakeSquare(std::vector<std::vector<char>>& grid) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int cnt_b = 0;
                int cnt_w = 0;
                for(int r = 0; r < 2; r++) {
                    for(int c = 0; c < 2; c++) {
                        if(grid[i + r][j + c] == 'B') {
                            cnt_b += 1;
                        } else {
                            cnt_w += 1;
                        }
                    }
                }
                if(cnt_b <= 1 || cnt_w <= 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
