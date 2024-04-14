#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        while(true) {
            auto it = std::upper_bound(A.begin(), A.end(), X - 1);
            int remove = it - A.begin(); 
            if(remove == 0) {
                break;
            }
            X -= remove;
        }
        std::cout << X << " \n"[i == Q - 1];
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
