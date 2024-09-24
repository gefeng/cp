#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ctime>

void run_case(int T) {
    int N;
    std::cin >> N;
    
    std::vector<int> X(N);
    std::vector<int> Y(N);
    for(int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    auto coliner = [&](int a, int b, int c) {
        int x1 = X[a] - X[c];
        int y1 = Y[a] - Y[c];
        int x2 = X[b] - X[c];
        int y2 = Y[b] - Y[c];
        
        return x1 * y2 - x2 * y1 == 0;
    };

    int round = int(sqrt(N));
    int ans = N;
    while(round--) {
        int a = std::rand() % N;
        int b = std::rand() % N;
        while(a == b) {
            b = std::rand() % N;
        }

        int cnt = 2;
        for(int i = 0; i < N; i++) {
            if(i == a || i == b) {
                continue;
            }

            if(coliner(a, b, i)) {
                cnt += 1;
            }
        }

        ans = std::min(ans, N - cnt);
    }

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    std::srand(std::time(nullptr));

    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
