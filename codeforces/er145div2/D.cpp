#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL PRICE1 = 1000000000000LL;
const LL PRICE2 = 1000000000001LL;
const LL INF = (LL)2e18;

void run_case() {
    string S;
    cin >> S;
    
    int N = S.size();

    vector<int> save_0(N, 0);
    vector<int> save_1(N, 0);

    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            save_1[i] = i == 0 ? 1 : save_1[i - 1] + 1;
        } else {
            save_1[i] = i == 0 ? 0 : save_1[i - 1];
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '0') {
            save_0[i] = i == N - 1 ? 1 : save_0[i + 1] + 1;
        } else {
            save_0[i] = i == N - 1 ? 0 : save_0[i + 1];
        }
    }

    LL ans = min(PRICE2 * save_1[N - 1], PRICE2 * save_0[0]);
    for(int i = 0; i < N; i++) {
        int l = i == 0 ? 0 : save_1[i - 1]; 
        int r = i == N - 1 ? 0 : save_0[i + 1];

        LL cost = PRICE2 * (l + r);
        ans = min(ans, cost);

        if(i < N - 1 && S[i] == '1' && S[i + 1] == '0') {
            l = i == 0 ? 0 : save_1[i - 1]; 
            r = i == N - 2 ? 0 : save_0[i + 2];
            cost = PRICE1 + PRICE2 * (l + r);
            ans = min(ans, cost);
        }
    }

    if(ans == INF) {
        ans = 0LL;
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
