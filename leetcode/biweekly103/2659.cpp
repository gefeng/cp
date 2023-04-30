#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

struct fenwick_tree {
    int n;
    std::vector<int> ft;
    
    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }
    
    void update(int i, int v) {
        for(i += 1; i < n; i += i & -i) {
            ft[i] += v;
        }
    }
    
    int query(int i) {
        int res = 0;
        for(i += 1; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }
    
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long countOperationsToEmptyArray(std::vector<int>& nums) {
        LL ans = 0LL;        
        int n = nums.size();
        
        if(n == 1) {
            return 1;
        }
        
        std::vector<std::pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i].first = nums[i];
            v[i].second = i;
        }
        
        std::sort(v.begin(), v.end());
        
        fenwick_tree ft(n);
        int cur_len = n;
        
        ans = v[0].second + 1;
        
        for(int i = 1; i < n; i++) {
            int p1 = v[i - 1].second;
            int p2 = v[i].second;
            
            int cnt = 0;
            if(p1 < p2) {
                cnt = ft.query(p1, p2);
            } else {
                cnt = ft.query(0, p2) + ft.query(p1, n - 1);
            }
            
            int d = (p2 - p1 + n) % n - cnt;
            ans += d;
            
            ft.update(p1, 1);
        }
        
        return ans;
    }
};
