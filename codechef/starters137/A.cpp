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
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    bool ok = true;
    for(int i = 1; i < N; i++) {
        if(B[i - 1] < A[i] - A[i - 1]) {
            for(int j = i + 1; j < N; j++) {
                if(B[j - 1] < A[j] - A[j - 1]) {
                    ok = false;
                    break;
                }
            } 
            if(ok) {
                std::cout << "Yes" << '\n';
                return;
            }

            ok = true;
            for(int j = N - 2; j >= i; j--) {
                if(B[j + 1] < A[j + 1] - A[j]) {
                    ok = false;
                    break;
                } 
            }
            if(ok) {
                std::cout << "Yes" << '\n';
                return;
            }

            break;
        }
    }

    if(ok) {
        std::cout << "Yes" << '\n';
        return;
    }

    ok = true;
    for(int i = N - 2; i >= 0; i--) {
        if(B[i + 1] < A[i + 1] - A[i]) {
            for(int j = i - 1; j >= 0; j--) {
                if(B[j + 1] < A[j + 1] - A[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                std::cout << "Yes" << '\n';
                return;
            }

            ok = true;
            for(int j = 1; j <= i; j++) {
                if(B[j - 1] < A[j] - A[j - 1]) {
                    ok = false;
                    break;
                } 
            }

            if(ok) {
                std::cout << "Yes" << '\n';
                return;
            }
            break;
        }
    }

    int len_l = 1;
    int len_r = 1;
    for(int i = 1; i < N; i++) {
        if(B[i] >= A[i] - A[i - 1]) {
            len_l += 1;
        } else {
            break;
        }
    }

    for(int i = N - 2; i >= 0; i--) {
        if(B[i] >= A[i + 1] - A[i]) {
            len_r += 1; 
        } else {
            break;
        }
    }
    
    std::cout << (len_l + len_r >= N ? "Yes" : "No") << '\n';
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
