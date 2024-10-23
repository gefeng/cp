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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int max_v = *std::max_element(A.begin(), A.end());
    int min_v = *std::min_element(A.begin(), A.end());

    int last_max = -1;
    int last_min = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == max_v) {
            last_max = i;
        }
        if(A[i] == min_v) {
            last_min = i;
        }
    }

    if(last_min > last_max) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;
    while(A.size() >= 3) {
        int n = A.size();
        if(n % 2 == 1) {
            ans.emplace_back(0, n - 1);
            std::vector<int> tmp(A);
            std::sort(tmp.begin(), tmp.end());
            for(int i = 0; i < N; i++) {
                if(A[i] == tmp[n / 2]) {
                    A.erase(A.begin() + i);
                    break;
                }
            }
        } else {
            ans.emplace_back(0, n - 2);
            std::vector<int> tmp(A.begin(), A.end() - 1);
            std::sort(tmp.begin(), tmp.end());
            for(int i = 0; i < N; i++) {
                if(A[i] == tmp[(n - 1) / 2]) {
                    A.erase(A.begin() + i);
                    break;
                }
            }
        }
    }

    std::cout << N - 2 << '\n';
    for(int i = 0; i < N - 2; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
