#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> div;
    for(int d = 1; d * d <= N; d++) {
        if(N % d == 0) {
            div.push_back(d);
            if(N / d != d) {
                div.push_back(N / d);
            }
        }
    }

    std::sort(div.begin(), div.end());
    
    int ans = 0;
    for(int d : div) {
        if(d == N) {
            ans += 1;
        } else {
            int k = N / d;
            int g = 0;
            bool same = true;
            for(int i = 0; i < d; i++) {
                int gl = 0;
                int pre = A[i];
                bool same_l = true;
                for(int j = 1; j < k; j++) {
                    int cur = A[j * d + i]; 
                    if(cur != pre) {
                        same_l = false;
                    }
                    gl = gl == 0 ? std::abs(cur - pre) : gcd(gl, std::abs(cur - pre));
                    pre = cur;
                }

                g = g == 0 ? gl : gcd(g, gl);
                same = same && same_l;
            }

            if(g > 1 || same) {
                ans += 1;
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
