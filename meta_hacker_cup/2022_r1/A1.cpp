#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case(int T) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);
    vector<int> B(N, 0);
    vector<int> P(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        P[A[i]] = i;
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
    }

    bool ok = true;
    int d = (0 - P[B[0]] + N) % N;
    for(int i = 1; i < N; i++) {
        if((i - P[B[i]] + N) % N != d) {
            ok = false;
            break;
        }
    }

    if(ok) {
        if(N == 2) {
            ok = d % 2 == K % 2;
        } else {
            if(d == 0) {
                ok = K != 1;
            } else {
                ok = K > 0;
            } 
        }
    }

    cout << "Case #" << T << ": " << (ok ? "YES" : "NO") << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
