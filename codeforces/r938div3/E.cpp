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
    for(int k = 1; k <= N; k++) {
        bool ok = true;
        std::vector<int> diff(N + 1, 0);
        std::string s(S);
        int sum = 0;
        for(int i = 0; i <= N - k; i++) {
            sum += diff[i];
            int c = (s[i] - '0' + sum) % 2;

            if(c == 0) {
                diff[i + 1] += 1;
                diff[i + k] -= 1;
            }
        }

        for(int i = N - k + 1; i < N; i++) {
            sum += diff[i];
            int c = (s[i] - '0' + sum) % 2;
            if(c == 0) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans = std::max(ans, k);
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
