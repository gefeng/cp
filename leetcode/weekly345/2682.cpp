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
    std::vector<int> circularGameLosers(int n, int k) {
        std::vector<int> ans;
        std::vector<int> vis(n, false);
        
        int x = 0;
        int t = 1;
        while(!vis[x]) {
            vis[x] = true;
            x = (x + t * k) % n;
            t += 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
