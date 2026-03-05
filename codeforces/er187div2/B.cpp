#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int64_t X;
    std::cin >> X;
    
    std::vector<int> d;
    while(X) {
        d.push_back(X % 10);
        X /= 10;
    }

    int sum = std::accumulate(d.begin(), d.end(), 0);

    d.back() -= 1;
    std::ranges::sort(d);
    
    int p = d.size() - 1;
    int ans = 0;
    while(sum > 9) {
        sum -= d[p--];
        ans += 1;
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
