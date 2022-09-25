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

struct dsu {
public:
    dsu(int n) : _n(n) {
        _p.resize(n, -1);
        _w.resize(n, 1);
    }
    int find(int i) {
        if(_p[i] < 0) return i;
        return _p[i] = find(_p[i]);
    }
    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) return;
        if(_w[x] >= _w[y]) {
            _p[y] = x;
            _w[x] += _w[y];
        } else {
            _p[x] = y;
            _w[y] += _w[x];
        }
    }
private:
    int _n;
    vector<int> _p;
    vector<int> _w;
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        map<int, vector<int>> v_n;
        for(int i = 0; i < n; i++) {
            v_n[vals[i]].push_back(i);
        }
        
        map<int, vector<pair<int, int>>> g;
        for(auto& e : edges) {
            g[max(vals[e[0]], vals[e[1]])].emplace_back(e[0], e[1]);
        }
        
        dsu uf(n);
        int ans = 0;
        for(auto& [k, v] : v_n) {
            for(auto& e : g[k]) {
                uf.unite(e.first, e.second);
            }
            
            unordered_map<int, int> cnt;
            for(int x : v) {
                ans += ++cnt[uf.find(x)];
            }
        }
        
        return ans;
    }
};
