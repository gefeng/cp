#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<std::pair<int, int>> min_a(N);
    min_a[0] = {A[0], 0};
    for(int i = 1; i < N; i++) {
        if(A[i] < min_a[i - 1].first) {
            min_a[i] = {A[i], i};
        } else {
            min_a[i] = min_a[i - 1];
        }
    }

    auto bs = [&](int b) {
        int lo = 0;
        int hi = N - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
        
            if(min_a[mid].first > b) {
                lo = mid + 1;
            } else {
                res = min_a[mid].second;
                hi = mid - 1;
            }
        }

        return res;
    };

    for(int i = 0; i < M; i++) {
        int j = bs(B[i]);
        std::cout << (j == - 1 ? -1 : j + 1) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
