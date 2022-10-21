#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL gcd(LL a, LL b) {
    if(a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    LL A, B, C, D;
    cin >> A >> B >> C >> D;

    LL Z = A * B;
    LL x = -1LL;
    LL y = -1LL;
    for(LL i = A + 1; i <= C; i++) {
        LL c = 0LL;
        if(Z % i != 0) {
            c = Z / gcd(Z, i);
        } else {
            c = Z / i;
        }
        
        LL l = B / c;
        LL r = D / c;
        
        if(l < r) {
            x = i;
            y = c * (l + 1);
            break;
        }
    }

    cout << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
