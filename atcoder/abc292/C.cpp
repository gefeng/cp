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

    LL ans = 0LL;
    vector<LL> cnt(N + 1, 0LL);
    vector<bool> is_perfect(N + 1, false);

    for(int i = 1; i < N; i++) {
        LL x = 0;
        for(int f = 1; f * f <= i; f++) {
            if(i % f == 0) {
                x += 1LL;
                if(i / f == f) {
                    is_perfect[i] = true;
                }
            } 
        }

        cnt[i] = x;
    }

    for(int i = 1; i < N; i++) {
        LL x = cnt[i] * 2LL;
        LL y = cnt[N - i] * 2LL;

        if(is_perfect[i]) {
            x -= 1LL;
        }
        if(is_perfect[N - i]) {
            y -= 1LL;
        }
        //cout << i << ' ' << N - i << ' ' << x << ' ' << y << '\n';
        
        ans += x * y;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
