#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::map<int64_t, int64_t> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]] += 1;
    } 

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int64_t X, Y;
        std::cin >> X >> Y;

        int64_t res = 0; 
        int64_t s = (int64_t)sqrt(X * X - 4 * Y);
        if(s * s != X * X - 4 * Y) {
            res = 0;
        } else {
            int64_t x1 = (X + s);
            int64_t x2 = (X - s);

            if(x1 % 2 != 0) {
                res = 0;
            } else {
                x1 /= 2;
                x2 /= 2;
                //std::cout << x1 << ' ' << x2 << '\n';
                int64_t y1 = X - x1;
                int64_t y2 = X - x2;

                if(m.find(x1) != m.end() && m.find(y1) != m.end()) {
                    if(x1 == y1) {
                        res += m[x1] * (m[x1] - 1) / 2;
                    } else {
                        res += m[x1] * m[y1]; 
                    }
                }
                if((std::min(x1, y1) != std::min(x2, y2) || std::max(x1, y1) != std::max(x2, y2)) && m.find(x2) != m.end() && m.find(y2) != m.end()) {
                    if(x2 == y2) {
                        res += m[x2] * (m[x2] - 1) / 2;
                    } else {
                        res += m[x2] * m[y2]; 
                    }
                }
            }
        }

        std::cout << res << " \n"[i == Q - 1];
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
