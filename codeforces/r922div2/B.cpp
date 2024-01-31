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
 
    std::vector<std::pair<int, int>> A(N);
 
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }
 
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }
 
    std::sort(A.begin(), A.end());
 
    for(int i = 0; i < N; i++) {
        std::cout << A[i].first << " \n"[i == N - 1];
    } 
 
    for(int i = 0; i < N; i++) {
        std::cout << A[i].second << " \n"[i == N - 1];
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
