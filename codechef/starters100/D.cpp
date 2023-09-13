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

    if(N % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));
    std::string s = "";
    int x = 0;
    for(int i = 0, d = 1; i < N; i++) {
        if(i == 0) {
            for(int j = 0; j < N; j++) {
                ans[i][j] = x;
                s.push_back('R');
                x = (x + 1) % N;
            }
            s.pop_back();
            d *= -1;
        } else {
            if(d < 0) {
                for(int j = N - 1; j > 0; j--) {
                    ans[i][j] = x;
                    s.push_back('L');
                    x = (x + 1) % N;
                }
            } else {
                for(int j = 1; j < N; j++) {
                    ans[i][j] = x;
                    s.push_back('R');
                    x = (x + 1) % N;
                }
            }
            s.pop_back();
            d *= -1;
        } 

        if(i + 1 < N) {
            s.push_back('D');
        }
    }

    s.push_back('L');
    for(int i = N - 1; i > 0; i--) {
        ans[i][0] = x;
        s.push_back('U');
        x = (x + 1) % N;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
    }

    std::cout << s << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
