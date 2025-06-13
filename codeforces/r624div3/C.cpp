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
    std::vector<int> diff(N + 1, 0);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        diff[0] += 1;
        diff[A[i]] -= 1;
    }

    std::array<int, 26> freq = {};
    for(int i = 0; i < N; i++) {
        freq[S[i] - 'a'] += 1;
    }
    
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += diff[i]; 
        freq[S[i] - 'a'] += sum;
    }

    for(int i = 0; i < 26; i++) {
        std::cout << freq[i] << " \n"[i == 25];
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
