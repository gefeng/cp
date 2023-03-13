#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, X, P;
    cin >> N >> X >> P;

    int c = N - (X % N);
    for(int i = 1; i <= min(2 * N, P); i++) {
        LL x = 1LL * i * (i + 1) / 2LL;
        
        if(x % N == c % N) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
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
