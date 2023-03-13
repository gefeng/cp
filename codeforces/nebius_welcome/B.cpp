#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K, D, W;
    cin >> N >> K >> D >> W;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for(int i = 0; i < N; ) {
        int t = A[i] + W;
        int d = K;
        while(i < N && d && A[i] <= t + D) {
            i += 1;
            d -= 1;
        }

        ans += 1; 
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
