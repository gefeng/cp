#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(3e5);

std::vector<int> xor_sum(MAX + 2, 0);

void run_case() {
    int A, B;
    std::cin >> A >> B;

    int ans = A;
    int sum = xor_sum[A];;

    sum ^= B;
    if(sum) {
        ans += sum == A ? 2 : 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        xor_sum[i + 1] = xor_sum[i] ^ i;
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
