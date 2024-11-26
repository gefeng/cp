#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

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
    int maxRemoval(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int ans = 0;
        
        std::sort(queries.begin(), queries.end());
        
        fenwick_tree ft(n);
        std::priority_queue<int> pq;
        
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j += 1;
            }
            
            nums[i] -= ft.query(i, n - 1);
            
            while(!pq.empty() && pq.top() >= i && nums[i] > 0) {
                nums[i] -= 1;
                ft.update(pq.top(), 1);
                pq.pop();
            }
            
            if(nums[i] > 0) {
                return -1;
            }
        }
        
        return pq.size();
    }
};
