#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using LL = unsigned long long;

constexpr LL MAX = (LL)1e18;

std::set<LL> save;

void run_case() {
    LL N;
    std::cin >> N;

    if(save.find(N) != save.end()) {
        std::cout << "YES" << '\n';
        return;
    }

    int64_t c = (int64_t)1 - (int64_t)4 * (1 - N);
    int64_t sc = (int64_t)sqrt(c);

    if(sc * sc == c) {
        if((sc - 1) % 2 == 0 && (-sc - 1) % 2 == 0) {
            int64_t x = (sc - 1) / 2;
            int64_t y = (-sc - 1) / 2;
            if(x > 1 || y > 1) {
                std::cout << "YES" << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(LL k = 2; k <= 1e6; k++) {
        LL sum = 1 + k;
        if(sum >= MAX) {
            break;
        }

        LL x = k;
        while(true) {
            if(x >= (MAX + k - 1) / k) {
                break;
            }
            
            x *= k;
            if(sum + x > MAX) {
                break;
            }

            sum += x;
            save.insert(sum);
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
