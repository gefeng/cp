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
    int M, X;
    std::cin >> M >> X;
    
    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int bal = 0;
    std::priority_queue<int> pq;
    for(int i = 0; i < M; i++) {
        if(A[i] <= bal) {
            pq.push(A[i]);
            bal -= A[i];
        } else {
            if(!pq.empty() && pq.top() > A[i]) {
                int x = pq.top();
                pq.pop();
                bal += x - A[i];
                pq.push(A[i]);
            }
        }

        ans = std::max(ans, (int)pq.size());
        bal += X;
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
