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

    std::vector<int> sorted(A);
    std::sort(sorted.begin(), sorted.end());

    int mex = 0;
    for(int i = 0; i < N; i++) {
        if(sorted[i] == mex) {
            mex += 1;
        } else {
            break;
        }
    }

    std::vector<int> a(A);
    a.push_back(mex);
    std::vector<int> ans(N + 1); 
    for(int i = 0; i < N + 1; i++) {
        ans[(i + K) % (N + 1)] = a[i];
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
