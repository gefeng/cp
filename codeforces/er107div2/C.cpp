#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 50;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    std::vector<int> pos(MAX + 1, -1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(pos[A[i]] == -1) {
            pos[A[i]] = i;
        } 
    }

    for(int i = 0; i < Q; i++) {
        int C;
        std::cin >> C;
        
        int j = pos[C];
        std::cout << j + 1 << " \n"[i == Q - 1];
    
        pos[C] = 0;
        for(int k = 1; k <= MAX; k++) {
            if(pos[k] != -1 && k != C && pos[k] < j) {
                pos[k] += 1; 
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
