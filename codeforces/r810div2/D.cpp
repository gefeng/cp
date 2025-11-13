#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <tuple>
#include <functional>

constexpr int64_t INF = static_cast<int64_t>(2e18);

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

using S = int64_t;

S op(S a, S b) {
    return std::max(a, b);
}

S id() {
    return -INF;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [x, y, z] = A[i];
        std::cin >> x >> y;
        z = i;
    }

    std::ranges::sort(A);

    std::vector<int64_t> diff1(N + 1, 0);
    std::vector<int64_t> diff2(N + 1, 0);
    std::vector<int64_t> h(N, 0);
    
    for(int i = 0; i < N; i++) {
        auto [x, p, _] = A[i];
        int j = std::lower_bound(A.begin(), A.end(), x - p, [](const auto& x, int y) {
                    return std::get<0>(x) < y;
                }) - A.begin();

        diff1[j] += p - x;
        diff2[j] += 1;
        diff1[i] -= p - x;
        diff2[i] -= 1;
    }

    int64_t rolling_s = 0;
    int64_t rolling_c = 0;
    for(int i = 0; i < N; i++) {
        rolling_s += diff1[i];        
        rolling_c += diff2[i];
        h[i] += std::get<1>(A[i]) + rolling_s + rolling_c * std::get<0>(A[i]);
    } 

    diff1.assign(N + 1, 0);
    diff2.assign(N + 1, 0);
    rolling_s = 0;
    rolling_c = 0;
    for(int i = 0; i < N; i++) {
        auto [x, p, _] = A[i];
        int j = std::upper_bound(A.begin(), A.end(), x + p, [](int x, const auto& y) {
                    return x < std::get<0>(y);
                }) - A.begin();

        diff1[i + 1] += p + x;
        diff2[i + 1] += 1;
        diff1[j] -= p + x;
        diff2[j] -= 1;
    }

    for(int i = 0; i < N; i++) {
        rolling_s += diff1[i];        
        rolling_c += diff2[i];
        h[i] += rolling_s - rolling_c * std::get<0>(A[i]);
    } 

    std::string ans(N, '0');    
    segtree<S, op, id> st1(N);
    segtree<S, op, id> st2(N);
    segtree<S, op, id> st3(N);

    for(int i = 0; i < N; i++) {
        st1.set(i, h[i]);
        st2.set(i, h[i] - std::get<0>(A[i]));
        st3.set(i, h[i] + std::get<0>(A[i]));
    }

    for(int i = 0; i < N; i++) {
        auto [x, p, idx] = A[i];
        int l = std::lower_bound(A.begin(), A.end(), x - p, [](const auto& x, int y) {
                    return std::get<0>(x) < y;
                }) - A.begin();

        int r = std::upper_bound(A.begin(), A.end(), x + p, [](int x, const auto& y) {
                    return x < std::get<0>(y);
                }) - A.begin();

        int64_t max1 = st2.prod(l, i) - (p - x);
        int64_t max2 = st3.prod(i + 1, r) - (p + x);
        max1 = std::max(max1, st1.prod(0, l));
        max2 = std::max(max2, st1.prod(r, N));

        if(std::max(h[i] - p, std::max(max1, max2)) <= M) {
            ans[idx] = '1';
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
