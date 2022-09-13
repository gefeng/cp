#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7;

void run_case(int T) {
    int N;
    string S;
    cin >> N >> S;
    
    LL ans = 0LL;
    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'X' || S[i] == 'O') {
            if(pre != -1 && S[pre] != S[i]) {
                ans += (LL)(pre + 1) * (N - i);
                ans %= MOD;
            }
            pre = i;
        }
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
