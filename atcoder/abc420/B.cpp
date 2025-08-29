#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> score(N, 0);
    for(int i = 0; i < M; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            cnt += A[j][i] - '0';
        } 
        for(int j = 0; j < N; j++) {
            if(cnt == 0 || cnt == N) {
                score[j] += 1;
                continue;
            } 
            if(cnt < N - cnt && A[j][i] == '1') {
                score[j] += 1;
            } else if(cnt > N - cnt && A[j][i] == '0') {
                score[j] += 1;
            }
        }
    }

    int max_v = *std::ranges::max_element(score);
    for(int i = 0; i < N; i++) {
        if(max_v == score[i]) {
            std::cout << i + 1 << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
