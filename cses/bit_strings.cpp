#include <iostream>
#include <string>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7;

void run_case() {
    int N;
    cin >> N;
    
    LL ans = 1LL;
    for(int i = 0; i < N; i++) {
        ans *= 2LL;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
