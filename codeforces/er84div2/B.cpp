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

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
            A[i][j] -= 1;
        }
    }

    std::vector<int> picked(N, 0);
    std::vector<int> done(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j : A[i]) {
            if(!picked[j]) {
                picked[j] = 1;
                done[i] = 1;
                break;
            }
        }
    }

    int p = -1;
    for(int i = 0; i < N; i++) {
        if(!picked[i]) {
            p = i;
            break;
        }
    }

    if(p == -1) {
        std::cout << "OPTIMAL" << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!done[i]) {
            std::cout << "IMPROVE" << '\n';
            std::cout << i + 1 << ' ' << p + 1 << '\n';
            return;
        }
    }

    std::cout << "OPTIMAL" << '\n';
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
