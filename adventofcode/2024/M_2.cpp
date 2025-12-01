#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t C = 10000000000000;

int next_int(std::string& s, int& p) {
    int n = s.size();
    while(p < n && !isdigit(s[p])) {
        p += 1;
    }
    int x = 0;
    while(p < n && isdigit(s[p])) {
        x = x * 10 + s[p++] - '0';
    }
    return x;
}

void run_case() {
    std::vector<std::string> A;
    for(std::string S; std::getline(std::cin, S); ) {
        if(!S.empty()) {
            A.push_back(S);
        }
    }

    int n = A.size();
    int64_t ans = 0;
    for(int i = 0; i < n; i += 3) {
        int p = 0;
        int64_t xa = next_int(A[i], p);
        int64_t ya = next_int(A[i], p);

        p = 0;
        int64_t xb = next_int(A[i + 1], p);
        int64_t yb = next_int(A[i + 1], p);
        
        p = 0;
        int64_t xt = next_int(A[i + 2], p) + C;
        int64_t yt = next_int(A[i + 2], p) + C;

        int64_t k = yt * xb - xt * yb;
        int64_t q = ya * xb - xa * yb; 
        
        if(k % q == 0 && k / q >= 0) {
            int64_t a = k / q;

            if((xt - a * xa) % xb == 0) {
                int64_t b = (xt - a * xa) / xb;

                if(b >= 0) {
                    ans += a * 3 + b;
                }
            }
        }

        // int min_c = INF;
        // for(int a = 0; a <= 100; a++) {
        //     for(int b = 0; b <= 100; b++) {
        //         if(a * xa + b * xb == xt && a * ya + b * yb == yt) {
        //             min_c = std::min(min_c, a * 3 + b); 
        //         }
        //     }
        // }
        //
        // if(min_c != INF) {
        //     ans += min_c;
        // }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
