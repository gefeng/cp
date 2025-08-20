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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int n = 50;
    std::vector<std::string> ans(N + 1, std::string(n, 'a'));
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < A[i - 1]; j++) {
            ans[i][j] = ans[i - 1][j];
        }
        if(A[i - 1] < n) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(c != ans[i - 1][A[i - 1]]) {
                    ans[i][A[i - 1]] = c;
                    break;
                }
            }
        }
    }

    for(int i = 0; i <= N; i++) {
        std::cout << ans[i] << '\n';
    }
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
