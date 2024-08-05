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

    std::vector<std::vector<int>> A(N, std::vector<int>(5));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            std::cin >> A[i][j];
        }
    }

    int winner = 0;
    for(int i = 1; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < 5; j++) {
            if(A[winner][j] < A[i][j]) {
                cnt += 1;
            } 
        }
        if(cnt < 3) {
            winner = i;
        }
    }

    for(int i = 0; i < N; i++) {
        if(i == winner) {
            continue;
        }
        int cnt = 0;
        for(int j = 0; j < 5; j++) {
            if(A[winner][j] < A[i][j]) {
                cnt += 1;
            }
        }

        if(cnt < 3) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << winner + 1 << '\n';
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
