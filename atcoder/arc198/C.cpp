#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

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

    int sum_a = std::accumulate(A.begin(), A.end(), 0);
    int sum_b = std::accumulate(B.begin(), B.end(), 0);

    if(sum_a != sum_b) {
        std::cout << "No" << '\n';
        return;
    }
    
    if(N == 2) {
        if(A[0] == B[0]) {
            std::cout << "Yes" << '\n' << 0 << '\n';
            return;
        }
        A[0] += 1;
        A[1] -= 1;
        std::swap(A[0], A[1]);
        if(A[0] != B[0]) {
            std::cout << "No" << '\n';
            return;
        }

        std::cout << "Yes" << '\n' << 1 << '\n';
        std::cout << 1 << ' ' << 2 << '\n';        
        return;
    }

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            continue;
        }

        if(i) {
            if(A[i] < B[i]) {
                int j = i + 1;
                while(j < N && A[j] <= B[j]) {
                    j += 1;
                }
                while(A[i] != B[i]) {
                    ans.emplace_back(i, j);
                    ans.emplace_back(0, j);
                    ans.emplace_back(0, i);
                    ans.emplace_back(0, j);
                    A[i] += 1;
                    A[j] -= 1;
                }
            } else {
                int j = i + 1;
                while(j < N && A[j] >= B[j]) {
                    j += 1;
                }
                while(A[i] != B[i]) {
                    ans.emplace_back(0, i);
                    ans.emplace_back(0, j);
                    ans.emplace_back(0, i);
                    ans.emplace_back(i, j);
                    A[i] -= 1;
                    A[j] += 1;
                }
            }
        } else {
            if(A[i] < B[i]) {
                int j = i + 1;
                while(j < N && A[j] <= B[j]) {
                    j += 1;
                }
                if(j == N - 1) {
                    j -= 1;
                }
                while(A[i] != B[i]) {
                    ans.emplace_back(i, j);
                    ans.emplace_back(j, N - 1);
                    ans.emplace_back(i, N - 1);
                    ans.emplace_back(j, N - 1);
                    A[i] += 1;
                    A[j] -= 1;
                }
            } else {
                int j = i + 1;
                while(j < N && A[j] >= B[j]) {
                    j += 1;
                }
                if(j == N - 1) {
                    j -= 1;
                }
                while(A[i] != B[i]) {
                    ans.emplace_back(i, N - 1);
                    ans.emplace_back(j, N - 1);
                    ans.emplace_back(i, N - 1);
                    ans.emplace_back(i, j);
                    A[i] -= 1;
                    A[j] += 1;
                }
            }
        }
    } 

    std::cout << "Yes" << '\n';
    int size = ans.size();
    assert(size <= 31000);
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
