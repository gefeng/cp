#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <climits>

using namespace std;
using LL = long long;

const LL MAX = 6208LL;

void run_case() {
    LL X;
    cin >> X;

    map<LL, LL> m;
    for(LL i = -MAX; i <= MAX; i++) {
        m[i * i * i * i * i] = i;
    }

    for(LL b = -MAX; b <= MAX; b++) {
        LL b5 = b * b * b * b * b;
        if(b5 < 0) {
            if(b5 + X >= LLONG_MIN && m.find(b5 + X) != m.end()) {
                cout << m[b5 + X] << ' ' << b << '\n';
                return;
            }
        } else {
            if(b5 <= LLONG_MAX - X && m.find(b5 + X) != m.end()) {
                cout << m[b5 + X] << ' ' << b << '\n';
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
