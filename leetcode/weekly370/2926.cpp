#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

struct seg_tree {
    int N, M, H;
    std::vector<int64_t> st;

    seg_tree(int n) {
        build(n);
    }

    seg_tree(std::vector<int64_t>& v) {
        build(v);
    }

    int highest_one_bit(unsigned int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1); 
    }

    void propagate(int i) {
        st[i] = std::max(st[2 * i], st[2 * i + 1]);
    }

    void build(int n) {
        N = n;
        M = highest_one_bit(std::max(1, N - 1)) << 2; 
        H = M / 2;
        st.resize(M, 0);
    }

    void build(std::vector<int64_t>& v) {
        build(v.size());
        
        for(int i = 0; i < N; i++) {
            st[i + H] = v[i];
        }
        
        for(int i = H - 1; i > 0; i--) {
            propagate(i);
        }
    }

    void set(int i, int64_t v) {
        st[i + H] = v;
        for(int j = (i + H) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }

    int64_t query(int l, int r) {
        int64_t max_v = 0;
        for(l += H, r += H; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                max_v = std::max(max_v, st[l++]);
            }
            if(!(r & 1)) {
                max_v = std::max(max_v, st[r--]);
            }
        }
        return max_v;
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = -INF;
        seg_tree st(n);
        std::set<int> s;
        
        std::vector<std::pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
        }
        
        std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) { 
            if(x.first - x.second == y.first - y.second) {
                return x.second < y.second;
            }
            return x.first - x.second < y.first - y.second; 
        });
        
        
        
        for(int i = 0; i < n; i++) {
            if(a[i].first <= 0) {
                ans = std::max(ans, (int64_t)a[i].first);
                continue;
            }

            auto it = s.upper_bound(a[i].second);
            if(s.empty() || it == s.begin()) {
                ans = std::max(ans, (int64_t)nums[a[i].second]);
                st.set(a[i].second, nums[a[i].second]);
            } else {
                it--;
                int64_t max_v = st.query(0, a[i].second) + nums[a[i].second];
                ans = std::max(ans, max_v);
                st.set(a[i].second, max_v);
            }
            s.insert(a[i].second);
        }
        
        return ans;
    }
};
