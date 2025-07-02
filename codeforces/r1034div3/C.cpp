#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string ans(N, '0');
    int x = *std::min_element(A.begin(), A.end());
    int y = *std::max_element(A.begin(), A.end());

    std::vector<int> max_v(N, -1);
    for(int i = N - 2; i >= 0; i--) {
        max_v[i] = std::max(max_v[i + 1], A[i + 1]);
    }

    int min_v = INF;
    for(int i = 0; i < N; i++) {
        if(i) {
            min_v = std::min(min_v, A[i - 1]);
        }
        if(i == 0 || i == N - 1) {
            ans[i] = '1';
        } else {
            if((A[i] < min_v && A[i] < max_v[i]) || (A[i] > min_v && A[i] > max_v[i]) || (A[i] < min_v && A[i] > max_v[i]) || A[i] == x || A[i] == y) {
                ans[i] = '1';
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
