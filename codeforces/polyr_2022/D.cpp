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
    
    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> a(N, 0);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            sum += A[i][j];
            a[i] += A[i][j];
        }
    }

    if(sum % N != 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::tuple<int, int, int>> ans;
    for(int c = 0; c < M; c++) {
        std::vector<int> give;
        std::vector<int> need;
        for(int r = 0; r < N; r++) {
            if(a[r] > sum / N && A[r][c] == 1) {
                give.push_back(r);
            } 
            if(a[r] < sum / N && A[r][c] == 0) {
                need.push_back(r);
            }
        }

        while(!give.empty() && !need.empty()) {
            int r1 = give.back();
            int r2 = need.back();

            if(a[r1] > sum / N && a[r2] < sum / N) {
                give.pop_back();
                need.pop_back();
                a[r1] -= 1;
                a[r2] += 1;
                ans.emplace_back(r1 + 1, r2 + 1, c + 1);
            } else if(a[r1] == sum / N) {
                give.pop_back(); 
            } else if(a[r2] == sum / N) {
                need.pop_back();
            }
        }
    }

    int sz = ans.size();
    std::cout << sz << '\n';
    for(auto [r1, r2, c] : ans) {
        std::cout << r1 << ' ' << r2 << ' ' << c << '\n';
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
