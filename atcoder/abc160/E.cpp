#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int X, Y, A, B, C;
    std::cin >> X >> Y >> A >> B >> C;

    std::vector<int> P(A);
    std::vector<int> Q(B);
    std::vector<int> R(C);
    
    for(int i = 0; i < A; i++) {
        std::cin >> P[i];
    }

    for(int i = 0; i < B; i++) {
        std::cin >> Q[i];
    }

    for(int i = 0; i < C; i++) {
        std::cin >> R[i];
    }

    std::sort(P.begin(), P.end(), std::greater<int>());
    std::sort(Q.begin(), Q.end(), std::greater<int>());
    std::sort(R.begin(), R.end(), std::greater<int>());

    std::vector<int> best;

    for(int i = 0; i < X; i++) {
        best.push_back(P[i]);
    }

    for(int i = 0; i < Y; i++) {
        best.push_back(Q[i]);
    }

    LL ans = 0LL;
    std::sort(best.begin(), best.end(), std::greater<int>());
    for(int i = 0; i < C && !best.empty(); i++) {
        if(best.back() >= R[i]) {
            break;
        }

        best.pop_back();
        ans += R[i];
    }
    
    for(int x : best) {
        ans += x;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
