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

    std::vector<int> L(N);
    std::vector<int> R(N);
    std::vector<int> W(N);
    for(int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> R[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> W[i];
    }

    std::sort(L.begin(), L.end());
    std::sort(R.begin(), R.end());
    std::sort(W.begin(), W.end(), std::greater<int>());

    std::set<int> s;
    std::vector<std::pair<int, int>> a;
    for(int i = N - 1, j = N - 1; i >= 0; i--) {
        while(j >= 0 && R[j] > L[i]) {
            s.insert(R[j--]); 
        } 

        a.emplace_back(L[i], *s.begin()); 
        s.erase(s.begin());
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                return x.second - x.first < y.second - y.first;
            });

    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += (int64_t)(a[i].second - a[i].first) * W[i];
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
