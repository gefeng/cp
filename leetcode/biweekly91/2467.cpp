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

const int INF = (int)2e9;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        unordered_map<int, int> b;
        dfs_1(g, 0, bob, 0, b);
        
        return dfs_2(g, amount, b, bob, 0, -1, 0);
    }
    
    bool dfs_1(vector<vector<int>>& g, int cur, int t, int d, unordered_map<int, int>& b) {
        b[cur] = d;
        
        if(cur == t) {
            return true;
        }
        
        for(int nei : g[cur]) {
            if(b.find(nei) == b.end()) {
                if(dfs_1(g, nei, t, d + 1, b)) {
                    return true;
                }
            }
        }
        
        b.erase(cur);
        return false;
    }
    
    int dfs_2(vector<vector<int>>& g, vector<int>& amount, unordered_map<int, int>& b, int bob, int cur, int pre, int d) {
        int res = 0;
        if(b.find(cur) != b.end()) {
            int v = b[bob];
            if(v - d == d) {
                res = amount[cur] / 2;
            } else if(v - d < d){
                res = 0;
            } else {
                res = amount[cur];
            }
        } else {
            res = amount[cur];
        }
        
        int max_v = -INF;
        for(int nei : g[cur]) {
            if(nei != pre) {
                max_v = max(max_v, dfs_2(g, amount, b, bob, nei, cur, d + 1));
            }
        }
        
        if(max_v != -INF) {
            res += max_v;
        }
            
        return res;
    }
};
