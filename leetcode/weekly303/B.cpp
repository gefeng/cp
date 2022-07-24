#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bool ok = true;
                for(int k = 0; k < n; k++) {
                    if(grid[i][k] != grid[k][j]) {
                        ok = false;
                        break;
                    }
                } 

                if(ok) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
