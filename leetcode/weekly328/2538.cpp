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
    LL ans = 0LL;
    vector<LL> save1;
    vector<LL> save2;
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> G(n);
        save1.resize(n, 0LL);
        save2.resize(n, 0LL);
        
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        dfs1(G, price, 0, -1);
        dfs2(G, price, 0, -1);
        
        return ans;
    }
    
    LL dfs1(vector<vector<int>>& G, vector<int>& price, int v, int p) {
        LL max1 = 0LL;
        LL max2 = 0LL;
        for(int nei : G[v]) {
            if(nei != p) {
                LL res = dfs1(G, price, nei, v);
                if(res > max1) {
                    max2 = max1;
                    max1 = res;
                } else if(res > max2) {
                    max2 = res;
                }
            }
        }
        save1[v] = max1 + price[v];
        save2[v] = max2 + price[v];
        
        return save1[v];
    }
    
    void dfs2(vector<vector<int>>& G, vector<int>& price, int v, int p) {
        if(p == -1) {
            ans = max(ans, save1[v] - price[v]);
        } else {
            LL best_p = 0LL;
            if(save1[p] == save1[v] + price[p]) {
                best_p = save2[p];
            } else {
                best_p = save1[p];
            }
            
            ans = max(ans, max(best_p, save1[v] - price[v]));
            
            if(best_p + price[v] > save1[v]) {
                save2[v] = save1[v];
                save1[v] = best_p + price[v];
            } else if(best_p + price[v] > save2[v]) {
                save2[v] = best_p + price[v];
            }
        }
        
        for(int nei : G[v]) {
            if(nei != p) {
                dfs2(G, price, nei, v);
            }
        }
    }
};
