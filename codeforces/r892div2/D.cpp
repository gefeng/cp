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

    std::vector<std::vector<int>> A(N, std::vector<int>(4));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> A[i][j];
        }
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });

    std::vector<std::pair<int, int>> save;
    for(int i = 0; i < N; i++) {
        int st = A[i][0];
        int ed = A[i][3];
    
        while(i + 1 < N) {
            if(A[i + 1][0] > ed) {
                break;  
            }    

            int ned = A[i + 1][3];
            if(ned > ed) {
                ed = ned;
            }
            i += 1;
        }

        save.emplace_back(st, ed);        
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        auto it = std::upper_bound(save.begin(), save.end(), X, [](int a, const auto& b) {
            return a < b.first;
        });
        
        int res = 0;
        if(it == save.begin()) {
            res = X;
        } else {
            it = std::prev(it);
            
            if(it->second >= X) {
                res = it->second;
            } else {
                res = X;
            }
        }

        std::cout << res << " \n"[i == Q - 1];
    }
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
