#include <iostream>
#include <utility>
#include <vector>

struct lazy_segment_tree {
    public:
        lazy_segment_tree(int n) {
            _n = n;
            while(__builtin_popcount(_n) != 1) {
                _n += 1;
            }
            _m = _n * 2;

            _st.resize(_m, 0);
            _lazy_add.resize(_m, 0);
            _lazy_set.resize(_m, 0);
            _is_add.resize(_m, 0);
            _is_set.resize(_m, 0);
        }

        lazy_segment_tree(std::vector<int>& a) : lazy_segment_tree(a.size()) {
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
        int _n;
        int _m;
        std::vector<int64_t> _st;
        std::vector<int64_t> _lazy_add;
        std::vector<int64_t> _lazy_set;
        std::vector<int> _is_add;
        std::vector<int> _is_set;

        void propagate(int v, int lo, int mid, int hi) {
            _st[v] = _st[v * 2] + _st[v * 2 + 1];
        }

        void push(int v) {
            if(_is_set[v] && _is_add[v]) {
                _lazy_set[v] += _lazy_add[v]; 
            }

            if(_is_set[v]) {
                _is_set[v * 2] = _is_set[v];
                _is_set[v * 2 + 1] = _is_set[v];
                _lazy_set[v * 2] = _lazy_set[v];
                _lazy_set[v * 2 + 1] = _lazy_set[v];

                _is_set[v] = 0;
                _is_add[v] = 0;
                _is_add[v * 2] = 0;
                _is_add[v * 2 + 1] = 0;
                _lazy_set[v] = 0;
                _lazy_add[v] = 0;
                _lazy_add[v * 2] = 0;
                _lazy_add[v * 2 + 1] = 0;
            } else { 
                _is_add[v * 2] = _is_add[v];
                _is_add[v * 2 + 1] = _is_add[v];
                _lazy_add[v * 2] += _lazy_add[v];
                _lazy_add[v * 2 + 1] += _lazy_add[v];

                _is_add[v] = 0;
                _lazy_add[v] = 0;
            }
        }

        void build(std::vector<int>& a) {
            int n = a.size();
            for(int i = 0; i < n; i++) {
                _st[_n + i] = a[i];
            }

            for(int i = _n - 1; i > 0; i--) {
                propagate(i, 0, 0, 0);
            }
        }

        int64_t query(int v, int lo, int hi, int l, int r) {
            if(lo >= l && hi <= r) {
                if(_is_set[v]) {
                    return _lazy_set[v] * (hi - lo + 1);
                } else {
                    return _st[v] + _lazy_add[v] * (hi - lo + 1);
                }
            }

            if(hi < l || lo > r) {
                return 0;
            }

            int mid = (lo + hi) >> 1;

            push(v);

            int64_t l_res = query(2 * v, lo, mid, l, r);
            int64_t r_res = query(2 * v + 1, mid + 1, hi, l, r);
            
            propagate(v, lo, mid, hi);

            return l_res + r_res;
        }

        void add(int v, int lo, int hi, int l, int r, int64_t val) {
            if(lo > r || hi < l) {
                return;
            }

            if(lo >= l && hi <= r) {
                _lazy_add[v] += val;
                return;
            } 

            int mid = (lo + hi) >> 1;

            push(v);

            add(2 * v, lo, mid, l, r, val);
            add(2 * v + 1, mid + 1, hi, l, r, val);

            propagate(v, lo, mid, hi);
        }

        void set(int v, int lo, int hi, int l, int r, int64_t val) {
            if(lo > r || hi < l) {
                return;
            }

            if(lo >= l && hi <= r) {
                _lazy_set[v] = val;
                _lazy_add[v] = 0;
                return;
            } 

            int mid = (lo + hi) >> 1;

            push(v);

            set(2 * v, lo, mid, l, r, val);
            set(2 * v + 1, mid + 1, hi, l, r, val);

            propagate(v, lo, mid, hi);
        }
};

/*struct lazy_segment_tree {
    public:
        lazy_segment_tree(int n) {
            _n = n;
            while(__builtin_popcount(_n) != 1) {
                _n += 1;
            }
            _m = _n * 2;

            _st.resize(_m, 0);
            _lazy.resize(_m, 0);
        }

        lazy_segment_tree(std::vector<int>& a) : lazy_segment_tree(a.size()) {
            build(a);
        }

        void increment(int i, int64_t v) {
            increment(1, 0, _n - 1, i, i, v); 
        }

        void increment(int l, int r, int64_t v) {
            increment(1, 0, _n - 1, l, r, v);
        }

        void assign(int i, int64_t v) {
            assign(1, 0, _n - 1, i, i, v);
        }

        void assign(int l, int r, int64_t v) {
            assign(1, 0, _n - 1, l, r, v);
        }

        int64_t query(int i) {
            return query(1, 0, _n - 1, i, i);
        }
    
        int64_t query(int l, int r) {
            return query(1, 0, _n - 1, l, r); 
        }

    private:
        int _n;
        int _m;
        std::vector<int64_t> _st;
        std::vector<int64_t> _lazy;

        void propagate(int v, int lo, int mid, int hi) {
            int64_t l = _lazy[v * 2] * (mid - lo + 1);
            int64_t r = _lazy[v * 2 + 1] * (hi - mid);
            _st[v] = _st[v * 2] + _st[v * 2 + 1] + l + r + _lazy[v] * (hi - lo + 1);
        }

        void push(int v) {
            _lazy[v * 2] += _lazy[v];
            _lazy[v * 2 + 1] += _lazy[v];
            _lazy[v] = 0;
        }

        void build(std::vector<int>& a) {
            int n = a.size();
            for(int i = 0; i < n; i++) {
                _st[_n + i] = a[i];
            }

            for(int i = _n - 1; i > 0; i--) {
                propagate(i, 0, 0, 0);
            }
        }

        int64_t query(int v, int lo, int hi, int l, int r) {
            if(lo >= l && hi <= r) {
                return _st[v] + _lazy[v] * (hi - lo + 1);
            }

            if(hi < l || lo > r) {
                return 0;
            }

            int mid = (lo + hi) >> 1;

            push(v);

            int64_t l_res = query(2 * v, lo, mid, l, r);
            int64_t r_res = query(2 * v + 1, mid + 1, hi, l, r);
            
            propagate(v, lo, mid, hi);

            return l_res + r_res;
        }

        void increment(int v, int lo, int hi, int l, int r, int val) {
            if(lo > r || hi < l) {
                return;
            }

            if(lo >= l && hi <= r) {
                _lazy[v] += val;
                return;
            } 

            int mid = (lo + hi) >> 1;

            push(v);

            increment(2 * v, lo, mid, l, r, val);
            increment(2 * v + 1, mid + 1, hi, l, r, val);

            propagate(v, lo, mid, hi);
        }

        void assign(int v, int lo, int hi, int l, int r, int val) {
            if(lo > r || hi < l) {
                return;
            }

            if(lo >= l && hi <= r) {
                _lazy[v] = val;
                return;
            } 

            int mid = (lo + hi) >> 1;

            push(v);

            assign(2 * v, lo, mid, l, r, val);
            assign(2 * v + 1, mid + 1, hi, l, r, val);

            propagate(v, lo, mid, hi);
        }
};*/

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    lazy_segment_tree st(A);

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int L, R, V;
            std::cin >> L >> R >> V;

            L -= 1;
            R -= 1;

            st.add(L, R, V);
        } else {
            int P;
            std::cin >> P;

            P -= 1;

            std::cout << st.query(P) << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
