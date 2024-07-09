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
    std::vector<int> C(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::vector<int64_t> psum_a(N + 1, 0);
    std::vector<int64_t> psum_b(N + 1, 0);
    std::vector<int64_t> psum_c(N + 1, 0);
    
    for(int i = 1; i <= N; i++) {
        psum_a[i] = psum_a[i - 1] + A[i - 1];
        psum_b[i] = psum_b[i - 1] + B[i - 1];
        psum_c[i] = psum_c[i - 1] + C[i - 1];
    } 
    
    int64_t tot = psum_a[N]; 
    
    auto bs1 = [&](int st) {
        int lo = st;
        int hi = N - 1;
        int res = -1;
        int64_t t = (tot + 3 - 1) / 3;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum_a[mid + 1] - psum_a[st] >= t) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    auto bs2 = [&](int st) {
        int lo = st;
        int hi = N - 1;
        int res = -1;
        int64_t t = (tot + 3 - 1) / 3;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum_b[mid + 1] - psum_b[st] >= t) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    auto bs3 = [&](int st) {
        int lo = st;
        int hi = N - 1;
        int res = -1;
        int64_t t = (tot + 3 - 1) / 3;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(psum_c[mid + 1] - psum_c[st] >= t) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    int64_t t = (tot + 3 - 1) / 3;
    for(int i = 1; i <= N - 2; i++) {
        if(psum_a[i] >= t) {
            int j = i - 1;
            int k = bs2(j + 1); 
            if(k != -1 && k != N - 1 && psum_c[N] - psum_c[k + 1] >= t) {
                std::cout << 1 << ' ' << j + 1 << ' ' << j + 2 << ' ' << k + 1 << ' ' << k + 2 << ' ' << N << '\n';
                return;
            }

            k = bs3(j + 1);
            if(k != -1 && k != N - 1 && psum_b[N] - psum_b[k + 1] >= t) {
                std::cout << 1 << ' ' << j + 1 << ' ' << k + 2 << ' ' << N << ' ' << j + 2 << ' ' << k + 1 << '\n';
                return;
            }
        } 
    }

    for(int i = 2; i < N; i++) {
        if(psum_a[N] - psum_a[i] >= t) {
            int k = bs2(0);
            if(k != -1 && k < i - 1 && psum_c[i] - psum_c[k + 1] >= t) {
                std::cout << i + 1 << ' ' << N << ' ' << 1 << ' ' << k + 1 << ' ' << k + 2 << ' ' << i << '\n';
                return;
            }

            k = bs3(0);
            if(k != -1 && k < i - 1 && psum_b[i] - psum_b[k + 1] >= t) {
                std::cout << i + 1 << ' ' << N << ' ' << k + 2 << ' ' << i << ' ' << 1 << ' ' << k + 1 << '\n';
                return;
            }
        }
    }
    
    for(int i = 1; i < N - 1; i++) {
        int j = bs1(i);
        if(j == -1) {
            continue;
        }

        if(j < N - 1 && psum_b[i] >= t && psum_c[N] - psum_c[j + 1] >= t) {
            std::cout << i + 1 << ' ' << j + 1 << ' ' << 1 << ' ' << i << ' ' << j + 2 << ' ' << N << '\n';
            return;
        }

        if(j < N - 1 && psum_c[i] >= t && psum_b[N] - psum_b[j + 1] >= t) {
            std::cout << i + 1 << ' ' << j + 1 << ' ' << j + 2 << ' ' << N << ' ' << 1 << ' ' << i << '\n';
            return;
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
