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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, -1);
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        if(m.find(A[i]) != m.end()) {
            ans[i] = m[A[i]] + 1;
        }
        m[A[i]] = i;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
