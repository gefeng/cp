#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, D;
    std::cin >> N >> M >> D;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }
    
    A.push_back(N + 1);

    int sum = 0;
    int pre = 0;
    for(int i = 0; i < M + 1; i++) {
        int p = A[i];
        if(p != 1) {
            sum += i == 0 ? (p - 2) / D + 2 : (p - pre - 1) / D + (i == M ? 0 : 1);
        } else {
            sum += 1;
        }
        pre = p;
    }

    int min_v = sum;
    int remove = 0;
    pre = 0;
    for(int i = 0; i < M; i++) {
        int p = A[i];
        int cnt = sum;

        if(p != 1) {
            int nxt = A[i + 1]; 
            int eat1 = i == 0 ? (p - 2) / D + 2 : (p - pre - 1) / D + 1;
            int eat2 = (nxt - p - 1) / D + (i + 1 == M ? 0 : 1); 
            cnt -= eat1 + eat2;
            cnt += i == 0 ? (nxt - 2) / D + 1 + (i + 1 == M ? 0 : 1) : (nxt - pre - 1) / D + (i + 1 == M ? 0 : 1);
        }

        if(min_v > cnt) {
            min_v = cnt;
            remove = 1;
        } else if(min_v == cnt) {
            remove += 1;
        }
        pre = p;
    }

    std::cout << min_v << ' ' << remove << '\n'; 
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
