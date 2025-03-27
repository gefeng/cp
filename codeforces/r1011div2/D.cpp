#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int64_t ans = 0;
    std::priority_queue<int> pq;
    
    for(int i = 1; i <= N; i++) {
        pq.push(A[i - 1]);
        if((N - i + 1) % (K + 1) == 0) {
            ans += pq.top();
            pq.pop();
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
