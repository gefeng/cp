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
    
    std::vector<std::pair<int, int>> A(N);
    std::vector<std::pair<int, int>> B(N);
    
    for(int i = 0; i < N; i++) {
        char T_1, T_2;
        int X, Y;
        std::cin >> T_1 >> X >> T_2 >> Y;
        
        if(T_1 == '+') {
            A[i] = {0, X};
        } else {
            A[i] = {1, X};
        }

        if(T_2 == '+') {
            B[i] = {0, Y};
        } else {
            B[i] = {1, Y};
        }
    }

    auto find_next = [&](int st) {
        for(int i = st; i < N; i++) {
            if(A[i].first == 1 && B[i].first == 1) {
                if(A[i].second > B[i].second) {
                    return 0;
                } else if(B[i].second > A[i].second) {
                    return 1;
                }
            } else if(A[i].first == 1) {
                return 0;
            } else if(B[i].first == 1) {
                return 1;
            }
        }
        return -1;
    };

    int64_t l = 1;
    int64_t r = 1;
    for(int i = 0; i < N; i++) {
        int j = find_next(i + 1);
        if(A[i].first == 0 && B[i].first == 0) {
            if(j == -1 || j == 0) {
                l += A[i].second + B[i].second; 
            } else {
                r += A[i].second + B[i].second;
            }
        } else if(A[i].first == 1 && B[i].first == 1) {
            if(j == -1 || j == 0) {
                l += l * (A[i].second - 1) + r * (B[i].second - 1);
            } else {
                r += l * (A[i].second - 1) + r * (B[i].second - 1);
            }
        } else if(A[i].first == 1) {
            if(j == -1 || j == 0) {
                l += l * (A[i].second - 1) + B[i].second;
            } else {
                r += l * (A[i].second - 1) + B[i].second;
            }
        } else {
            if(j == -1 || j == 0) {
                l += r * (B[i].second - 1) + A[i].second;
            } else {
                r += r * (B[i].second - 1) + A[i].second;
            }
        }
    }

    std::cout << l + r << '\n';
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
