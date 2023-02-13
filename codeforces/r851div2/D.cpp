#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> p_2(N + 1);
    p_2[0] = 1LL;
    for(int i = 1; i <= N; i++) {
        p_2[i] = p_2[i - 1] * 2LL;
        p_2[i] %= MOD;
    }

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        int l = i - 1;
        int r = 0;
        for(int j = i + 1; j < N; j++) {
            int d = A[j] - A[i];
            
            while(l >= 0 && A[i] - A[l] <= d) {
                l -= 1;
            }

            r = j + 1;
            while(r < N && A[r] - A[j] < d) {
                r += 1;
            } 

            int cnt = l + 1 + N - r;
            ans += p_2[cnt];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
