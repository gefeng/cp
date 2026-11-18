#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> nxt(N, 0);
    for(int i = 0; i < N; ) {
        int j = i;
        if(i != N - 1) {
            int d = A[i + 1] - A[i];
            i++;
            while(i + 1 < N && A[i + 1] - A[i] == d) {
                i++;
            }
            for(int k = j; k < i; k++) {
                nxt[k] = i;
            }
        } else {
            nxt[i] = i;
            break;
        }
    }

    auto check = [&](int i, int j, int d) {
        return (A[j] - A[i]) % (j - i) == 0 && (A[j] - A[i]) / (j - i) == d;
    };

    int ans = 0;
    for(int i = 0; i < N; i++) {
        std::map<int, int> m1;
        int max_f = 0;
        int d = 0;
        int p = -1;
        for(int j = i + 1; j < N; j++) {
            int x = A[j] - A[i];
            int y = j - i;
            if(x % y == 0) {
                int f = ++m1[x / y];
                if(f > max_f) {
                    max_f = f;
                    d = x / y;
                }
            }
            
            if(j - i - max_f > K) {
                break;
            }

            int used = j - i - max_f;
            ans = std::max(ans, j - i + 1 + std::min(i, K - used));

            if(max_f > K) {
                p = j + 1;
                break;
            }
        }

        if(max_f > K && p != -1) {
            while(p < N) {
                if(check(i, p, d) && p + 1 < N && check(i, p + 1, d)) {
                    int np = nxt[p];
                    max_f += np - p + 1;
                    p = np;
                } else if(check(i, p, d)) {
                    max_f++;
                }
                int used = p - i - max_f;
                if(used > K) {
                    break;
                }
                ans = std::max(ans, p - i + 1 + std::min(i, K - used)); 
                p++;
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
