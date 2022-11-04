#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using LL = long long;

// the official livestream introduce a more efficient way instead of
// doing prime factorization for each number.
void run_case() {
    LL N;
    cin >> N;

    vector<LL> f(N + 1, 0LL);
    for(LL i = 1LL; i <= N; i++) {
        f[i] = i;
    }
    
    for(LL i = 2LL; i * i <= N; i++) {
        LL x = i * i;
        for(int j = x; j <= N; j += x) {
            while(f[j] % x == 0) {
                f[j] /= x;
            }
        } 
    }

    vector<LL> cnt(N + 1, 0LL);
    for(LL i = 1LL; i <= N; i++) {
        cnt[f[i]] += 1LL;
    }

    LL ans = 0LL;
    for(LL i = 1LL; i <= N; i++) {
        ans += cnt[i] * cnt[i];
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
