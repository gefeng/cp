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

struct segment_tree {
public:
    const int INF = 1e9;
    segment_tree(int n) : _n(n) {
        _m = left_most_bit(max(1, n - 1)) << 2;
        _h = _m / 2;
        _st.resize(_m, -INF);            
    }

    void propagate(int i) {
        _st[i] = max(_st[i * 2], _st[i * 2 + 1]);
    }

    void update(int i, int v) {
        _st[i + _h] = v;
        for(int j = (i + _h) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }
    
    int query(int l, int r) {
        int res = -INF;
        for(l += _h, r += _h; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                res = max(res, _st[l++]);
            }
            if(!(r & 1)) {
                res = max(res, _st[r--]);
            }
        }
        return res;
    }
    
    int left_most_bit(int x) {
        int res = 0;
        for(int i = 0; i < 30; i++) {
            if(x & (1 << i)) {
                res = 1 << i;
            }
        }     
        return res;
    }
private:
    int _n, _m, _h;
    vector<int> _st;
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        
        int m = 0;
        for(int x : nums) {
            m = max(m, x);
        }

        segment_tree rmq(m + 1);
        
        for(int i = 0; i < n; i++) {
            int l = max(0, nums[i] - k);
            int r = nums[i] - 1;
            int max_len = max(1, rmq.query(l, r) + 1);

            ans = max(ans, max_len);
            rmq.update(nums[i], max_len); 
        }

        return ans;
    }
};
