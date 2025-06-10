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

    std::vector<int> first(N + 1, -1);
    std::vector<int> last(N + 1, -1);
    for(int i = 0; i < N; i++) {
        if(first[A[i]] == -1) {
            first[A[i]] = i;
        }
        last[A[i]] = i;
    }

    for(int i = 1; i <= N; i++) {
        if(first[i] != -1 && first[i] + 1 < last[i]) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
