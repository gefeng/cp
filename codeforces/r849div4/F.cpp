#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

struct fenwick_tree {
    int sz;
    vector<int> t;

    fenwick_tree(int n) : sz(n + 5) {
        t.resize(sz, 0);
    }

    void update(int i, int v) {
        for(++i; i < sz; i += i & -i) {
            t[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += t[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i]; 
    }

    fenwick_tree ft1(N);
    fenwick_tree ft2(N);
    
    auto f = [](int x) -> int {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };

    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if(T == 1) {
            int L, R;
            cin >> L >> R;
            L -= 1;
            R -= 1;

            ft1.update(L, 1);
            ft2.update(R, 1);
        } else {
            int X;
            cin >> X;
            X -= 1;
            
            int tot = ft2.query(X, N - 1) - ft1.query(X + 1, N - 1);

            int res = A[X];
            while(tot) {
                int nxt = f(res);
                if(nxt == res) {
                    break;
                }
                tot -= 1;
                res = nxt;
            }

            cout << res << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
