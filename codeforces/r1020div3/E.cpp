#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    std::vector<int> pos(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]] = i + 1;
    }

    for(int i = 0; i < Q; i++) {
        int L, R, X;
        std::cin >> L >> R >> X;

        int p = pos[X];
        if(p < L || p > R) {
            std::cout << -1 << " \n"[i == Q - 1];
            continue;
        }

        int smaller = X - 1; 
        int greater = N - X;
        
        int a = 0;
        int b = 0;
        int cnt = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            
            if(A[mid - 1] == X) {
                break;
            }

            if(A[mid - 1] < X) {
                if(p > mid) {
                    L = mid + 1; 
                    smaller -= 1;
                    continue;
                }    
                a += 1;
                R = mid - 1;
            } else {
                if(p < mid) {
                    R = mid - 1;
                    greater -= 1;
                    continue;
                }
                b += 1;
                L = mid + 1;
            }
        }

        int ex = std::min(a, b);
        smaller -= ex;
        greater -= ex;
        a -= ex;
        b -= ex;
        cnt = ex * 2;
        if(a) {
            greater -= a;
            smaller -= a;
            cnt += a * 2;
        }
        if(b) {
            greater -= b;
            smaller -= b;
            cnt += b * 2;
        }
        
        if(greater < 0 || smaller < 0) {
            std::cout << -1 << " \n"[i == Q - 1];
        } else {
            std::cout << cnt << " \n"[i == Q - 1];
        }
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
