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

    std::sort(A.begin(), A.end());

    std::vector<int> ans;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] > sum) {
            sum += A[i];
            ans.push_back(A[i]);
            A[i] = -1;
        }
    }

    std::cout << N - ans.size() << '\n';

    for(int i = 0; i < N; i++) {
        if(A[i] != -1) {
            ans.push_back(A[i]);
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
