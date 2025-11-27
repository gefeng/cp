#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
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

S id() {
    return -1;
}

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    
    dsu(int n_) : n(n_), p(n, -1), w(n, 1) {}

    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }
        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }

    int size(int i) {
        return w[find(i)];
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::vector<std::pair<int, int>> E(M);
    for(int i = 0; i < M; i++) {
        std::cin >> E[i].first >> E[i].second;
        E[i].first -= 1;
        E[i].second -= 1;
    }

    dsu uf(N);
    std::vector<std::vector<int>> groups(N);
    std::vector<int> f(N, -1); // first f[i] edges to connect i - 1 and i

    for(int i = 0; i < N; i++) {
        groups[i].push_back(i);
    }

    for(int i = 0; i < M; i++) {
        auto [u, v] = E[i]; 
        if(uf.same(u, v)) {
            continue;
        }
        if(uf.size(u) >= uf.size(v)) {
            int pu = uf.find(u);
            int pv = uf.find(v);
            assert(groups[pu].size() >= groups[pv].size());
            uf.unite(u, v);
            for(int x : groups[pv]) {
                groups[pu].push_back(x);
            }
            while(!groups[pv].empty()) {
                int x = groups[pv].back();
                groups[pv].pop_back();
                if(x - 1 >= 0 && f[x] == -1 && uf.same(x, x - 1)) {
                    f[x] = i;
                }
                if(x + 1 < N && f[x + 1] == -1 && uf.same(x, x + 1)) {
                    f[x + 1] = i;
                }
            }
        } else {
            int pu = uf.find(u);
            int pv = uf.find(v);
            assert(groups[pu].size() < groups[pv].size());
            uf.unite(u, v);
            for(int x : groups[pu]) {
                groups[pv].push_back(x);
            }
            while(!groups[pu].empty()) {
                int x = groups[pu].back();
                groups[pu].pop_back();
                if(x - 1 >= 0 && f[x] == -1 && uf.same(x, x - 1)) {
                    f[x] = i;
                }
                if(x + 1 < N && f[x + 1] == -1 && uf.same(x, x + 1)) {
                    f[x + 1] = i;
                }
            }
        }
    }

    segtree<S, op, id> st(f);

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        int res = L == R ? 0 : st.prod(L + 1, R + 1) + 1;

        std::cout << res << " \n"[i == Q - 1];
    }
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
