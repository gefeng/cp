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

    std::vector<std::vector<int>> A(3, std::vector<int>(N, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][N - 1 - j];
        }
    }

    int k = 0;
    while(true) {
        bool read = false;
        for(int i = 0; i < 3; i++) {
            if(!A[i].empty()) {
                int x = A[i].back(); 
                
                if((x | X) == X) {
                    k |= x;
                    read = true; 
                    A[i].pop_back();
                    break;
                }
            }
        }

        if(!read) {
            break; 
        }
    }

    std::cout << (k == X ? "Yes" : "No") << '\n'; 
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
