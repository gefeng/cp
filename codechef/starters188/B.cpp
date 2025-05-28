#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> std::get<0>(A[i]);
        std::get<2>(A[i]) = i;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> std::get<1>(A[i]);
    }

    std::sort(A.begin(), A.end());
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::vector<int64_t> ans(N);
    int64_t sum = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && std::get<0>(A[i]) == std::get<0>(A[j])) {
            i += 1;
        }
        
        for(int k = j; k < i; k++) {
            ans[std::get<2>(A[k])] = sum;
        }

        for(int k = j; k < i; k++) {
            pq.push(std::get<1>(A[k]));
            sum += std::get<1>(A[k]);
        }

        while(pq.size() > K) {
            sum -= pq.top();
            pq.pop();
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
