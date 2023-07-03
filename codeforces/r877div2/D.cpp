#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct lazy_segment_tree {
    public:
        lazy_segment_tree(int n) {
            _n = n;
            while(__builtin_popcount(_n) != 1) {
                _n += 1;
            }
            _m = _n * 2;

            _st.resize(_m, INF);
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
        const int64_t INF = 1000000000000000000;

        int _n;
        int _m;
        std::vector<int64_t> _st;
        std::vector<int64_t> _lazy_add;
        std::vector<int64_t> _lazy_set;
        std::vector<int> _is_add;
        std::vector<int> _is_set;

        void propagate(int v) {
            _st[v] = std::min(_st[v * 2], _st[v * 2 + 1]);
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

        void build(std::vector<int>& a) {
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
                return INF;
            }

            if(lo >= l && hi <= r) {
                return _st[v];
            }

            int mid = (lo + hi) >> 1;

            push(v, lo, mid, hi);

            int64_t lv = query(2 * v, lo, mid, l, r);
            int64_t rv = query(2 * v + 1, mid + 1, hi, l, r);
            
            propagate(v);

            return std::min(lv, rv);
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
    int _n;
    std::vector<int> _st;
    
    fenwick_tree(int n) : _n(n + 1) {
        _st.resize(_n, 0);
    }

    void update(int i, int v) {
        for(++i; i < _n; i += i & -i) {
            _st[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += _st[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    std::set<int> open;
    std::set<int> close;
    lazy_segment_tree st(N);
    fenwick_tree ft(N);

    int bal = 0;
    for(int i = 0; i < N; i++) {
        if(i < N - 1 && S[i] == ')' && S[i + 1] == ')') {
            close.insert(i);
        }
        if(i < N - 1 && S[i] == '(' && S[i + 1] == '(') {
            open.insert(i);
        }

        bal += S[i] == '(' ? 1 : -1;
        st.set(i, i, bal);
        ft.update(i, S[i] == '(' ? 1 : -1);
    } 

    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;
        P -= 1;

        if(S[P] == '(') {
            if(P - 1 >= 0 && S[P - 1] == '(') {
                open.erase(P - 1);
            }
            if(P + 1 < N && S[P + 1] == '(') {
                open.erase(P);
            }

            if(P < N - 1 && S[P + 1] == ')') {
                close.insert(P);
            }

            if(P - 1 >= 0 && S[P - 1] == ')') {
                close.insert(P - 1);
            }
        } else {
            if(P - 1 >= 0 && S[P - 1] == ')') {
                close.erase(P - 1);
            }
            if(P + 1 < N && S[P + 1] == ')') {
                close.erase(P);
            }

            if(P < N - 1 && S[P + 1] == '(') {
                open.insert(P);
            }

            if(P - 1 >= 0 && S[P - 1] == '(') {
                open.insert(P - 1);
            }
        }

        if(S[P] == '(') {
            ft.update(P, -2);
            st.add(P, N - 1, -2);
            S[P] = ')';
        } else {
            ft.update(P, 2);
            st.add(P, N - 1, 2);
            S[P] = '(';
        }

        if(N % 2 == 1) {
            std::cout << "NO" << '\n';
            continue;
        }
        
        if(st.query(0, N - 1) >= 0 && ft.query(0, N - 1) == 0) {
            std::cout << "YES" << '\n';
            continue;
        } 

        int first_open = open.empty() ? -1 : *open.begin();
        int last_close = close.empty() ? N : *close.rbegin();

        if((first_open == -1 && st.query(0, N - 1) < 0) || (first_open && st.query(0, first_open - 1) < 0)) {
            std::cout << "NO" << '\n';
            continue;
        }

        if((last_close == N && ft.query(0, N - 1) > 0) || (last_close + 2 < N && ft.query(last_close + 2, N - 1) > 0)) {
            std::cout << "NO" << '\n';
            continue;
        }

        std::cout << "YES" << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
