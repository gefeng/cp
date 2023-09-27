#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::vector<int> A(K);
    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    int Q;
    std::cin >> Q;
    std::vector<int> diff(N + 1, 0);
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
        X -= 1;

        int p = std::upper_bound(A.begin(), A.end(), X) - A.begin() - 1;
        int l = std::min(X, B[p] + A[p] - X);
        int r = std::max(X, B[p] + A[p] - X);
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += diff[i];
        int p = std::upper_bound(A.begin(), A.end(), i) - A.begin() - 1;
        int l = A[p];
        int r = B[p];
        
        if(i <= (l + r) / 2 && sum % 2 == 1) {
            std::swap(S[i], S[l + r - i]); 
        }
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
