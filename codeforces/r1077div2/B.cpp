#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    int ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        if(S[j] == '0') {
            if(j == 0 && i == N) {
                if(i - j <= 2) {
                    ans += 1;
                } else {
                    int c1 = (i - j - 1) / 3 + ((i - j - 1) % 3 == 2 ? 1 : 0) + 1;
                    int c2 = (i - j - 2) / 3 + ((i - j - 2) % 3 == 2 ? 1 : 0) + 1;
                    int c3 = (i - j) / 3 + ((i - j) % 3 == 2 ? 1 : 0) + 1;
                    ans += std::min(std::min(c1, c2), c3);
                }
            } else if(j == 0 || i == N) {
                ans += (i - j) / 3 + ((i - j) % 3 == 2 ? 1 : 0);
            } else {
                ans += (i - j) / 3;
            }
        } else {
            ans += 1;
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
