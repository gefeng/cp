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

    std::vector<int> A(N);
    std::vector<int> B(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    int j = 0;
    std::vector<int> first(M, 0); 
    std::vector<int> last(M, 0);
    for(int i = 0; i < N && j < M; i++) {
        if(A[i] == B[j]) {
            first[j] = i;
            j += 1;
        }
    }

    if(j != M) {
        std::cout << "No" << '\n';
        return;
    }
    
    j = M - 1;
    for(int i = N - 1; i >= 0 && j >= 0; i--) {
        if(A[i] == B[j]) {
            last[j] = i;
            j -= 1;
        }
    }

    for(int i = 0; i < M; i++) {
        if(first[i] != last[i]) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
