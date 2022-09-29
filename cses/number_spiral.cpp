#include <iostream>

using namespace std;
using LL = long long;

void run_case() {
    int R, C;
    cin >> R >> C;

    int layer = max(R, C);
    LL cur = (1LL + 2LL * layer - 1LL) * layer / 2LL;
    LL pre = (1LL + 2LL * (layer - 1LL) - 1LL) * (layer - 1LL) / 2LL;
     
    if(layer & 1) {
        cout << (R < C ? cur - R + 1LL : pre + C) << '\n';
    } else {
        cout << (R < C ? pre + R : cur - C + 1LL) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
