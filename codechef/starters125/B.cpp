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

    int parity = 0;
    int cnt_one = 0;
    for(int x : A) {
        if(x == 1) {
            cnt_one += 1;
        } else {
            parity += x;
            parity %= 2;
        }
    }

    if(cnt_one % 2 == 0) {
        if(cnt_one == N) {
            std::cout << "Draw" << '\n';
        } else {
            std::cout << (parity ? "Alice" : "Bob") << '\n'; 
        }
    } else {
        if(parity == 0) {
            std::cout << "Alice" << '\n';
        } else {
            std::cout << (N - cnt_one == 1 ? "Draw" : "Bob") << '\n';
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
