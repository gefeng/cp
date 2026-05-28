#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]]++;
    }

    int max_f = 0;
    for(auto [_, f] : m) {
        max_f = std::max(max_f, f);
    }

    std::cout << (N - max_f + 1) << '\n';
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
