#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        B[i]--;
    }

    std::vector<int> a;
    std::vector<int> b;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            a.push_back(A[i]);
        } else {
            b.push_back(A[i]);
        }
    }

    std::ranges::sort(a);
    std::ranges::sort(b);
   
    int64_t ans = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
    bool eve = false;
    bool odd = false;
    for(int p : B) {
        if(p % 2 == 1) {
            if(!b.empty()) {
                if(b.back() >= 0) {
                    ans -= b.back();
                    b.pop_back();
                    odd = true;
                } else {
                    if(!odd) {
                        ans -= b.back(); 
                        b.pop_back();
                        odd = true;
                    }
                }
            }
        } else {
            if(!a.empty()) {
                if(a.back() >= 0) {
                    ans -= a.back();
                    a.pop_back();
                    eve = true;
                } else {
                    if(!eve) {
                        ans -= a.back();
                        a.pop_back();
                        eve = true;
                    }
                }
            }
        }
    }

    std::cout << ans << '\n';
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
