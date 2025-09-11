#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int K;
    int64_t X;
    std::cin >> K >> X;

    int64_t tot = static_cast<int64_t>(1) << (K + 1);
    int64_t a = X;
    int64_t b = tot - X;
    
    std::vector<int> seq;
    while(a != b) {
        if(a * 2 >= tot) {
            a -= b;
            b *= 2;
            seq.push_back(2);
        } else {
            b -= a;
            a *= 2;
            seq.push_back(1);
        }
    }

    std::ranges::reverse(seq);

    int n = seq.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << seq[i] << " \n"[i == n - 1];
    }
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
