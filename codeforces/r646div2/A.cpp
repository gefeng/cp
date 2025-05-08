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
    int cnt_eve = 0;
    int cnt_odd = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
        cnt_odd += A[i] % 2;
    }

    cnt_eve = N - cnt_odd;
    
    if(cnt_odd == 0) {
        std::cout << "No" << '\n';
        return;
    }

    X -= 1;
    cnt_odd -= 1;
    
    int d = std::min(cnt_odd / 2 * 2, X / 2 * 2);
    X -= d;

    d = std::min(cnt_eve, X);
    X -= d;

    std::cout << (X == 0 ? "Yes" : "No") << '\n';    
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
