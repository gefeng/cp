#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <functional>

constexpr int64_t INF = int64_t(2e18);

unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2; return x;
}

int countr_zero(unsigned int n) {
    return __builtin_ctz(n);
}

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = bit_ceil((unsigned int)(_n));
        log = countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct S {
    int64_t sum = 0;
    int64_t max_sum = -INF;
    int64_t max_prefix = -INF;
    int64_t max_suffix = -INF;
    S() {}
    S(int64_t _v) : sum(_v), max_sum(_v), max_prefix(_v), max_suffix(_v) {}
};
    
S op(S a, S b) {
    if(b.max_sum == -INF) {
        return a;
    }
    if(a.max_sum == -INF) {
        return b;
    }
    
    S c;
    c.max_prefix = std::max(a.max_prefix, a.sum + b.max_prefix);
    c.max_suffix = std::max(b.max_suffix, b.sum + a.max_suffix);
    c.sum = a.sum + b.sum;
    
    c.max_sum = std::max(a.max_sum, b.max_sum);
    c.max_sum = std::max(c.max_sum, c.max_prefix);
    c.max_sum = std::max(c.max_sum, c.max_suffix);
    c.max_sum = std::max(c.max_sum, a.max_suffix + b.max_prefix);
    return c;
}
    
S e() {
    return S();
}

class Solution {
public:
    long long maxSubarraySum(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = -INF;
        std::map<int, std::vector<int>> pos;
        
        int64_t sum = 0;
        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
            sum += nums[i];
        }
        
        segtree<S, op, e> st(n);
        for(int i = 0; i < n; i++) {
            st.set(i, S(nums[i]));
        }
        
        ans = st.all_prod().max_sum;
        
        for(const auto& [v, a] : pos) {
            std::vector<std::pair<int, int>> segs;
            int pre = -1;
            for(int p : a) {
                if(pre == -1) {
                    if(p != 0) {
                        segs.emplace_back(0, p - 1);
                    }
                } else {
                    if(pre + 1 <= p - 1) {
                        segs.emplace_back(pre + 1, p - 1);
                    }
                }
                pre = p;
            }
            
            if(pre != n - 1) {
                segs.emplace_back(pre + 1, n - 1);
            }
            
            sum = 0;
            
            for(auto [l, r] : segs) {
                
                S x = st.prod(l, r + 1);
                ans = std::max(ans, x.max_sum);
                ans = std::max(ans, sum + x.max_prefix);
                
                sum = std::max(x.max_suffix, x.sum + sum);
                
                ans = std::max(ans, sum);
                sum = std::max(int64_t(0), sum);
            }
        }
        
        return ans;
    }
};
