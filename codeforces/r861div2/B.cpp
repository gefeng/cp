#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0)); 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    LL ans = 0LL;
    for(int i = 0; i < M; i++) {
        std::vector<int> col(N);
        for(int j = 0; j < N; j++) {
            col[j] = A[j][i]; 
        }

        sort(col.begin(), col.end());

        LL sum = 0LL;
        for(int j = 0; j < N; j++) {
            ans += 1LL * j * col[j] - sum;
            sum += col[j];
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
