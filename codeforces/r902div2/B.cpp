#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, P;
    std::cin >> N >> P;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; i++) {
        a.emplace_back(A[i], B[i]);
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                if(x.second == y.second) {
                    return x.first > y.first;
                }
                return x.second < y.second;
            });

    int64_t ans = P;
    for(int i = 0, j = N - 1; i < N && j; i++) {
        if(a[i].second <= P) {
            int d = std::min(j, a[i].first); 
            j -= d;
            ans += (int64_t)d * a[i].second;
        } else {
            ans += (int64_t)j * P;
            break;
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
