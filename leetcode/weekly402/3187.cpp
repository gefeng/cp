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
    fenwick_tree(int _n) : n(_n + 1), ft(n, 0) {
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
    std::vector<int> countOfPeaks(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<int> ans;
        int n = nums.size();
        int m = queries.size();
        
        fenwick_tree ft(n);
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
                ft.update(i, 1);
            }
        }
        
        for(int i = 0; i < m; i++) {
            int t = queries[i][0];
            if(t == 1) {
                int l = queries[i][1] + 1;
                int r = queries[i][2] - 1;
                if(r - l + 1 > 0) {
                    ans.push_back(ft.query(l, r));
                } else {
                    ans.push_back(0);
                }
            } else {
                int p = queries[i][1];
                int x = queries[i][2];
                
                if(p - 2 >= 0 && nums[p - 1] > nums[p - 2] && nums[p - 1] > nums[p]) {
                    ft.update(p - 1, -1);
                }
                if(p + 2 < n && nums[p + 1] > nums[p] && nums[p + 1] > nums[p + 2]) {
                    ft.update(p + 1, -1);
                }
                if(p - 1 >= 0 && p + 1 < n && nums[p] > nums[p - 1] && nums[p] > nums[p + 1]) {
                    ft.update(p, -1);
                }
                
                nums[p] = x;
                if(p - 2 >= 0 && nums[p - 1] > nums[p - 2] && nums[p - 1] > nums[p]) {
                    ft.update(p - 1, 1);
                }
                if(p + 2 < n && nums[p + 1] > nums[p] && nums[p + 1] > nums[p + 2]) {
                    ft.update(p + 1, 1);
                }
                if(p - 1 >= 0 && p + 1 < n && nums[p] > nums[p - 1] && nums[p] > nums[p + 1]) {
                    ft.update(p, 1);
                }
            }
        }
        
        return ans;
    }
};
