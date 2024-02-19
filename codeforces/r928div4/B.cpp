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

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    int pre = 0;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(G[i][j] == '1') {
                cnt += 1;
            }
        }

        if(cnt) {
            if(pre != 0 && cnt != pre) {
                std::cout << "TRIANGLE" << '\n';
                return;
            }

            pre = cnt;
        }
    }

    std::cout << "SQUARE" << '\n';
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
