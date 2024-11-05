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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> left(N, 0);
    std::vector<int> right(N, 0);
    std::vector<int> decl(N, 0);
    std::vector<int> decr(N, 0);
    std::vector<int> incl(N, 0);    
    std::vector<int> incr(N, 0);
    std::vector<int> inc(N, 0);
    std::vector<int> dec(N, 0);
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            left[i] = 0;
        } else {
            left[i] = A[i] > A[i - 1] ? left[i - 1] : i;
        }
    }
    
    for(int i = N - 1; i >= 0; i--) {
        if(i == N - 1) {
            right[i] = i;
        } else {
            right[i] = A[i] > A[i + 1] ? right[i + 1] : i;
        }
    }

    for(int i = 0; i < N; i++) {
        if(i == 0) {
            incl[i] = 1;
            inc[i] = 1;
        } else {
            if(A[i] > A[i - 1]) {
                incl[i] = std::max(incl[i - 1], inc[i - 1] + 1);
                inc[i] = inc[i - 1] + 1;
            } else {
                incl[i] = std::max(incl[i - 1], 1);
                inc[i] = 1;
            }
        }
    }

    inc.assign(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        if(i == N - 1) {
            incr[i] = 1;
            inc[i] = 1;
        } else {
            if(A[i] > A[i + 1]) {
                incr[i] = std::max(incr[i + 1], inc[i + 1] + 1);
                inc[i] = inc[i + 1] + 1;
            } else {
                incr[i] = std::max(incr[i + 1], 1);
                inc[i] = 1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(i == 0) {
            decl[i] = 1;
            dec[i] = 1;
        } else {
            if(A[i] < A[i - 1]) {
                decl[i] = std::max(decl[i - 1], dec[i - 1] + 1); 
                dec[i] = dec[i - 1] + 1;
            } else {
                decl[i] = std::max(decl[i - 1], 1);
                dec[i] = 1;
            }
        }
    }

    dec.assign(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        if(i == N - 1) {
            decr[i] = 1;
            dec[i] = 1;
        } else {
            if(A[i] < A[i + 1]) {
                decr[i] = std::max(decr[i + 1], dec[i + 1] + 1);
                dec[i] = dec[i + 1] + 1;
            } else {
                decr[i] = std::max(decr[i + 1], 1);
                dec[i] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < N - 1; i++) {
        if(A[i] > A[i - 1] && A[i] > A[i + 1]) {
            int l = left[i];
            int r = right[i];
            int l_len = i - l + 1;
            int r_len = r - i + 1;
            if(l_len == 2 || r_len == 2 || (l_len % 2 == 0 && r_len % 2 == 0)) {
                continue;
            }

            if(l_len == r_len) {
                if(incl[l] < l_len && decl[l] < l_len && incr[r] < l_len && decr[r] < l_len) {
                    ans += 1;
                } 
            }
        } 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
