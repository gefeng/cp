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
    
    dsu(int _n) : n(_n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }
    
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
};

class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        int ans = 0;
        dsu uf(n);
    
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            uf.unite(u, v);
        }
        
        std::vector<int> cnt_v(n, 0);
        std::vector<int> cnt_e(n, 0);
        
        for(int i = 0; i < n; i++) {
            cnt_v[uf.find(i)] += 1;
        }
        
        for(auto& e : edges) {
            cnt_e[uf.find(e[0])] += 1;
        }
        
        for(int i = 0; i < n; i++) {
            int p = uf.find(i);
            if(p == i && cnt_e[i] == cnt_v[i] * (cnt_v[i] - 1) / 2) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
