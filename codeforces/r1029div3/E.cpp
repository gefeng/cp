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
    std::vector<int> B(N);
    std::vector<std::vector<int>> pos_a(N + 1);
    std::vector<std::vector<int>> pos_b(N + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos_a[A[i]].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        pos_b[B[i]].push_back(i);
    }

    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == B[i]) {
            ans = i + 1;
            break;
        }

        if((!pos_a[B[i]].empty() && pos_a[B[i]].back() > i && pos_a[B[i]].back() - i > 1) || (!pos_b[B[i]].empty() && pos_b[B[i]].back() > i) || 
                (!pos_a[A[i]].empty() && pos_a[A[i]].back() > i) || (!pos_b[A[i]].empty() && pos_b[A[i]].back() > i && pos_b[A[i]].back() - i > 1)) {
            ans = i + 1;
            break;
        }
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
