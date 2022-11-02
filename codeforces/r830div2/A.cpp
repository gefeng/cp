#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    int g = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];

        if(i == 0) {
            g = A[i];
        } else {
            g = gcd(g, A[i]);
        }
    }

    if(g == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> G(N, 0);
    for(int i = 0; i < N; i++) {
        G[i] = gcd(i + 1, A[i]);
    }

    int ans = 3;
    for(int i = 0; i < N; i++) {
        if(gcd(g, gcd(i + 1, A[i])) == 1) {
            ans = min(ans, N - i);
        }
    }

    cout << ans << '\n';
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
