#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    dsu(int n) : n(n), p(n, -1), w(n, 1) {}
    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    } 
    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }
        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    std::vector<int> minimumCost(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& query) {
        dsu uf(n);
        for(auto& e : edges) {
            uf.unite(e[0], e[1]);
        }
        
        std::vector<int> cost(n, -1);
        for(auto& e : edges) {
            int p = uf.find(e[0]);
            cost[p] = cost[p] == -1 ? e[2] : (cost[p] & e[2]);
        }
        
        int size = query.size();
        std::vector<int> ans(size, -1);
        for(int i = 0; i < size; i++) {
            int u = query[i][0];
            int v = query[i][1];
            
            if(!uf.same(u, v)) {
                continue;
            }
            
            ans[i] = u == v ? 0 : cost[uf.find(u)];
        }
        
        return ans;
    }
};
