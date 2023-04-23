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

    auto query = [](int i) {
        std::cout << "? " << i + 1 << std::endl;
        char res;
        std::cin >> res;
        return res;
    };

    auto print = [](int i) {
        std::cout << "! " << i + 1 << std::endl;
    };

    int lo = 0;
    int hi = N - 1;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        char res = query(mid);

        if(res == '0') {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    print(ans);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
