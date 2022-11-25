#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> ans(N, 0);
    
    if(N % 2 == 0) {
        ans[0] = N / 2;
        ans[N - 1] = N / 2 * 3;
        for(int l = 1, r = N - 2; l < r; l += 1, r -= 1) {
            ans[l] = ans[l - 1] + 1;
            ans[r] = ans[r + 1] - 1;
        }
    } else {
        ans[N / 2] = N;

        // sum = 2^n
        // max - min = n - 1
        for(int l = N / 2 - 1, r = N / 2 + 1; l >= 0; l -= 1, r += 1) {
            ans[l] = ans[l + 1] - 1;
            ans[r] = ans[r - 1] + 1;
        }

        // sum = n^2 + 2n
        // max - min = n - 1
        for(int i = 0; i < N; i++) {
            ans[i] += 2;
        }

        // sum = n^2 + 2n
        // max - min = n + 1
        ans[0] -= 1;
        ans[N - 1] += 1;

        // sum = n^2 + 2n + 1
        // max - min = n + 1
        ans[N - 2] += 1;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
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
