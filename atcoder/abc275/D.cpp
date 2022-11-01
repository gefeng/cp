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

LL dfs(LL x, map<LL, LL>& m) {
    if(x == 0LL) {
        return 1LL;
    }

    if(m.find(x) != m.end()) {
        return m[x];
    }

    LL ans = dfs(x / 2, m) + dfs(x / 3, m);
    m[x] = ans;

    return ans;
}

void run_case() {
    LL N;
    cin >> N;

    map<LL, LL> m;
    LL ans = dfs(N, m);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
