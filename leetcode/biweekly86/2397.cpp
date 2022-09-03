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

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 1; i < (1 << n); i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if((1 << j) & i) {
                    cnt++;
                }
            }
            
            if(cnt == cols) {
                int cover = 0;
                for(int r = 0; r < m; r++) {
                    bool ok = true;
                    for(int c = 0; c < n; c++) {
                        if(mat[r][c] == 1 && ((1 << c) & i) == 0) {
                            ok = false;
                            break;
                        }
                    }
                    
                    cover += ok ? 1 : 0;
                }
                ans = max(ans, cover);
            }
        }
        
        return ans;
    }
};
