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
    std::vector<int> seen(N + 1, 0);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];

        if(seen[A[i]]) {
            cnt += 1;
        }
        seen[A[i]] = 1;
    }

    std::cout << cnt << '\n';
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
