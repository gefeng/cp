#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>

constexpr int INF = int(1e9);

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
    return 0;
}

int K;
bool g(S x) {
    return x < K;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int M;
    std::cin >> M;
    std::vector<std::pair<int, int>> queries;
    std::vector<int> a;
    std::set<int> s;
    for(int i = 0; i < M; i++) {
        char T;
        std::cin >> T;
        
        if(T == '+') {
            int X;
            std::cin >> X;
            queries.emplace_back(0, X);
            a.push_back(X);
        } else if(T == '-') {
            int X;
            std::cin >> X;
            queries.emplace_back(1, X);
            a.push_back(X);
        } else {
            int K;
            std::cin >> K;
            queries.emplace_back(2, K);
            a.push_back(K);
        }
    } 

    for(int x : A) {
        s.insert(x);
        a.push_back(x);
    }

    s.insert(0);
    a.push_back(0);

    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    
    segtree<S, op, e> st(a.size());

    auto update = [&](int x, int len) {
        int i = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        st.set(i, len);
    };

    auto insert = [&](int x) {
        auto it_nxt = s.lower_bound(x); 
        auto it_pre = std::prev(it_nxt); 
        int pre_len = x - *it_pre - 1;
        int cur_len = it_nxt == s.end() ? INF : *it_nxt - x - 1;
        
        update(*it_pre, pre_len);
        update(x, cur_len);
        s.insert(x);
    };
    
    auto remove = [&](int x) {
        auto it_cur = s.lower_bound(x); 
        auto it_pre = std::prev(it_cur);
        auto it_nxt = std::next(it_cur);
        
        int pre_len = it_nxt == s.end() ? INF : *it_nxt - *it_pre - 1;
        int cur_len = 0;
        
        update(*it_pre, pre_len);
        update(x, cur_len);
        s.erase(x);
    };

    for(int x : s) {
        auto it = s.upper_bound(x);
        int len = it == s.end() ? INF : *it - x - 1; 
        update(x, len);
    }

    for(auto [t, x] : queries) {
        if(t == 0) {
            insert(x); 
        } else if(t == 1) {
            remove(x);
        } else {
            K = x;
            int i = st.max_right<g>(0);
            if(i < a.size()) {
                std::cout << a[i] + 1 << ' ';
            }
        }
    }
    std::cout << std::endl;
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
