#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);

    for(int i = 1; i < N; i++) {
        int l = i - 1 == 0 ? INF : A[i - 1] - A[i - 2];
        int r = A[i] - A[i - 1];
        psum1[i + 1] = psum1[i] + (r < l ? 1LL : r);
    }

    for(int i = 1; i < N; i++) {
        int j = N - 1 - i;
        int l = A[j + 1] - A[j];
        int r = j + 1 == N - 1 ? INF : A[j + 2] - A[j + 1];
        psum2[i + 1] = psum2[i] + (l < r ? 1LL : l);
    }

    int M;
    std::cin >> M;

    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;

        int64_t ans = 0;
        if(U < V) {
            ans = psum1[V + 1] - psum1[U + 1]; 
        } else {
            ans = psum2[N - V] - psum2[N - U];
        }
        std::cout << ans << '\n';
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
