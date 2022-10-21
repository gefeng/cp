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

    vector<LL> div_a;
    vector<LL> div_b;
    div_a.reserve(2000);  // for x in [0, 1e9] there are at most 1344 divisors
    div_b.reserve(2000);

    for(int d = 1; d * d <= A; d++) {
        if(A % d == 0) {
            div_a.push_back(d);
            if(d * d != A) {
                div_a.push_back(A / d);
            }
        }
    }

    for(int d = 1; d * d <= B; d++) {
        if(B % d == 0) {
            div_b.push_back(d);
            if(d * d != B) {
                div_b.push_back(B / d);
            }
        }
    }

    for(LL d_a : div_a) {
        for(LL d_b : div_b) {
            LL d_ab_1 = d_a * d_b;
            LL d_ab_2 = A * B / d_ab_1;

            LL x = C / d_ab_1 * d_ab_1;
            LL y = D / d_ab_2 * d_ab_2;
            if(x > A && y > B) {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
    }

    cout << -1 << ' ' << -1 << '\n';
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
