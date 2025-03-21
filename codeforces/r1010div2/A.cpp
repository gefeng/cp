#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int r = 0;
    int c = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < M; j++) {
            sum ^= A[i][j] - '0'; 
        }
        r += sum;
    }

    for(int i = 0; i < M; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            sum ^= A[j][i] - '0';
        }
        c += sum;
    }

    ans = std::min(r, c);
    r -= ans;
    c -= ans;
    
    ans += (r + c + 1) / 2 * 2;
    
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
