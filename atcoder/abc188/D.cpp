#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N; LL C;
    cin >> N >> C;

    map<LL, LL> m;
    for(int i = 0; i < N; i++) {
        LL A, B, W;
        cin >> A >> B >> W;

        m[A] += W;
        m[B + 1] -= W;
    }

    LL ans = 0LL;
    LL sum = 0LL;
    LL pre = -1LL;
    for(auto& [k, v] : m) {
        if(pre != -1LL) {
            ans += min(sum, (LL)C) * (k - pre); 
        }
        sum += v;
        pre = k;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
