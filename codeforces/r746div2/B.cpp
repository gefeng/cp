#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(2 * X - N <= 0) {
        std::cout << "YES" << '\n';
        return;
    }

    if(N == X) {
        for(int i = 1; i < N; i++) {
            if(A[i] < A[i - 1]) {
                std::cout << "NO" << '\n';
                return;
            } 
        }
        std::cout << "YES" << '\n';
        return;
    }
   
    for(int i = N - X + 1; i < X; i++) {
        if(A[i] < A[i - 1]) {
            std::cout << "NO" << '\n';
            return;
        } 
    }

    std::vector<int> a;
    for(int i = 0; i < N - X; i++) {
        a.push_back(A[i]);
        a.push_back(A[N - 1 - i]);
    }
    
    std::sort(a.begin(), a.end());
    
    std::cout << (A[N - X] >= a[N - X - 1] && A[X - 1] <= a[N - X] ? "YES" : "NO") << '\n';
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
