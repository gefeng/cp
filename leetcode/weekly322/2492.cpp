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

const int INF = 2e9;

struct dsu {
    int n;
    vector<int> p;
    vector<int> w;
    dsu(int n)  : n(n) {
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
    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        dsu uf(n);
        for(auto& e : roads) {
            uf.unite(e[0] - 1, e[1] - 1);
        }
        
        int ans = INF;
        for(auto& e : roads) {
            if(uf.same(0, e[0] - 1) || uf.same(0, e[1] - 1)) {
                ans = min(e[2], ans);
            }
        }
        
        return ans;
    }
};
