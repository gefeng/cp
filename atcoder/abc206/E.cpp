#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MAX = (int)1e6;

void run_case() {
    int L, R;
    cin >> L >> R;

    auto f = [&](int g) -> LL {
        LL x = R / g - (L - 1) / g;
        return x * x;
    };

    LL ans = 0LL;
    vector<LL> save(R + 1, 0LL);
    for(int g = R; g >= 2; g--) {
        save[g] = f(g);
        for(int i = g + g; i <= R; i += g) {
            save[g] -= save[i];
        }
        //cout << g << ' ' << save[g] << '\n';
        ans += save[g];
    }

    for(int i = L; i <= R; i++) {
        if(i == 1) continue;
        ans -= 2LL * (R / i) - 1LL;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
