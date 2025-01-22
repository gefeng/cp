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

    bool inc = true;
    for(int i = 0; i < N - 1; i++) {
        if(A[i + 1] < A[i]) {
            inc = false; 
        }
    }

    if(inc) {
        std::cout << "Yes" << '\n';
        return;
    }

    for(int i = 0; i < N - 1; i++) {
        int d = std::min(A[i], A[i + 1]);
        A[i] -= d;
        A[i + 1] -= d;
    }

    inc = true;
    for(int i = 0; i < N - 1; i++) {
        if(A[i + 1] < A[i]) {
            inc = false;
        }
    }

    std::cout << (inc ? "Yes" : "No") << '\n';
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
