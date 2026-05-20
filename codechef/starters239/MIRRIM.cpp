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

    int x1 = A[N / 2 - 1];
    int x2 = A[N / 2];
    
    bool ans = true;
    for(int i = 0; i < N / 2 - 1; i++) {
        if(x1 - A[i] != A[N - 1 - i] - x2) {
            ans = false;
            break;
        } 
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
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
