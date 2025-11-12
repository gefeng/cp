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

    std::vector<int> A(N);
    std::vector<int> pos(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]] = i;
    }

    std::string S;
    std::cin >> S;

    if(S[0] == '1' || S.back() == '1' || S[pos[1]] == '1' || S[pos[N]] == '1') {
        std::cout << -1 << '\n';
        return;
    }
    
    std::cout << 5 << '\n';
    std::cout << 1 << ' ' << pos[1] + 1 << '\n';
    std::cout << pos[1] + 1 << ' ' << N << '\n';
    std::cout << 1 << ' ' << pos[N] + 1 << '\n';
    std::cout << pos[N] + 1 << ' ' << N << '\n';
    std::cout << std::min(pos[1], pos[N]) + 1 << ' ' << std::max(pos[1], pos[N]) + 1 << '\n';
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
