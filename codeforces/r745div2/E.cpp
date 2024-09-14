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
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    int sm = int(std::sqrt(M));
    std::vector<int> when(N, -1);
    std::vector<int> diff(M + 10, 0);
    std::vector<std::vector<int>> freq(sm + 1, std::vector<int>(sm + 1, 0));

    int sum = 0;
    for(int i = 1; i <= M; i++) {
        int T, X;
        std::cin >> T >> X;

        int x = X - 1;
        
        if(T == 1) {
            when[x] = i;
            if(A[x] + B[x] > sm) {
                int t = i + A[x];
                while(t <= M) {
                    diff[t] += 1;
                    diff[std::min(M + 1, t + B[x])] -= 1;
                    t += A[x] + B[x];
                }
            } else {
                for(int t = i + A[x]; t < std::min(M + 1, i + A[x] + B[x]); t++) {
                    freq[A[x] + B[x]][t % (A[x] + B[x])] += 1;
                }
            }
        } else {
            int pre = when[x]; 
            if(A[x] + B[x] > sm) {
                int t = pre + A[x];
                while(t <= M) {
                    if(t < i && t + B[x] >= i) {
                        sum -= 1;
                    }
                    diff[t] -= 1;
                    diff[std::min(M + 1, t + B[x])] += 1;
                    t += A[x] + B[x];
                }
            } else {
                for(int t = pre + A[x]; t < std::min(M + 1, pre + A[x] + B[x]); t++) {
                    freq[A[x] + B[x]][t % (A[x] + B[x])] -= 1;
                }
            }
        }

        sum += diff[i];

        int res = sum;
        for(int j = 2; j <= sm; j++) {
            res += freq[j][i % j];
        }
        
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
