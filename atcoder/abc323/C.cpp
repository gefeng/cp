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
    
    std::vector<int> A(M);
    std::vector<std::pair<int, int>> sorted(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        sorted[i] = {A[i], i};
    }

    std::sort(sorted.begin(), sorted.end(), std::greater<std::pair<int, int>>());

    std::vector<int> s(N, 0);
    std::vector<std::string> B(N);
    int max1 = 0;
    int max2 = 0;
    for(int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;

        B[i] = S;
        
        int score = 0;
        for(int j = 0; j < M; j++) {
            if(S[j] == 'o') {
                score += A[j];
            } 
        } 

        score += i + 1;

        s[i] = score;
        if(score > max1) {
            max2 = max1;
            max1 = score;
        } else if(score > max2) {
            max2 = score;
        }
    }

    for(int i = 0; i < N; i++) {
        int score = s[i];
        if(score == max1 && score > max2) {
            std::cout << 0 << '\n';
            continue;
        }

        if(score == max1) {
            std::cout << 1 << '\n';
            continue;
        } 

        int cnt = 0;
        for(int j = 0; j < M; j++) {
            if(B[i][sorted[j].second] == 'x') {
                score += sorted[j].first;
                cnt += 1;
                if(score > max1) {
                    break; 
                }
            }
        }

        std::cout << cnt << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
