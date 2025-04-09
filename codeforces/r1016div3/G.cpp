#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(K == 0) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<std::array<int, 2>> nxt;
    std::vector<int> val;
    nxt.push_back({-1, -1});
    val.push_back(0);
    
    auto add = [&](int x, int idx) {
        int now = 0;
        for(int i = 30; i >= 0; i--) {
            int b = x & (1 << i) ? 1 : 0;
            if(nxt[now][b] == -1) {
                nxt.push_back({-1, -1});
                val.push_back(idx);
                nxt[now][b] = nxt.size() - 1;
            } 
            now = nxt[now][b];
            val[now] = std::max(val[now], idx);
        }
    };

    auto query = [&](int x) {
        int now = 0;
        int j = -1;
        for(int i = 30; i >= 0; i--) {
            int b_1 = x & (1 << i) ? 1 : 0;
            int b_2 = K & (1 << i) ? 1 : 0; 
            if(b_2 == 0) {
                int b = b_1 ^ 1;
                if(nxt[now][b] != -1) {
                    j = std::max(j, val[nxt[now][b]]);     
                }
                if(nxt[now][b_1] == -1) {
                    break;
                }
                now = nxt[now][b_1];
                if(i == 0) {
                    j = std::max(j, val[now]);
                }
            } else {
                int b = b_1 ^ 1;
                if(nxt[now][b] == -1) {
                    break;
                }
                now = nxt[now][b];
                if(i == 0) {
                    j = std::max(j, val[now]);
                } 
            }
        }
        return j;
    };

    int ans = INF;
    for(int i = 0; i < N; i++) {
        int j = query(A[i]);

        if(j != -1) {
            ans = std::min(ans, i - j + 1);
            //std::cout << i << ' ' << i - j + 1 << '\n';
        }
        
        add(A[i], i);
    }

    ans = ans == INF ? -1 : ans;

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
