#include <iostream>
#include <algorithm>
#include <vector>

struct lazy_segment_tree {
    public:
        lazy_segment_tree(int n) {
            _n = n;
            while(__builtin_popcount(_n) != 1) {
                _n += 1;
            }
            _m = _n * 2;

            _st.resize(_m, -INF);
            _lazy_add.resize(_m, 0);
            _lazy_set.resize(_m, 0);
            _is_add.resize(_m, 0);
            _is_set.resize(_m, 0);
        }

        lazy_segment_tree(std::vector<int64_t>& a) : lazy_segment_tree(a.size()) {
            build(a);
        }

        void add(int i, int64_t v) {
            add(1, 0, _n - 1, i, i, v); 
        }

        void add(int l, int r, int64_t v) {
            add(1, 0, _n - 1, l, r, v);
        }

        void set(int i, int64_t v) {
            set(1, 0, _n - 1, i, i, v);
        }

        void set(int l, int r, int64_t v) {
            set(1, 0, _n - 1, l, r, v);
        }

        int64_t query(int i) {
            return query(1, 0, _n - 1, i, i);
        }
    
        int64_t query(int l, int r) {
            return query(1, 0, _n - 1, l, r); 
        }

    private:
        const int64_t INF = 1000000000000000000;

        int _n;
        int _m;
        std::vector<int64_t> _st;
        std::vector<int64_t> _lazy_add;
        std::vector<int64_t> _lazy_set;
        std::vector<int> _is_add;
        std::vector<int> _is_set;

        void propagate(int v) {
            //_st[v] = _st[v * 2] + _st[v * 2 + 1]; // adapt
            _st[v] = std::max(_st[v * 2], _st[v * 2 + 1]);
        }

        void push(int v, int lo, int mid, int hi) {
            if(_is_set[v]) {
                _is_set[v * 2] = _is_set[v];
                _is_set[v * 2 + 1] = _is_set[v];
                _lazy_set[v * 2] = _lazy_set[v];
                _lazy_set[v * 2 + 1] = _lazy_set[v];

                _st[v * 2] = _lazy_set[v];
                _st[v * 2 + 1] = _lazy_set[v];

                _is_set[v] = 0;
                _is_add[v] = 0;
                _is_add[v * 2] = 0;
                _is_add[v * 2 + 1] = 0;
                _lazy_set[v] = 0;
                _lazy_add[v] = 0;
                _lazy_add[v * 2] = 0;
                _lazy_add[v * 2 + 1] = 0;
            } else if(_is_add[v]) { 
                if(_is_set[v * 2]) {
                    _lazy_set[v * 2] += _lazy_add[v];
                    _is_add[v * 2] = 0;
                } else {
                    _lazy_add[v * 2] += _lazy_add[v];
                    _is_add[v * 2] = 1;
                }

                if(_is_set[v * 2 + 1]) {
                    _lazy_set[v * 2 + 1] += _lazy_add[v];
                    _is_add[v * 2 + 1] = 0;
                } else {
                    _lazy_add[v * 2 + 1] += _lazy_add[v];
                    _is_add[v * 2 + 1] = 1;
                }

                _st[v * 2] += _lazy_add[v];
                _st[v * 2 + 1] += _lazy_add[v];

                _is_add[v] = 0;
                _lazy_add[v] = 0;
            }
        }

        void build(std::vector<int64_t>& a) {
            int n = a.size();
            for(int i = 0; i < n; i++) {
                _st[_n + i] = a[i];
            }

            for(int i = _n - 1; i > 0; i--) {
                propagate(i);
            }
        }

        int64_t query(int v, int lo, int hi, int l, int r) {
            if(hi < l || lo > r) {
                return -INF;
            }

            if(lo >= l && hi <= r) {
                return _st[v];
            }

            int mid = (lo + hi) >> 1;

            push(v, lo, mid, hi);

            int64_t lv = query(2 * v, lo, mid, l, r);
            int64_t rv = query(2 * v + 1, mid + 1, hi, l, r);
            
            propagate(v);

            return std::max(lv, rv);
        }

        void add(int v, int lo, int hi, int l, int r, int64_t val) {
            if(lo > r || hi < l) {
                return;
            }

            if(lo >= l && hi <= r) {
                if(_is_set[v]) {
                    _lazy_set[v] += val; 
                    _is_add[v] = 0;
                } else {
                    _lazy_add[v] += val;
                    _is_add[v] = 1;
                }
                _st[v] += val;
                return;
            } 

            int mid = (lo + hi) >> 1;

            push(v, lo, mid, hi);

            add(2 * v, lo, mid, l, r, val);
            add(2 * v + 1, mid + 1, hi, l, r, val);

            propagate(v);
        }

        void set(int v, int lo, int hi, int l, int r, int64_t val) {
            if(lo > r || hi < l) {
                return;
            }

            if(lo >= l && hi <= r) {
                _lazy_set[v] = val;
                _lazy_add[v] = 0;
                _is_set[v] = 1;
                _is_add[v] = 0;
                _st[v] = val;
                return;
            } 

            int mid = (lo + hi) >> 1;

            push(v, lo, mid, hi);

            set(2 * v, lo, mid, l, r, val);
            set(2 * v + 1, mid + 1, hi, l, r, val);

            propagate(v);
        }
};

struct fenwick_tree {
    int n;
    std::vector<int64_t> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

    void update(int i, int64_t v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    int64_t query(int i) {
        int64_t res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    int64_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int64_t> A(N);
    fenwick_tree ft(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        ft.update(i, A[i]);
    }

    std::vector<int64_t> psum(N, 0);
    psum[0] = A[0];
    for(int i = 1; i < N; i++) {
        psum[i] = psum[i - 1] + A[i];
    }

    lazy_segment_tree st(psum);
    
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int P, V;
            std::cin >> P >> V;
            P -= 1;

            st.add(P, N - 1, V - A[P]);
            ft.update(P, V - A[P]);
            A[P] = V;
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;

            int64_t max_s = st.query(L, R);
            int64_t sum = ft.query(L - 1); 

            std::cout << std::max((int64_t)0, max_s - sum) << '\n';
        }
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    run_case();
}
