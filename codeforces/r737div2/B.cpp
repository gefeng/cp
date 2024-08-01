#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> s(A);
    std::sort(s.begin(), s.end());

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && A[i + 1] > A[i]) {
            auto it = std::lower_bound(s.begin(), s.end(), A[i + 1]);
            it--;
            if(*it != A[i]) {
                break;
            }
            i += 1;
        }

        a.emplace_back(A[j], A[i]); 
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                return x.first < y.first;
            });

    int n = a.size();
    for(int i = 1; i < n; i++) {
        if(a[i].first < a[i - 1].second) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << (n <= K ? "YES" : "NO") << '\n';
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
