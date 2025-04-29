#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int ans = 0;
    if(X * 2 <= Y) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(A[i][j] == '.') {
                    ans += X;              
                }
            }
        }
    } else {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; ) {
                if(A[i][j] == '*') {
                    j += 1;
                    continue;
                }

                int k = j;
                while(j < M && A[i][j] == '.') {
                    j += 1;
                }
                ans += (j - k) / 2 * Y + ((j - k) % 2) * X;
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
