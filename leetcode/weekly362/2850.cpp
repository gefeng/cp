#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    int minimumMoves(std::vector<std::vector<int>>& grid) {
        std::vector<std::vector<int>> g(9);
        g[0] = {1, 3};
        g[1] = {0, 2, 4};
        g[2] = {1, 5};
        g[3] = {0, 4, 6};
        g[4] = {1, 3, 5, 7};
        g[5] = {2, 4, 8};
        g[6] = {3, 7};
        g[7] = {4, 6, 8};
        g[8] = {5, 7};
        
        std::string s = "";
        std::string t(9, '1');
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                s.push_back((char)(grid[i][j] + '0'));
            }
        }

        std::queue<std::string> q;
        std::unordered_set<std::string> vis;
        q.push(s);
        vis.insert(s);
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                std::string cur = q.front();
                q.pop();
                
                if(cur == t) {
                    return ans;
                }
                
                for(int i = 0; i < 9; i++) {
                    if(cur[i] != '0' && cur[i] != '1') {
                        for(int j : g[i]) {
                            cur[i] -= 1;
                            cur[j] += 1;
                            if(vis.find(cur) == vis.end()) {
                                vis.insert(cur);
                                q.push(cur);
                            }
                            cur[i] += 1;
                            cur[j] -= 1;
                        }
                    }
                }
            }
            ans += 1;
        }
        return -1;
    }
};
