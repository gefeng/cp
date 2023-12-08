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
    int64_t P, X, Y;
    std::cin >> N >> P >> X >> Y;

    int64_t day = 0;
    int64_t earn = 0;
    int64_t cnt = 0;
    int64_t cnt_task = (N + 7 - 1) / 7;
    int64_t need = (P + X + Y * 2 - 1) / (X + Y * 2);
    
    cnt = std::min(cnt_task / 2, need);
    
    earn = cnt * (X + Y * 2);
    P -= earn;
    day += cnt;
    cnt_task -= 2 * cnt;
    if(P <= 0) {
        std::cout << N - day << '\n';
        return;
    }

    need = (P + X + Y - 1) / (X + Y);
    cnt = std::min(need, cnt_task); 

    earn = cnt * (X + Y);
    day += cnt;
    P -= earn;
    if(P <= 0) {
        std::cout << N - day << '\n'; 
        return;
    }

    day += (P + X - 1) / X;

    std::cout << N - day << '\n';
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
