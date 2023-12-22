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
    std::vector<std::pair<int, int>> B(N);
    std::vector<std::pair<int, int>> C(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i].first;
        B[i].second = i;
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> C[i].first;
        C[i].second = i;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());
    std::sort(B.begin(), B.end(), std::greater<std::pair<int, int>>());
    std::sort(C.begin(), C.end(), std::greater<std::pair<int, int>>());

    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(A[i].second != B[j].second && A[i].second != C[k].second && B[j].second != C[k].second) {
                    ans = std::max(ans, A[i].first + B[j].first + C[k].first);
                }
            }
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
