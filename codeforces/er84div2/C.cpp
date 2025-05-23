#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> A(K);
    std::vector<std::pair<int, int>> B(K);

    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
    }
    
    for(int i = 0; i < K; i++) {
        std::cin >> B[i].first >> B[i].second;
    }
    
    std::string ans = "";
    for(int i = 0; i < N - 1; i++) {
        ans.push_back('U');
    }

    for(int i = 0; i < M - 1; i++) {
        ans.push_back('L');
    }

    for(int i = 0, j = 0; i < N; i++, j ^= 1) {
        if(j == 0) {
            for(int k = 0; k < M - 1; k++) {
                ans.push_back('R');
            }
        } else {
            for(int k = 0; k < M - 1; k++) {
                ans.push_back('L');
            }
        }

        if(i != N - 1) {
            ans.push_back('D');
        }
    }    
    
    int size = ans.size();
    assert(size < 2 * N * M);
    std::cout << size << '\n';
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
