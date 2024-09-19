#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> family(N + 1, 0);
    for(int i = 0; i < M; i++) {
        int A;
        char B;
        std::cin >> A >> B;
        
        if(B == 'M' && family[A] == 0) {
            std::cout << "Yes" << '\n';
            family[A] = 1;
        } else {
            std::cout << "No" << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
