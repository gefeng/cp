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
        for(int j = 0; j <= i; j++) {
            int X;
            std::cin >> X;
            A[i].push_back(X);
        }
    } 

    int x = 1;
    for(int i = 1; i <= N; i++) {
        if(x >= i) {
            x = A[x - 1][i - 1];
        } else {
            x = A[i - 1][x - 1];
        }
    }

    std::cout << x << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
