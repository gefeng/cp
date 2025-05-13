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
    int64_t W;
    std::cin >> N >> W;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end());

    int64_t sum = 0;
    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(sum + A[i].first < (W + 1) / 2) {
            sum += A[i].first;
            ans.push_back(A[i].second);
        } else if(sum + A[i].first <= W) {
            sum += A[i].first;
            ans.push_back(A[i].second);
            break;
        } else {
            if(A[i].first > W) {
                std::cout << -1 << '\n';
                return;
            }
            std::cout << 1 << '\n' << ' ' << A[i].second + 1 << '\n';
            return;
        }
    }

    if(sum < (W + 1) / 2) {
        std::cout << -1 << '\n';
        return;
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
