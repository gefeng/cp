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
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        for(int i = 0; i < m; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            set<int> s;
            while(x != 1) {
                s.insert(x);
                x /= 2;
            }
            int lca = 1;
            while(y != 1) {
                if(s.find(y) != s.end()) {
                    lca = y;
                    break;
                }
                y /= 2;
            }
            
            int l = 0;
            int r = 0;
            x = queries[i][0];
            y = queries[i][1];
            
            while(x != lca) {
                x /= 2;
                l += 1;
            }
            while(y != lca) {
                y /= 2;
                r += 1;
            }
            ans[i] = l + r + 1;
        }
        
        return ans;
    }
};
