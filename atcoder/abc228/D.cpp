#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N = 1 << 20;
    int Q;
    cin >> Q;
    //xxooooxxxooxooxo
    vector<LL> A(N, -1);
    set<int> s;
    for(int i = 0; i < N; i++) {
        s.insert(i);
    }

    for(int i = 0; i < Q; i++) {
        LL T, X;
        cin >> T >> X;

        if(T == 1LL) {
            int h = X % N;
            if(A[h] == -1) {
                A[h] = X;
                s.erase(h);
            } else {
                auto it = s.upper_bound(h);
                if(it == s.end()) {
                    it = s.lower_bound(0);
                }

                if(it != s.end()) {
                    A[*it] = X;
                    s.erase(it);
                }
            }
        } else {
            cout << A[X % N] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
