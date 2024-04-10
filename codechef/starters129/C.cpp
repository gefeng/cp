#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S;
    std::cin >> N >> S;

    if(N == 1 || S % 2 == 1 || S < N) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> A(N, 0);
    if(N % 2 == 0) {
        for(int i = 0; i < N - 2; i++) {
            A[i] = 1;
        }

        A[N - 2] = (S - N + 2) / 2;
        A[N - 1] = (S - N + 2) / 2;
    } else {
        if(N > 3) {
            if(S - 6 < N - 3) {
                std::cout << -1 << '\n';
                return;
            }
            A[0] = 1;
            A[1] = 2;
            A[2] = 3;
            for(int i = 3; i < N - 2; i++) {
                A[i] = 1;
            }
            A[N - 2] = (S - 6 - (N - 5)) / 2;
            A[N - 1] = (S - 6 - (N - 5)) / 2;
        } else {
            int s = S / 2;
            A[0] = s;
            for(int i = 0; i < 30; i++) {
                if(s & (1 << i)) {
                    if(A[1] == 0) {
                        A[1] |= 1 << i;
                    } else {
                        A[2] |= 1 << i;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            std::cout << -1 << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " \n"[i == N - 1];
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
