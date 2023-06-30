#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> v;
    for(int i = 0; i < N; i++) {
        if(N - 1 - i >= K || i >= K) {
            v.push_back(A[i]);
        }
    }

    std::sort(v.begin(), v.end());

    std::vector<int> ans(N, 0);
    for(int i = 0, j = 0; i < N; i++) {
        if(N - 1 - i >= K || i >= K) {
            ans[i] = v[j++];
        } else {
            ans[i] = A[i];
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
