#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, L;
    std::cin >> N >> L;
    
    if(L >= 2000) {
        for(int i = 0; i < N; i++) {
            std::cout << i + 1 << " \n"[i == N - 1];
        } 
    } else {
        for(int i = 0, x = L; i < N; i++, x += 2000) {
            std::cout << x << " \n"[i == N - 1];
        }
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
