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
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == 2) {
            cnt += 1;
        }
    }

    if(cnt % 2 == 0) {
        std::cout << ((N - cnt) % 2 == 0 ? "YES" : "NO") << '\n';
    } else {
        std::cout << (N - cnt < 2 || (N - cnt - 2) % 2 == 1 ? "NO" : "YES") << '\n';
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
