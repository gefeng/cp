#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e7;
constexpr int MAX_D = 63;

std::vector<std::vector<int>> f(MAX_D + 1);

void run_case() {
    int N;
    std::cin >> N;

    std::array<int, 10> a = {};
    a[0] = 1;
    for(int i = 1; i < 10; i++) {
        a[i] = a[i - 1] + i + 1;
    }

    int n = N;
    int64_t ans = 1;
    while(n) {
        ans *= a[n % 10];
        n /= 10;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 0; i <= MAX; i++) {
        int x = i;
        int sum = 0;
        while(x) { 
            sum += x % 10;
            x /= 10;
        }
        f[sum].push_back(i);
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
