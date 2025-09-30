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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> seen(N + 1, 0);
    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] == -1) {
            continue;
        }
        if(seen[A[i]]) {
            std::cout << "No" << '\n';
            return;
        }
        seen[A[i]] = 1;
        ans[i] = A[i];
    }

    std::cout << "Yes" << '\n';
    for(int i = 0, j = 1; i < N; i++) { 
        if(ans[i] == 0) {
            while(j <= N && seen[j]) {
                j += 1;
            }
            ans[i] = j++;
        }
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
