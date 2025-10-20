#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    auto query = [](int t, int l, int r) {
        std::cout << t << ' ' << l + 1 << ' ' << r + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int x = query(1, 0, N - 1);
    int y = query(2, 0, N - 1);
    int len = y - x;

    int lo = 0;
    int hi = N - len;
    int l = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
    
        x = query(1, mid, N - 1);
        y = query(2, mid, N - 1);

        if(y - x == len) {
            l = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << "! " << l + 1 << ' ' << l + len << std::endl;
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
