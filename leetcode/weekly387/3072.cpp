#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

struct fenwick_tree {
    int n;
    std::vector<int> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
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
    std::vector<int> resultArray(std::vector<int>& nums) {
        std::vector<int> ans;
        std::vector<int> a;
        std::vector<int> b;
        int n = nums.size();
        
        std::map<int, int> m1;
        std::map<int, int> m2;
        int id = 0;
        for(int x : nums) {
            m1[x] = 0;
        }
        for(auto& [x, v] : m1) {
            m2[id] = x;
            v = id;
            id++;
        }
        
        for(int i = 0; i < n; i++) {
            nums[i] = m1[nums[i]];
        }
        
        fenwick_tree ft1(n + 10);
        fenwick_tree ft2(n + 10);
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        ft1.update(nums[0], 1);
        ft2.update(nums[1], 1);
        for(int i = 2; i < n; i++) {
            int cnt1 = ft1.query(nums[i] + 1, n + 5);
            int cnt2 = ft2.query(nums[i] + 1, n + 5);
            if(cnt1 > cnt2) {
                a.push_back(nums[i]);
                ft1.update(nums[i], 1);
            } else if(cnt1 < cnt2) {
                b.push_back(nums[i]);
                ft2.update(nums[i], 1);
            } else {
                if(a.size() <= b.size()) {
                    a.push_back(nums[i]);
                    ft1.update(nums[i], 1);
                } else {
                    b.push_back(nums[i]);
                    ft2.update(nums[i], 1);
                }
            }
        }
        
        for(int x : a) {
            ans.push_back(m2[x]);
        }
        for(int x : b) {
            ans.push_back(m2[x]);
        }
        return ans;
    }
};
