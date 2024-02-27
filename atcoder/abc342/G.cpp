#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct segtree {
    int n, m, h;
    std::vector<std::multiset<int>> st;
    
    segtree(std::vector<int>& a) {
        n = 1;
        int size = a.size();
        while(n < size) {
            n <<= 1; 
        }
        m = n;
        n <<= 1;
        h = n >> 1;
        
        st.resize(n);

        for(int i = 0; i < size; i++) {
            st[i + h].insert(a[i]);
        }
    }

    void update(int l, int r, int t, int x) {
        update(l, r, 1, 0, m - 1, t, x);  
    }

    int query(int i) {
        return query(i, 1, 0, m - 1);    
    }

    void update(int l, int r, int v, int tl, int tr, int t, int x) {
        if(tl >= l && tr <= r) {
            if(t == 1) {
                st[v].insert(x);
            } else {
                st[v].erase(x);
            } 
            return;
        } 

        if(tl > r || tr < l) {
            return;
        }

        int m = (tl + tr) >> 1;
        update(l, r, 2 * v, tl, m, t, x);
        update(l, r, 2 * v + 1, m + 1, tr, t, x);
    }

    int query(int i, int v, int tl, int tr) { 
        if(tl == tr && tl == i) {
            return *st[v].rbegin();
        }
        if(tr < i || tl > i) {
            return 0;
        }

        int res = i >= tl && i <= tr && !st[v].empty() ? *st[v].rbegin() : 0;
        int m = (tl + tr) >> 1;
        res = std::max(res, std::max(query(i, v * 2, tl, m), query(i, v * 2 + 1, m + 1, tr)));
        return res;
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    segtree st(A);

    int Q;
    std::cin >> Q;
    std::vector<std::array<int, 3>> save(Q); 
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int L, R, X;
            std::cin >> L >> R >> X;
            L -= 1;
            R -= 1;

            save[i] = {L, R, X};
            
            st.update(L, R, 1, X);
        } else if(T == 2) {
            int P;
            std::cin >> P;
            P -= 1;
            std::array<int, 3> op = save[P];

            st.update(op[0], op[1], 2, op[2]);
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
