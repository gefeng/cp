#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N, std::vector<int>(N));
    std::deque<int> q;
    for(int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;
        for(int j = 0; j < N; j++) {
            A[i][j] = S[j] - '0';
        }
    }

    for(int i = 0; i < N; i++) {
        q.emplace_back(A[0][i]);
    }

    for(int i = 1; i < N; i++) {
        q.emplace_back(A[i][N - 1]);
    }

    for(int i = N - 2; i >= 0; i--) {
        q.emplace_back(A[N - 1][i]);
    }

    for(int i = N - 2; i > 0; i--) {
        q.emplace_back(A[i][0]);
    }
    
    int last = q.back();
    q.pop_back();
    q.push_front(last);
    
    
    for(int i = 0; i < N; i++) {
        A[0][i] = q.front();
        q.pop_front();
    }

    for(int i = 1; i < N; i++) {
        A[i][N - 1] = q.front();
        q.pop_front();
    }

    for(int i = N - 2; i >= 0; i--) {
        A[N - 1][i] = q.front();
        q.pop_front();
    }

    for(int i = N - 2; i > 0; i--) {
        A[i][0] = q.front();
        q.pop_front();
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << A[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
