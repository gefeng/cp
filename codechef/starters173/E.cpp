#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <set>

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

    if(N == 1) {
        for(int i = 0; i < M; i++) {
            if(B[i] == A[0]) {
                std::cout << -1 << '\n';
                return;
            }
        }
        std::cout << 1 << '\n' << A[0] << '\n';
        return;
    }

    bool unique = true;
    for(int i = 0; i < N; i++) {
        if(A[i] != A[0]) {
            unique = false;
            break;
        }
    }

    if(unique) {
        for(int i = 0; i < M; i++) {
            if(A[0] == B[i]) {
                std::cout << -1 << '\n';
                return;
            }
        }
        std::cout << 1 << '\n' << A[0] << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(A[i] % 2 != A[0] % 2) {
            std::cout << 2 << '\n' << A[0] << ' ' << A[i] << '\n';
            return;
        }
    }

    std::set<int> s(B.begin(), B.end());
    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    if(sum % N != 0 || s.find(sum / N) == s.end()) {
        std::cout << N << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << A[i] << " \n"[i == N - 1];
        }
        return;
    }

    if(N >= 18) {
        std::vector<int> a;
        bool unique = true;
        for(int i = 0; i < N; i++) {
            if(a.size() + 1 < 18) {
                a.push_back(i);
                if(A[i] != A[0]) {
                    unique = false;
                }
            } else {
                if(!unique) {
                    a.push_back(i);
                    break;
                } else {
                    if(A[i] != A[0]) {
                        a.push_back(i);
                        break;
                    }
                }
            }
        }

        for(int i = 1; i < (1 << 18); i++) {
            int len = 0;
            sum = 0;
            for(int j = 0; j < 18; j++) {
                if(i & (1 << j)) {
                    sum += A[a[j]];
                    len += 1;
                }
            }
            if(sum % len != 0 || s.find(sum / len) == s.end()) {
                std::cout << len << '\n';
                for(int j = 0; j < 18; j++) {
                    if(i & (1 << j)) {
                        std::cout << A[a[j]] << ' ';
                    }
                }
                std::cout << '\n';
                return;
            }
        }
    } else {
        for(int i = 1; i < (1 << N); i++) {
            sum = 0;
            int len = 0;
            for(int j = 0; j < N; j++) {
                if(i & (1 << j)) {
                    sum += A[j];
                    len += 1;
                }
            }
            if(sum % len != 0 || s.find(sum / len) == s.end()) {
                std::vector<int> ans;
                for(int j = 0; j < N; j++) {
                    if(i & (1 << j)) {
                        ans.push_back(A[j]);
                    }
                }
                std::cout << len << '\n';
                for(int j = 0; j < len; j++) {
                    std::cout << ans[j] << " \n"[j == len - 1];
                }
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
