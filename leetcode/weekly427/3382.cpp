#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
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

using S = int;
    
S op(S a, S b) {
    return std::max(a, b);
}
    
S e() {
    return -1;
}

class Solution {
public:
    long long maxRectangleArea(std::vector<int>& xCoord, std::vector<int>& yCoord) {
        int n = xCoord.size();
        int64_t ans = -1;
        
        // compress
        int id = 0;
        std::map<int, int> m;
        std::map<int, int> rm;
        for(int x : xCoord) {
            m[x] = 0;
        }
        
        for(int y : yCoord) {
            m[y] = 0;
        }
        
        for(auto& [x, v] : m) {
            v = id++;
            rm[v] = x;
        }
        
        std::vector<std::pair<int, int>> a(n);
        
        for(int i = 0; i < n; i++) {
            a[i] = {m[xCoord[i]], m[yCoord[i]]};
        }
        //compress
        
        std::sort(a.begin(), a.end());
        
        std::map<int, int> y_to_x;
        std::map<int, std::set<int>> x_to_y;
        
        segtree<S, op, e> st(id);
        
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && a[i].first == a[j].first) {
                i += 1;
            }
            
            int len = i - j;
            if(len > 1) {
                for(int k = j; k < i; k++) {
                    auto [x, y] = a[k];
                    if(k != j) {
                        auto [x1, y1] = a[k - 1];
                        if(y_to_x.find(y) == y_to_x.end()) {
                            continue;
                        }
                        int x2 = y_to_x[y];
                        int max_x = st.prod(y1, y + 1);
                        if(max_x > x2) {
                            continue;
                        }
                        
                        auto it = x_to_y[x2].lower_bound(y);
                        if(it == x_to_y[x2].begin()) {  
                            continue;
                        }
                        
                        it--;
                        if(*it != y1) {
                            continue;
                        }
                        
                        ans = std::max(ans, int64_t(rm[x] - rm[x2]) * (rm[y] - rm[y1]));
                    }
                    if(k != i - 1) {
                        auto [x1, y1] = a[k + 1];
                        if(y_to_x.find(y) == y_to_x.end()) {
                            continue;
                        }
                        int x2 = y_to_x[y];
                        int max_x = st.prod(y, y1 + 1);
                        if(max_x > x2) {
                            continue;
                        }
                        
                        auto it = x_to_y[x2].upper_bound(y);
                        if(it == x_to_y[x2].end()) {
                            continue; 
                        }
                        
                        if(*it != y1) {
                            continue;
                        }
                        
                        ans = std::max(ans, int64_t(rm[x] - rm[x2]) * (rm[y1] - rm[y]));
                    }
                }
            }
            
            for(int k = j; k < i; k++) {
                auto [x, y] = a[k];
                y_to_x[y] = x;
                x_to_y[x].insert(y);
                st.set(y, x);
            }
        }
        return ans;
    }
};
