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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));        
        for(auto& q : queries) {
            int a = q[0];
            int b = q[1];
            int c = q[2];
            int d = q[3];
            
            diff[a][b] += 1;
            diff[c + 1][d + 1] += 1;
            diff[a][d + 1] -= 1;
            diff[c + 1][b] -= 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i) {
                    diff[i][j] += diff[i - 1][j];
                }        
                if(j) {
                    diff[i][j] += diff[i][j - 1];
                }
                if(i && j) {
                    diff[i][j] -= diff[i - 1][j - 1];
                }
                ans[i][j] = diff[i][j];
            }
        }
        
        return ans;
    }
};
