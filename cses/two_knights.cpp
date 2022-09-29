#include <iostream>
#include <array>
#include <vector>

using namespace std;
using ll = long long;

void run_case() {
    int n;
    cin >> n;

    cout << 0 << '\n';

    for(int k = 2; k <= n; k++) {
        ll tot = 1ll * k * k;
        ll cnt = tot * (tot - 1ll) / 2ll;

        cnt -= k > 2 ? 4ll * (k - 2) * (k - 1) : 0ll;

        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
