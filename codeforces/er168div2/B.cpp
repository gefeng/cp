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

    std::vector<std::string> G(2);
    for(int i = 0; i < 2; i++) {
        std::cin >> G[i];
    }

    int ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < N - 1; j++) {
            if(G[i][j] == '.') {
                if(i == 0) {
                    if(G[i + 1][j - 1] == 'x' && G[i + 1][j + 1] == 'x' && G[i + 1][j] == '.' && G[i][j - 1] == '.' && G[i][j + 1] == '.') {
                        ans += 1;
                    }
                } else {
                    if(G[i - 1][j - 1] == 'x' && G[i - 1][j + 1] == 'x' && G[i - 1][j] == '.' && G[i][j - 1] == '.' && G[i][j + 1] == '.') {
                        ans += 1;
                    }
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
