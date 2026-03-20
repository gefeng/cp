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
    int N, K, P, M;
    std::cin >> N >> K >> P >> M;
    P -= 1;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    int ans = 0;
    while(M) {
        std::pair<int, int> play{};
        int p = -1;
        for(int i = 0; i < K; i++) {
            if(A[i].second == P) {
                play = A[i]; 
                p = i;
            }
        }

        if(p == -1) {
            play = A[0];
            p = 0;
            for(int i = 1; i < K; i++) {
                if(A[i].first < play.first) {
                    play = A[i];
                    p = i;
                }
            }
        }
        
        if(M < play.first) {
            break;
        }
        
        M -= play.first;
        if(play.second == P) {
            ans += 1;
        }
        
        for(int i = p; i < N - 1; i++) {
            A[i] = A[i + 1];
        }
        A[N - 1] = play;
    }

    std::cout << ans << '\n';
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
