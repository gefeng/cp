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
    int first = -1;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] > 1) {
            first = first == -1 ? i : first;
        }
    }

    if(first == -1) {
        std::cout << (N % 2 == 1 ? "First" : "Second") << '\n';
        return;
    } 

    std::cout << (first % 2 == 0 ? "First" : "Second") << '\n';
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
