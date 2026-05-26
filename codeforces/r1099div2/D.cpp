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

    std::string S;
    std::cin >> S;
    
    std::vector<int64_t> A(N);
    std::vector<int64_t> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    if(S[0] == '1' && C[0] != A[0]) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int64_t> ans(N, 0);
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            ans[i] = A[i];
        }
    }

    ans[0] = C[0];
    int64_t max_s = C[0];
    int64_t sum = C[0];
    int pre = 0; 
    for(int i = 1; i < N; i++) {
        if(C[i] < C[i - 1]) {
            std::cout << "NO" << '\n';
            return;
        }

        if(C[i] > C[i - 1]) {
            if(A[i] < 0 || (A[i] == 0 && S[i] == '1')) {
                std::cout << "NO" << '\n';
                return;
            }

            int k = pre + 1;
            while(k <= i && S[k] == '1') {
                k++;
            }
            
            for(int j = pre + 1; j <= i; j++) {
                if(S[j] == '1') {
                    sum += A[j];
                    if(j < i && sum > max_s) {
                        if(k >= j) {
                            std::cout << "NO" << '\n';
                            return;
                        }
                        ans[k] -= sum - max_s;
                        sum = max_s;
                    }
                }
            } 

            if(sum < C[i]) {
                if(S[i] == '0') {
                    ans[i] = C[i] - sum;
                    sum = C[i];
                } else {
                    for(int j = i - 1; j > pre; j--) {
                        if(S[j] == '0') {
                            int64_t d = C[i] - sum;
                            sum = C[i];
                            ans[j] += d;
                            break;
                        }
                    }
                    if(sum != C[i]) {
                        std::cout << "NO" << '\n';
                        return;
                    }
                }
            } else if(sum > C[i]) {
                for(int j = pre + 1; j <= i; j++) {
                    if(S[j] == '0') {
                        ans[j] -= sum - C[i];
                        sum = C[i];
                        break;
                    }
                }
                if(sum != C[i]) {
                    std::cout << "NO" << '\n';
                    return;
                }
            }
            max_s = C[i];
            pre = i;
        } else if(i == N - 1) {
            int k = pre + 1;
            while(k <= i && S[k] == '1') {
                k++;
            }
            for(int j = pre + 1; j <= i; j++) {
                if(S[j] == '1') {
                    sum += A[j];
                    if(sum > max_s) {
                        if(k >= j) {
                            std::cout << "NO" << '\n';
                            return;
                        }
                        ans[k] -= sum - max_s;
                        sum = max_s;
                    }
                }
            } 
        }
    }

    int64_t psum = 0;
    max_s = -static_cast<int64_t>(2e18);
    for(int i = 0; i < N; i++) {
        psum += ans[i];
        max_s = std::max(max_s, psum);
        if(max_s != C[i]) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
