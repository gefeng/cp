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
public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), _parent_or_size(n, -1) {}

    int find(int a) {
        assert(a >= 0 && a < _n);
        if(_parent_or_size[a] < 0) return a;
        return find(_parent_or_size[a]); 
    }

    void unite(int a, int b) {
        assert(a >= 0 && a < _n);
        assert(b >= 0 && b < _n);
        int x = find(a), y = find(b);
        if(x == y) return;
        if(-_parent_or_size[x] < -_parent_or_size[y]) std::swap(x, y);
        _parent_or_size[x] += _parent_or_size[y];
        _parent_or_size[y] = x;
    }

    bool same(int a, int b) {
        assert(a >= 0 && a < _n);
        assert(b >= 0 && b < _n);
        return find(a) == find(b);
    }

    int size(int a) {
        assert(a >= 0 && a < _n);
        return -_parent_or_size[find(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(_n);
        std::vector<int> group_size(_n, 0);
        for(int i = 0; i < _n; i++) {
            group_size[find(i)]++;
        }
        for(int i = 0; i < _n; i++) {
            res[i].reserve(group_size[i]);
        }
        for(int i = 0; i < _n; i++) {
            res[find(i)].push_back(i);
        }
        // erase-remove idiom: remove all empty vector in linear time
        res.erase(
            std::remove_if(res.begin(), res.end(), 
                           [](const std::vector<int>& v) { return v.empty(); }), 
            res.end());
        return res;
    }

private:
    int _n;
    // if root then -1 * component_size
    // else parent
    std::vector<int> _parent_or_size;
};

class Solution {
public:
    int countComponents(std::vector<int>& nums, int threshold) {
        int n = nums.size();
        int m = threshold;
        dsu uf(m + 1);
        
        std::vector<int> seen(m + 1, 0);
        std::set<int> s;
        int ans = 0;
        for(int x : nums) {
            if(x <= m) {
                seen[x] = 1;
            } else {
                if(s.find(x) != s.end()) {
                    continue;
                }
                ans += 1;
                s.insert(x);
            }
        }
        
        for(int i = 1; i <= m; i++) {
            if(!seen[i]) {
                continue;
            }
            for(int j = i; j <= m; j += i) {
                uf.unite(i, j);
            }
        }
    
        std::set<int> head;
        for(int i = 0; i <= m; i++) {
            if(seen[i]) {
                int p = uf.find(i);
                head.insert(p);
            }
        }
        ans += head.size();
        return ans;
    }
};
