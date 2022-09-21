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
    int N, X, Y;
    cin >> N >> X >> Y;
   
    string A, B;
    cin >> A >> B;

    int cnt_1 = 0;
    int cnt_2 = 0;
    for(int i = 0; i < N; i++) {
        cnt_1 += A[i] - '0';
        cnt_2 += B[i] - '0';
    }

    if(abs(cnt_1 - cnt_2) & 1) {
        cout << -1 << '\n';
        return;
    }

    LL ans = 0LL;
    int pre = -1;
    int cnt = 0;
    int adj = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            continue;
        }

        if(pre == -1) {
            pre = i;
        } else {
            if(pre + 1 == i) {
                adj++;
            }
            pre = -1;
        }
        cnt++;
    }

    if(cnt == 2) {
        if(X < 2 * Y) {
            ans = adj ? X : Y;
        } else {
            ans = adj ? 2 * Y : Y;
        }
    } else {
        ans = (LL)cnt / 2LL * (LL)Y;
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
