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
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] <= B[i]) {
            continue;
        }
        int p = -1;
        for(int j = i + 1; j < N; j++) {
            if(A[j] <= B[i]) {
                p = j;
                break;
            }
        }

        if(p == -1) {
            std::cout << -1 << '\n';
            return;
        }

        int t = A[p];
        for(int j = p; j > i; j--) {
            A[j] = A[j - 1];
        }
        A[i] = t;
        ans += p - i;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
