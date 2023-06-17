#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    struct fenwick_tree {
        int n;
        std::vector<int> ft;
        
        fenwick_tree(int _n) : n(_n + 1) {
            ft.resize(n, -1);
        }
        
        void update(int i, int v) {
            for(i += 1; i < n; i += i & -i) {
                ft[i] = std::max(ft[i], v);
            }
        }
        
        int query(int i) {
            int res = -1;
            for(i += 1; i > 0; i -= i & -i) {
                res = std::max(res, ft[i]);
            }
            return res;
        }
    };
    
    std::vector<int> maximumSumQueries(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<std::vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        std::vector<int> ans(m, 0);
        std::map<int, int> comp;
        
        for(int x : nums2) {
            comp[x] = 0;
        }
        
        for(auto& q : queries) {
            comp[q[1]] = 0;
        }
        
        int generator = comp.size() - 1;
        for(auto& [_, v] : comp) {
            v = generator--;
        }
        
        for(int i = 0; i < queries.size(); i++) {
            queries[i].emplace_back(i);
        }
        
        std::vector<std::pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.emplace_back(nums1[i], nums2[i]);
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[0] < b[0];
        };
        
        std::sort(queries.begin(), queries.end(), cmp);
        std::sort(v.begin(), v.end());
        
        fenwick_tree ft(comp.size());
        for(int i = m - 1, j = n - 1; i >= 0; i--) {
            std::vector<int>& q = queries[i];
            
            while(j >= 0 && v[j].first >= q[0]) {
                ft.update(comp[v[j].second], v[j].first + v[j].second);
                j -= 1;
            }
            
            ans[q[2]] = ft.query(comp[q[1]]);
        }
        
        return ans;
    }
};
