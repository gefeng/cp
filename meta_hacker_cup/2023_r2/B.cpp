#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case(int T) {
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

    std::vector<int> cand;
    std::vector<int> psum1(N + 1, 0);
    std::vector<int> psum2(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum1[i] = psum1[i - 1] + (A[i - 1] < B[i - 1] ? 1 : 0);
        psum2[i] = psum2[i - 1] + (A[i - 1] > B[i - 1] ? 1 : 0);
    }

    if(N % 2 == 0) {
        for(int i = 0; i <= N; i++) {
            if(psum1[i] == i && (psum2[N] - psum2[i]) == N - i) {
                if(i < N / 2) {
                    cand.push_back(i + N + N / 2);
                } else {
                    cand.push_back(i - N / 2);
                }
            }
            if(psum2[i] == i && (psum1[N] - psum1[i]) == N - i) {
                cand.push_back(i + N / 2);
            }
        }
    } else {
        for(int i = 0; i < N; i++) {
            if(psum1[i] == i && (psum2[N] - psum2[i + 1]) == N - i - 1) {
                if(i < N / 2) {
                    cand.push_back(i + N + N / 2 + 1);
                } else {
                    cand.push_back(i - N / 2);
                } 
            }
            if(psum2[i] == i && (psum1[N] - psum1[i + 1]) == N - i - 1) {
                cand.push_back(i + N / 2 + 1); 
            }
        }
    }

    int ans = -1;
    for(int x : cand) {
        std::vector<int> a(N);
        std::vector<int> b(N);

        bool swapped = false;
        if(x >= N) {
            std::swap(A, B);
            swapped = true;
            x -= N;
        }
    
        for(int i = 0; i < N - x; i++) {
            a[i] = A[i + x];
            b[i] = B[i + x];
        }
        
        for(int i = 0; i < x; i++) {
            a[i + (N - x)] = B[i];
            b[i + (N - x)] = A[i];
        }

        if(swapped) {
            std::swap(A, B);
        }

        std::reverse(b.begin(), b.end());
        bool ok = true;
        for(int i = 0; i < N; i++) {
            if(a[i] != b[i]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans = x + (swapped ? N : 0);
            break;
        }
    } 

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
