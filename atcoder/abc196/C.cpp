#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

int dfs(LL N, int half, LL cur, LL d, int cur_len) {
    if(cur_len == half) {
        LL x = cur * d + cur; 
        return x <= N ? 1 : 0;
    } 

    int st = cur == 0 ? 1 : 0;
    int res = 0;
    for(int i = st; i < 10; i++) {
        res += dfs(N, half, cur * 10LL + i, d * 10LL, cur_len + 1);
    }
    return res;
}

void run_case() {
    LL N;
    cin >> N; 

    int ans = 0;
    for(int len = 2; len <= 12; len += 2) {
        int half = len / 2;

        ans += dfs(N, half, 0LL, 1LL, 0); 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
