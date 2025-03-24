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
    dsu(int _n) : n(_n), p(n, -1), w(n, 1) {
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
    int numberOfComponents(std::vector<std::vector<int>>& properties, int k) {
        int n = properties.size();
        int ans = 0;
        dsu uf(n);
        
        auto count = [&](int i, int j) {
            std::unordered_set<int> seen;
            std::unordered_set<int> common;
            int cnt = 0;
            for(int x : properties[i]) {
                seen.insert(x);
            }
            for(int y : properties[j]) {
                if(seen.find(y) != seen.end()) {
                    common.insert(y);
                }
            }
            return common.size();
        };
        
        std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            std::unordered_set<int> seen;
            for(int x : properties[i]) {
                seen.insert(x);
            }
            for(int j = i + 1; j < n; j++) {
                std::unordered_set<int> common;
                for(int y : properties[j]) {
                    if(seen.find(y) != seen.end()) {
                        common.insert(y);
                    }
                }
                a[i][j] = common.size();
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i][j] >= k) {
                    uf.unite(i, j);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(uf.find(i) == i) {
                ans += 1;
            }
        }
        return ans;
    }
};
