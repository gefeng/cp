#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                if(x.first == y.first) {
                    return x.second > y.second;
                }
                return x.first > y.first;
            });

    int ans = 0;
    int now = N;
    for(int i = 0; i < N; i++) {
        if(A[i].second < now) {
            now = A[i].second;
            ans += 1;
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
