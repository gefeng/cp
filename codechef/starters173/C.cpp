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

    if(M == 1) {
        for(int i = 0; i < N; i++) {
            if(A[i] > B[0]) {
                A[i] = B[0];
            }
        }
    } else {
        int p = std::min_element(B.begin(), B.end()) - B.begin();

        std::vector<int> b;
        for(int i = p; i < M; i++) {
            b.push_back(B[i]);
        }

        for(int i = 0; i < p; i++) {
            b.push_back(B[i]);
        }

        bool replaced = false;
        for(int i = 0; i <= N - M; i++) {
            if(A[i] > b[0]) {
                replaced = true;
                for(int j = i; j <= N - M; j++) {
                    A[j] = b[0];
                }
                for(int j = N - M + 1, k = 1; j < N; j++, k++) {
                    A[j] = b[k];
                }
                break;
            }
        }

        if(!replaced) {
            for(int i = N - M, j = 0; i < N && j < M; i++, j++) {
                if(A[i] == b[j]) {
                    continue;
                }
                if(A[i] > b[j]) {
                    for(int k = 0; k < M; k++) {
                        A[N - M + k] = b[k];
                    }
                }
                break;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " \n"[i == N - 1];
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
