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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::pair<int, int>> ans;
    for(int i = N - 1; i >= 0; i--) {
        if(B[i] <= N) {
            if(A[i] > N) {
                ans.emplace_back(3, i);
                std::swap(A[i], B[i]);
                continue;
            }

            int j = i - 1;
            while(A[j] <= N) {
                j -= 1;
            }

            while(j != i) {
                ans.emplace_back(1, j);
                std::swap(A[j], A[j + 1]);
                j += 1;
            }
            ans.emplace_back(3, i);
            std::swap(A[i], B[i]);
        } else if(A[i] > N) {
            if(B[i] <= N) {
                ans.emplace_back(3, i);
                std::swap(A[i], B[i]);
                continue;
            }

            int j = i - 1;
            while(B[j] > N) {
                j -= 1;
            }

            while(j != i) {
                ans.emplace_back(2, j);
                std::swap(B[j], B[j + 1]);
                j += 1;
            }
            ans.emplace_back(3, i);
            std::swap(A[i], B[i]);
        }
    }
    
    for(int i = N - 2; i >= 0; i--) {
        int j = i;
        while(j + 1 < N && A[j] > A[j + 1]) {
            std::swap(A[j], A[j + 1]);
            ans.emplace_back(1, j);
            j += 1;
        }

        j = i;
        while(j + 1 < N && B[j] > B[j + 1]) {
            std::swap(B[j], B[j + 1]);
            ans.emplace_back(2, j);
            j += 1;
        }
    }

    int size = ans.size();
    assert(size <= 1709);
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second + 1 << '\n';
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
