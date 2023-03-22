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
    string S;
    cin >> S;
    
    map<int, int> m;
    m[0] = 1;
    int x = 0;
    int d = 1;
    LL ans = 0LL;

    for(int i = S.size() - 1; i >= 0; i--) {
        x = d * (S[i] - '0') + x;
        x %= 2019;
        d *= 10;
        d %= 2019;

        if(m.find(x) != m.end()) {
            ans += m[x];
        }

        m[x] += 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
