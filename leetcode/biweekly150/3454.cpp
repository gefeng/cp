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

unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}

int countr_zero(unsigned int n) {
    return __builtin_ctz(n);
}

#if __cplusplus >= 201703L

template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct lazy_segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
    static_assert(
        std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
        "mapping must work as F(F, S)");
    static_assert(
        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
        "compostiion must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");

#else

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

#endif

  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)bit_ceil((unsigned int)(_n));
        log = countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

using S = std::pair<int, int64_t>;
using F = int;

S op(S a, S b) {
    if(a.first < b.first) {
        return a;
    }
    if(a.first > b.first) {
        return b;
    }
    return S(a.first, a.second + b.second);
}

S e() {
    return {int(2e9), 0};
}

S mapping(F f, S a) {
    a.first += f;
    return a;
}

F composition(F f, F g) {
    return f + g;
}

F id() {
    return 0;
}

class Solution {
public:
    double separateSquares(std::vector<std::vector<int>>& squares) {
        int n = squares.size();
        
        int c_id = 0;
        std::map<int, int> m;
        std::vector<int> end_points;
        for(auto& s : squares) {
            m[s[0]] = 0;
            m[s[0] + s[2]] = 0;
        }
        
        for(auto& [from, to] : m) {
            to = c_id++;
            end_points.push_back(from);
        }
        
        std::sort(end_points.begin(), end_points.end());
        
        std::vector<S> init(end_points.size() - 1);
        for(int i = 1; i < end_points.size(); i++) {
            init[i - 1] = {0, end_points[i] - end_points[i - 1]};
        }
        
        lazy_segtree<S, op, e, F, mapping, composition, id> st(init);

        std::vector<std::array<int, 4>> events;
        for(auto& s : squares) {
            events.push_back({s[1], m[s[0]], m[s[0] + s[2]], 0});
            events.push_back({s[1] + s[2], m[s[0]], m[s[0] + s[2]], 1});
        }
        
        std::sort(events.begin(), events.end());
        
        int64_t area = 0;
        int64_t pre_y = -1;
        int64_t tot = st.all_prod().second;
        for(int i = 0; i < n * 2; ) {
            if(pre_y != -1) {
                S q = st.all_prod();
                area += (events[i][0] - pre_y) * (q.first == 0 ? tot - q.second : tot);
            }
            
            int j = i;
            while(i < n * 2 && events[i][0] == events[j][0]) {
                if(events[i][3] == 0) {
                    st.apply(events[i][1], events[i][2], 1);
                } else {
                    st.apply(events[i][1], events[i][2], -1);
                }
                i += 1;
            }
            pre_y = events[j][0];
        }
        
        double ans = 0.0;
        int64_t now = 0;
        pre_y = -1;
        for(int i = 0; i < init.size(); i++) {
            st.set(i, init[i]);
        }

        for(int i = 0; i < n * 2; ) {
            if(pre_y != -1) {
                S q = st.all_prod();
                int64_t x = q.first == 0 ? tot - q.second : tot;
                now += x * (events[i][0] - pre_y);
                if(now * 2 >= area) {
                    now -= x * (events[i][0] - pre_y);
                    ans = (2 * x * pre_y + area - now * 2) / (2.0 * x);
                    break;
                }
            }
            
            int j = i;
            while(i < n * 2 && events[i][0] == events[j][0]) {
                if(events[i][3] == 0) {
                    st.apply(events[i][1], events[i][2], 1);
                } else {
                    st.apply(events[i][1], events[i][2], -1);
                }
                i += 1;
            }
            pre_y = events[j][0];
        }
        
        return ans;
    }
};
