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
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    
    LL ans = 0LL;
    if(A[0] == A[N - 1]) {
        ans = 1LL * (N - 1) * N; 
    } else {
        int x = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] != A[0]) {
                break;
            }
            x += 1;
        }

        int y = 0;
        for(int i = N - 1; i >= 0; i--) {
            if(A[i] != A[N - 1]) {
                break;
            }
            y += 1;
        }

        ans = 2LL * x * y;
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
