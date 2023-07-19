#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

const LL INF = (LL)2e18;

LL gcd(LL a, LL b) {
    if(a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    LL A, B;
    std::cin >> A >> B;

    if(A < B) {
        std::swap(A, B); 
    }

    if(A == B) {
        std::cout << 1 << '\n';
        return;
    }

    if(A - B == 1LL) {
        std::cout << B << '\n';
        return;
    }

    LL ans = 0LL;
    while(true) {
        LL g = gcd(A, B);
        LL d = A - B;

        LL min_v = INF;
        for(LL f = 1LL; f * f <= d; f++) {
            if(d % f == 0) {
                LL rem1 = A % f;
                LL rem2 = A % (d / f);

                if(f > g && rem1 % g == 0) {
                    min_v = std::min(min_v, rem1); 
                }
                
                if(d / f > g && rem2 % g == 0) {
                    min_v = std::min(min_v, rem2);
                }
            }
        }

        if(min_v == INF) {
            ans += B / g;
            break;
        }

        ans += min_v / g;
        A -= min_v;
        B -= min_v;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
