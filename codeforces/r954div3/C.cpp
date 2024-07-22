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
    
    std::string S;
    std::cin >> S;
    
    std::vector<int> A(M);
    std::vector<int> B(M);
    std::vector<int> change_to(N, -1);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];     
        A[i] -= 1;
    }

    for(int i = 0; i < M; i++) {
        char C;
        std::cin >> C;
        B[i] = C - 'a';
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    for(int i = 0, p = 0; i < M; ) {
        int j = i;
        while(i < M && A[i] == A[j]) {
            i += 1;
        }
        S[A[j]] = (char)(B[p++] + 'a');
    }
    
    std::cout << S << '\n';
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
