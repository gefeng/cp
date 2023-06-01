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

constexpr int MAX = 1e5;

class Solution {
public:
    bool canTraverseAllPairs(std::vector<int>& nums) {
        int n = nums.size();
        dsu uf(MAX + 1);
        
        if(n == 1) {
            return true;
        }
        
        for(int x : nums) {
            if(x == 1) {
                return false;
            }
            
            int y = x;
            for(int f = 2; f * f <= y; f++) {
                if(y % f == 0) {
                    uf.unite(f, x);
                }
                while(y % f == 0) {
                    y /= f;
                }
            }
            if(y > 1) {
                uf.unite(y, x);
            }
        }
        
        std::set<int> head;
        for(int x : nums) {
            head.insert(uf.find(x));
        }
        
        return head.size() == 1;
    }
};
