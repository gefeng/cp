#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

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

    std::sort(B.begin(), B.end());
    
    std::multiset<int> ms;
    for(int i = 0; i < N; i++) {
        ms.insert(A[i]); 
    }

    int64_t ans = 0;
    for(int i = 0; i < M; i++) {
        auto it = ms.lower_bound(B[i]);
        if(it == ms.end()) {
            ans = -1;
            break;
        }

        ans += *it;
        ms.erase(it);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
