#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> a(K);
    for(int i = 0; i < N; i++) {
        a[i % K].push_back(S[i] - '0'); 
    }

    int all_one = 0;
    int all_zero = 0;
    for(int i = 0; i < K; i++) {
        if(a[i].empty()) {
            continue;
        }

        int n = a[i].size();
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += a[i][j] ? 0 : 1;
        }
        if(cnt == n) {
            all_one = INF;
            break;
        }
        
        all_one += cnt;
    }

    for(int i = 0; i < K; i++) {
        if(a[i].empty()) {
            continue;
        }

        int n = a[i].size();
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += a[i][j];
        }

        if(n == 1 && cnt) {
            all_zero = INF;
            break;
        }
    
        if(cnt & 1) {
            all_zero += cnt == n ? cnt / 2 + 2 : (cnt - 1) / 2 + 2;
        } else {
            all_zero += cnt / 2;
        }
    }

    std::cout << std::min(all_one, all_zero) << '\n';
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
