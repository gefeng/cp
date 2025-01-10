#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> last(N, -1);
    for(int i = N - 1, j = M - 1; i >= 0 && j >= 0; i--) {
        if(S[i] == T[j]) {
            last[j] = i;
            j -= 1;
        }
    }

    int ans = 0;
    int pre = -1;
    for(int i = 0, j = 0; i < N && j < M; i++) {
        if(S[i] == T[j]) {
            if(j) {
                ans = std::max(ans, last[j] - pre);
            }
            pre = i;
            j += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
