#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int K;
    std::cin >> K;

    std::vector<std::vector<int>> masks(K);
    std::vector<int> save_size(K, 0);
    for(int i = 0; i < K; i++) {
        int N;
        std::cin >> N;

        for(int j = 0; j < N - 1; j++) {
            int P;
            std::cin >> P;
        }

        save_size[i] = N;
    }

    int ans = 0;
    std::sort(save_size.begin(), save_size.end(), std::greater<int>());
    
    for(int i = 0; i < K; i++) {
        int v = save_size[i];
        for(int j = 30; j >= 0; j--) {
            if(v & (1 << j)) {
                if(ans & (1 << j)) {
                    ans |= (1 << j) - 1;
                    break;
                } else {
                    ans |= 1 << j;
                }
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
