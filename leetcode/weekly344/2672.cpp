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
    std::vector<int> colorTheArray(int n, std::vector<std::vector<int>>& queries) {
        int m = queries.size();
        
        std::vector<int> ans(m, 0);
        std::vector<int> color(n, 0);
        
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int j = queries[i][0];
            int c = queries[i][1];
            
            if(c == color[j]) {
                ans[i] = cnt;
                continue;
            }
            
            if(j > 0 && color[j - 1] != 0 && color[j - 1] == color[j]) {
                cnt -= 1;
            }
            if(j > 0 && color[j - 1] != color[j] && c == color[j - 1]) {
                cnt += 1;
            }
            if(j < n - 1 && color[j + 1] != 0 && color[j + 1] == color[j]) {
                cnt -= 1;
            }
            if(j < n - 1 && color[j + 1] != color[j] && c == color[j + 1]) {
                cnt += 1;
            }
            ans[i] = cnt;
            color[j] = c;
        }
        
        return ans;
    }
};
