#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S;
    std::cin >> N >> S;

    std::vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    if(sum > S) {
        for(int i = 0; i < N; i++) {
            std::cout << A[i] << " \n"[i == N - 1];
        }
        return;
    }

    if(S == sum) {
        std::cout << -1 << '\n';
        return;
    }
    
    S -= sum;
    
    if(S != 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::array<int, 3> a = {0, 2, 1};
    std::vector<int> ans;
    for(int x = 0; x < 3; x++) {
        for(int i = 0; i < N; i++) {
            if(A[i] == a[x]) {
                ans.push_back(A[i]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
