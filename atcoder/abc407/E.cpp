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

    std::vector<int> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    std::priority_queue<int> pq;
    int64_t ans = 0;
    for(int i = 0; i < N * 2; i++) {
        pq.push(A[i]);

        if(i % 2 == 0) {
            ans += pq.top();
            pq.pop();
        }
    }

    std::cout << ans << '\n';
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
