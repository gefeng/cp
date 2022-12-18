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
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<set<int>> g(n);
        for(auto& e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            g[u].insert(v);
            g[v].insert(u);
            deg[u] += 1;
            deg[v] += 1;
        }
        
        vector<int> odd;
        for(int i = 0; i < n; i++) {
            if(deg[i] & 1) {
                odd.push_back(i);
            }
        }
        
        int m = odd.size();
        if(m == 0) {
            return true;
        }
        if(m > 4 || m == 1) {
            return false;
        }
        
        if(m == 2) {
            return check_two(g, odd[0], odd[1]);
        } else {
            for(int x : odd) {
                for(int y : odd) {
                    if(x != y && g[x].find(y) == g[x].end()) {
                        for(int i : odd) {
                            for(int j : odd) {
                                if(i != j && i != x && i != y && j != x && j != y && g[i].find(j) == g[i].end()) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return false;
    }
    
    bool check_two(vector<set<int>>& g, int x, int y) {
        int n = g.size();
        if(g[x].find(y) == g[x].end()) {
            return true;
        } else {
            for(int i = 0; i < n; i++) {
                if(i != x && i != y && g[i].find(x) == g[i].end() && g[i].find(y) == g[i].end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
