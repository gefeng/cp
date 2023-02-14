#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    LL N;
    cin >> N;

    LL ans = N;
    set<LL> seen;
    for(LL i = 2LL; i * i <= N; i++) {
        LL x = i * i;
        while(x <= N) {
            if(seen.find(x) == seen.end()) {
                ans -= 1LL;
                seen.insert(x);
            }
            x *= i;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
