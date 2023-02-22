#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

struct seg_tree {
    int N, M, H;
    vector<int> st;

    seg_tree(int n) {
        build(n);
    }

    seg_tree(vector<int>& v) {
        build(v);
    }

    int highest_one_bit(unsigned int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1); 
    }

    void propagate(int i) {
        st[i] = st[2 * i] ^ st[2 * i + 1];
    }

    void build(int n) {
        N = n;
        M = highest_one_bit(max(1, N - 1)) << 2; 
        H = M / 2;
        st.resize(M, 0);
    }

    void build(vector<int>& v) {
        build(v.size());
        
        for(int i = 0; i < N; i++) {
            st[i + H] = v[i];
        }
        
        for(int i = H - 1; i > 0; i--) {
            propagate(i);
        }
    }

    void add(int i, int v) {
        st[i + H] = v;
        for(int j = (i + H) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }

    int query(int l, int r) {
        int sum = 0;   
        for(l += H, r += H; l <= r; l >>= 1, r >>= 1) {
            if(l & 1) {
                sum ^= st[l++];
            }
            if(!(r & 1)) {
                sum ^= st[r--];
            }
        }
        return sum;
    }
};

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    seg_tree st(A);

    for(int i = 0; i < Q; i++) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if(T == 1) {
            X -= 1;
            st.add(X, A[X] ^ Y);
            A[X] ^= Y;
        } else {
            X -= 1;
            Y -= 1;
            cout << st.query(X, Y) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
