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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<bool> r(n, 0);
        for(int x : restricted) {
            r[x] = 1;
        }
        
        return dfs(g, r, 0, -1);
    }
    
    int dfs(vector<vector<int>>& g, vector<bool>& r, int cur, int p) {
        int cnt = 1;
        
        for(int nei : g[cur]) {
            if(nei != p && !r[nei]) {
                cnt += dfs(g, r, nei, cur);
            }
        }
        
        return cnt;
    }
};
