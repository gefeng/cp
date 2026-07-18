#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> ans(N, 0);
    
    int hb1 = 0;
    int hb2 = 0;
    for(int i = 30; i >= 0; i--) {
        if(N & (1 << i)) {
            hb1 = i;
            break;
        }
    }

    for(int i = 30; i >= 0; i--) {
        if(K & (1 << i)) {
            hb2 = i;
            break;
        }
    }

    if(hb2 > hb1) {
        std::cout << "NO" << '\n';
        return;
    }

    if(N == 1) {
        if(K == 1) {
            std::cout << "YES" << '\n' << 0 << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
        return;
    }
    
    if(K == N) {
        for(int i = 0; i < N - 1; i++) {
            ans[i] = i + 1;
        }
        ans[N - 1] = 0;
    } else if((K ^ N) < N) {
        for(int i = 0, j = 1; i < N - 2; i++) {
            if(j == (K ^ N)) {
                j++;
            }
            ans[i] = j++;
        }
        ans[N - 2] = 0;
        ans[N - 1] = K ^ N;
    } else {
        if(N == 2) {
            std::cout << "NO" << '\n';
            return;
        }

        int x = 0;
        int y = 0;
        int t = N ^ K;
        for(int i = 30; i >= 0; i--) {
            if((t & (1 << i)) && (x | (1 << i)) < N) {
                x |= 1 << i;
            }
        }
        
        y = t ^ x;
        if(y == x || y >= N) {
            std::cout << "NO" << '\n';
            return;
        }

        for(int i = 0, j = 1; i < N - 3; i++) {
            while(j == x || j == y) {
                j++;
            }
            ans[i] = j++;
        }
        ans[N - 3] = 0;
        ans[N - 2] = std::min(x, y);
        ans[N - 1] = std::max(x, y);
        
        assert((ans[N - 2] ^ ans[N - 1] ^ N) == K);
    }

    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
