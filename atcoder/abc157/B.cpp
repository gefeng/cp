#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::vector<int>> A(3, std::vector<int>(3));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    int N;
    std::cin >> N;
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> rs(3, 0);
    std::vector<int> cs(3, 0);
    int ds1 = 0;
    int ds2 = 0;
    for(int x : B) {
        for(int r = 0; r < 3; r++) {
            for(int c = 0; c < 3; c++) {
                if(A[r][c] == x) {
                    rs[r] += 1;
                    cs[c] += 1;
                    if(r == c) {
                        ds1 += 1;
                    } 
                    if(r + c == 2) {
                        ds2 += 1;
                    }
                }
            }
        }
    }

    bool ans = ds1 == 3 || ds2 == 3;
    for(int i = 0; i < 3; i++) {
        if(rs[i] == 3 || cs[i] == 3) {
            ans = true;
        }
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
