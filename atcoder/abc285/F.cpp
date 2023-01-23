#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct fenwick_tree {
    int sz;
    vector<int> t;
    
    fenwick_tree(int n) : sz(n + 5) {
        t.resize(sz, 0);
    }

    void update(int i, int x) {
        for(++i; i < sz; i += i & -i) {
            t[i] += x;
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
    int N;
    cin >> N;

    string S;
    cin >> S;

    fenwick_tree ft(N);
    vector<fenwick_tree> v(26, fenwick_tree(N));

    for(int i = 0; i < N - 1; i++) {
        if(S[i] > S[i + 1]) {
            ft.update(i, 1);
        } 
    }

    for(int i = 0; i < N; i++) {
        int j = S[i] - 'a';
        v[j].update(i, 1);
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if(T == 1) {
            int X;
            char C;
            cin >> X >> C;
            X -= 1;

            if(X < N - 1 && S[X] > S[X + 1]) {
                ft.update(X, -1);
            }
            if(X > 0 && S[X - 1] > S[X]) {
                ft.update(X - 1, -1);
            }
            v[S[X] - 'a'].update(X, -1);

            S[X] = C;
            if(X < N - 1 && S[X] > S[X + 1]) {
                ft.update(X, 1);
            }
            if(X > 0 && S[X - 1] > S[X]) {
                ft.update(X - 1, 1);
            }

            v[C - 'a'].update(X, 1);
        } else {
            int L, R;
            cin >> L >> R;
            L -= 1;
            R -= 1;

            int sum = ft.query(L, R - 1);
            if(sum) {
                cout << "No" << '\n';
            } else {
                bool ok = true;
                for(char c = S[L] + 1; c < S[R]; c++) {
                    int j = c - 'a';
                    int cnt = v[j].query(L, R);
                    int tot = v[j].query(0, N);
                    if(cnt != tot) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
