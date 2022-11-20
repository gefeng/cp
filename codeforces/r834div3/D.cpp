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
    LL N, M;
    cin >> N >> M;

    int cnt_2 = 0;
    int cnt_5 = 0;
    LL x = N;
    while(x % 2LL == 0LL) {
        cnt_2 += 1;
        x /= 2LL;
    }

    while(x % 5LL == 0LL) {
        cnt_5 += 1;
        x /= 5LL;
    }

    int d = min(cnt_2, cnt_5);
    cnt_2 -= d;
    cnt_5 -= d;
    
    LL ans = 1LL;
    while(ans * 2LL <= M && cnt_5) {
        cnt_5 -= 1LL;
        ans *= 2LL;
    }
    while(ans * 5LL <= M && cnt_2) {
        cnt_2 -= 1LL;
        ans *= 5LL;
    }

    while(ans * 10LL <= M) {
        ans *= 10LL; 
    }

    ans = M / ans * ans;    
    ans *= N;
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
