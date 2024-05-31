#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N + M + 1);
    std::vector<int> B(N + M + 1);
    for(int i = 0; i < N + M + 1; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N + M + 1; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> ans(N + M + 1, 0);
    int p = -1;
    int cnt_p = 0;
    int cnt_t = 0;
    int64_t sum = 0;
    for(int i = 0; i < N + M; i++) {
        if(A[i] > B[i]) {
            if(cnt_p < N) {
                sum += A[i]; 
                cnt_p += 1;
            } else {
                sum += B[i];
                cnt_t += 1;
                if(p == -1) {
                    p = i;
                }
            }
        } else {
            if(cnt_t < M) {
                sum += B[i];
                cnt_t += 1;
            } else {
                sum += A[i];
                cnt_p += 1;
                if(p == -1) {
                    p = i;
                }
            }
        }
    }
    p = p == -1 ? N + M : p;

    ans[N + M] = sum;
    for(int i = 0; i < M + N; i++) {
        if(p == N + M) {
            if(A[i] > B[i]) {
                ans[i] = sum - A[i] + A.back();
            } else {
                ans[i] = sum - B[i] + B.back();
            }
            continue;
        } 

        if(A[i] > B[i]) {
            if(i < p) {
                if(A[p] > B[p]) {
                    ans[i] = sum + B.back() - A[i] + A[p] - B[p];
                } else {
                    ans[i] = sum + A.back() - A[i];
                }
            } else {
                if(A[p] > B[p]) {
                    ans[i] = sum + B.back() - B[i];
                } else {
                    ans[i] = sum + A.back() - A[i];
                }
            }
        } else {
            if(i < p) {
                if(A[p] < B[p]) {
                    ans[i] = sum + A.back() - B[i] + B[p] - A[p];
                } else {
                    ans[i] = sum + B.back() - B[i];
                }
            } else {
                if(A[p] < B[p]) {
                    ans[i] = sum + A.back() - A[i];
                } else {
                    ans[i] = sum + B.back() - B[i];
                }
            }
        }
    }

    for(int i = 0; i < N + M + 1; i++) {
        std::cout << ans[i] << " \n"[i == N + M];
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
