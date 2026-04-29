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
    for(int i = 0; i < N; i++) {
        int len = 0;
        for(int j = i; j < N; j++) {
            if((j - i) % 2 == 0) {
                if(S[j] != 'u' && S[j] != 'o') {
                    break;
                }
                len++;
            } else {
                if(S[j] != 'w') {
                    break;
                }
                len++;
            }
        }
        ans = std::max(ans, len % 2 == 0 ? len - 1 : len);
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
