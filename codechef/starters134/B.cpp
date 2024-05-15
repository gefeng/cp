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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> B(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> B[i].first;
        B[i].second = i;
    }

    std::sort(B.begin(), B.end());
    
    std::priority_queue<int> pq1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;
    std::vector<int64_t> ans(Q);
    int p = 0;
    int64_t sum_l = 0;
    int64_t sum_r = 0;
    for(auto [k, i] : B) {
        while(p < k) {
            int x = A[p++];
            pq2.push(x);
            sum_r += x;
            
            while(pq2.size() - pq1.size() > 1) {
                int y = pq2.top();
                pq2.pop();
                sum_r -= y;
                sum_l += y;
                pq1.push(y);
            }

            while(!pq1.empty() && !pq2.empty() && pq1.top() > pq2.top()) {
                int y = pq1.top();
                int z = pq2.top();
                pq1.pop();
                pq2.pop();
                sum_l -= y;
                sum_r -= z;
                pq1.push(z);
                pq2.push(y);
                sum_l += z;
                sum_r += y;
            }
        } 

        ans[i] = sum_r - sum_l;
    }

    for(int i = 0; i < Q; i++) {
        std::cout << ans[i] << " \n"[i == Q - 1];
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
