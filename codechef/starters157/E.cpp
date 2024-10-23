#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> div(N);
    std::vector<int> freq(M + 1, 0);
    for(int i = 0; i < N; i++) {
        for(int f = 1; f * f <= A[i]; f++) {
            if(A[i] % f == 0) {
                div[i].push_back(f);
                freq[f] += 1;
                if(A[i] / f != f) {
                    div[i].push_back(A[i] / f);
                    freq[A[i] / f] += 1; 
                }
            } 
        }
    }

    int ans = 0;
    int lo = 1;
    int hi = M;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int64_t t = 1;
        bool ok = false;
        for(int i = 1; i <= mid; i++) {
            if(freq[i] == 0) {
                t = lcm(t, i);
                if(t > M) {
                    break;
                }
            }
        }

        if(t <= M) {
            for(int i = 0; i < N; i++) {
                int64_t x = t;
                bool good = true;
                for(int d : div[i]) {
                    if(d <= mid && freq[d] == 1) {
                        x = lcm(x, d); 
                        if(x > M) {
                            good = false;
                            break;
                        }
                    }     
                }
                if(good) {
                    ok = true;
                    break;
                }
            }
        }

        if(ok) {
            ans = mid + 1;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
