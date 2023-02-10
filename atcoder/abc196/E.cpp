#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = 2e15;

void run_case() {
    int N;
    cin >> N;

    LL d = 0LL;
    LL l = -INF;
    LL r = INF;
    
    for(int i = 0; i < N; i++) {
        int A, T;
        cin >> A >> T;

        if(T == 1) {
            d += A; 
            l += A;
            r += A;
        } else if(T == 2) {
            l = max(l, (LL)A);
            r = max(r, (LL)A);
        } else {
            l = min(l, (LL)A);
            r = min(r, (LL)A);
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        LL X;
        cin >> X;

        X += d;
        if(X > r) {
            X = r;
        }
        if(X < l) {
            X = l;
        }

        cout << X << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
