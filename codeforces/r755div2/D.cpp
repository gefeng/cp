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
    int N;
    std::cin >> N;
    
    auto query = [](int l, int r) {
        std::cout << "? " << l << ' ' << r << std::endl;
        int64_t Q;
        std::cin >> Q;
        return Q;
    };

    auto check = [](int64_t x) {
        int64_t sqr = sqrtl(x);   
        if(sqr * sqr == x) {
            return int64_t(-1);
        }
        if(sqr * (sqr + 1) == x) {
            return sqr + 1;
        }
        if(sqr * (sqr - 1) == x) {
            return sqr;
        }
        return int64_t(-1);
    };

    int64_t tot = query(1, N);

    int lo = 1;
    int hi = N;
    int i = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int64_t q = query(1, mid);
        if(q == 0) {
            i = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    int j = tot - query(i + 1, N) + i + 1;
    int k = check((tot - int64_t(j - i - 1) * (j - i) / 2) * 2) + j - 1;
    
    std::cout << "! " << i << ' ' << j << ' ' << k << std::endl;
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
