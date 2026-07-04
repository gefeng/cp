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

    std::vector<int> c1(N + 1, -1);
    std::vector<int> c2(N + 1, M + 1);
    
    for(int i = 0; i < N; i++) {
        int A, D, B;
        std::cin >> A >> D >> B;

        if(D - 1 >= 1 ) {
            c1[A] = std::max(c1[A], D - 1);
        } 
        c2[B] = std::min(c2[B], D);
    }

    std::vector<int> diff(M + 10, 0);
    for(int c = 1; c <= N; c++) {
        if(c1[c] >= c2[c]) {
            diff[1] += 1;
            diff[M + 1] -= 1;
        }  else {
            if(c1[c] != -1) {
                diff[1] += 1;
                diff[c1[c] + 1] -= 1;
            }
            if(c2[c] != M + 1) {
                diff[c2[c]] += 1;
                diff[M + 1] -= 1;
            }
        }
    }

    int rolling = 0;
    for(int i = 1; i <= M; i++) {
        rolling += diff[i];
        std::cout << rolling << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
