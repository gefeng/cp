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
    int findChampion(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int max_v = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    cnt += 1;
                }
            }
            if(max_v < cnt) {
                max_v = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
