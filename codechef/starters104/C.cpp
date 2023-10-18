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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N);
    std::vector<int> freq(M + 1, 0);
    int max_f = 0;
    for(int i = 0; i < N; i++) {
        if(freq[A[i]] >= max_f) {
            int min_f = N + 1;
            int k = -1;
            for(int j = 1; j <= M; j++) {
                if(freq[j] < min_f) {
                    min_f = freq[j];
                    k = j;
                } 
            } 

            if(min_f == freq[A[i]]) {
                freq[A[i]] += 1;
                ans[i] = A[i];
                max_f = std::max(max_f, freq[A[i]]);
            } else {
                freq[k] += 1;
                ans[i] = k;
                max_f = std::max(max_f, freq[k]);
            }
        } else {
            freq[A[i]] += 1;
            ans[i] = A[i];
            max_f = std::max(max_f, freq[A[i]]);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
