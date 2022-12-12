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

using namespace std;

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        
        auto encode = [&](const int a, const int b) {
            return a * n + b;
        };
        
        unordered_map<int, vector<pair<int, int>>> g;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int d = 0; d < 4; d++) {
                    int nr = i + DR[d];
                    int nc = j + DC[d];
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n) {
                        g[encode(i, j)].emplace_back(encode(nr, nc), max(grid[i][j], grid[nr][nc]));
                    }
                }
            }
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> cost;
        
        pq.emplace(0, grid[0][0]);
        cost[0] = grid[0][0];
        while(!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            
            int v = cur.first;
            int c = cur.second;
            
            if(cost[v] != c) {
                continue;
            }
            
            for(auto& nei : g[v]) {
                int nv = nei.first;
                int nc = max(c, nei.second);
                
                if(cost.find(nv) == cost.end() || cost[nv] > nc) {
                    cost[nv] = nc;
                    pq.emplace(nv, nc);
                }
            }
        }
        
        int MAX = 1e6;
        vector<int> cnt(MAX + 5, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int c = cost[encode(i, j)];
                cnt[c + 1] += 1;
            }
        }
        
        for(int i = 1; i <= MAX; i++) {
            cnt[i] += cnt[i - 1];
        }
        
        int k = queries.size();
        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            ans[i] = cnt[queries[i]];
        }
        
        return ans;
    }
};
