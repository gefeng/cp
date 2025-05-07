#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    N *= 2;
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            pq.push(A[i]);
            ans += A[i];
        } else {
            if(A[i] > pq.top()) {
                ans += A[i];
                ans -= pq.top();
                pq.pop();
                pq.push(A[i]);
            }
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
