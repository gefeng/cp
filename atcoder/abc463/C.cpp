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
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    int Q;
    std::cin >> Q;
    std::vector<std::pair<int, int>> B(Q);

    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
        B[i] = {X, i};
    }

    std::ranges::sort(B);

    std::vector<int> ans(Q);
    
    std::multiset<int> ms;
    for(auto [h, _] : A) {
        ms.insert(h);
    }

    for(int i = 0, j = 0; i < Q; i++) {
        while(j < N && A[j].second <= B[i].first) {
            ms.erase(ms.find(A[j].first));
            j++;
        }
        ans[B[i].second] = *ms.rbegin();
    }

    for(int i = 0; i < Q; i++) {
        std::cout << ans[i] << '\n';
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
