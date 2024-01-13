#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e18;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int64_t> before;
    std::vector<int64_t> after;
    std::vector<std::vector<int>> append;

    int64_t len = 0;
    std::vector<int> v;
    for(int i = 0; i < N; i++) {
        int T, X;
        std::cin >> T >> X;

        if(T == 1) {
            if(len < MAX) {
                v.push_back(X);
                len += 1;
            }
        } else {
            if(len - v.size() < MAX) {
                append.push_back(v);

                before.push_back(len - v.size());
                after.push_back(len);
                if(X + 1 <= MAX / len) {
                    len *= (X + 1);
                } else {
                    len = MAX;
                }
            }
            v.clear();
        }
    }

    for(int i = 0; i < Q; i++) {
        int64_t P;
        std::cin >> P;
        P -= 1;

        int ans = 0;
        if(after.empty()) {
            ans = v[P];
        } else if(P + 1 > len - v.size()) {
            ans = v[P - (len - v.size())];
        } else {
            int j = before.size() - 1;
            while(j >= 0) {
                int64_t l = before[j];
                int64_t r = after[j];

                P %= r;
                if(P + 1 > l && P + 1 <= r && r - l > 0) {
                    ans = append[j][P - l];
                    break;
                }
                
                j -= 1;
            }
        }

        std::cout << ans << " \n"[i == Q - 1];
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
