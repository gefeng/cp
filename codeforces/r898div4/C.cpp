#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A(10);
    for(int i = 0; i < 10; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> score(10, std::vector<int>(10, 0));
    for(int i = 0; i < 5; i++) {
        int s = i + 1;
        for(int c = 0; c < 10 - i * 2; c++) {
            score[i][c + i] = s;
            score[9 - i][c + i] = s;
        }
        
        for(int r = 0; r < 10 - i * 2; r++) {
            score[r + i][i] = s;
            score[r + i][9 - i] = s;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(A[i][j] == 'X') {
                ans += score[i][j];
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
