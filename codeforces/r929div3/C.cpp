#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int A, B, L;
    std::cin >> A >> B >> L;
    
    std::set<int> a;
    std::set<int> b;
    for(int64_t f = 1; f <= L; f *= A) {
        a.insert(f);
    }

    for(int64_t f = 1; f <= L; f *= B) {
        b.insert(f);
    }

    auto is_ok = [&](int x) {
        for(int64_t f = 1; f <= x; f *= A) {
            if(x % f == 0 && b.find(x / f) != b.end()) {
                return true;
            }
        }

        for(int64_t f = 1; f <= x; f *= B) {
            if(x % f == 0 && a.find(x / f) != a.end()) {
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    for(int f = 1; f * f <= L; f++) {
        if(L % f == 0) {
            int x = L / f;
            
            if(is_ok(x)) {
                ans += 1;
            }

            if(L / f != f) {
                x = f;
                if(is_ok(x)) {
                    ans += 1;
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
