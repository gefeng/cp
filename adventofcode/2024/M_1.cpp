#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

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
    int ans = 0;
    for(int i = 0; i < n; i += 3) {
        int p = 0;
        int xa = next_int(A[i], p);
        int ya = next_int(A[i], p);

        p = 0;
        int xb = next_int(A[i + 1], p);
        int yb = next_int(A[i + 1], p);
        
        p = 0;
        int xt = next_int(A[i + 2], p);
        int yt = next_int(A[i + 2], p);

        int min_c = INF;
        for(int a = 0; a <= 100; a++) {
            for(int b = 0; b <= 100; b++) {
                if(a * xa + b * xb == xt && a * ya + b * yb == yt) {
                    min_c = std::min(min_c, a * 3 + b); 
                }
            }
        }

        if(min_c != INF) {
            ans += min_c;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
