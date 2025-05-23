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
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    } 

    auto solve = [N, &B](std::vector<int>& cycle) {
        int n = cycle.size(); 
        std::vector<int> divisors;
        for(int f = 1; f * f <= n; f++) {
            if(n % f == 0) {
                divisors.push_back(f);
                if(n / f != f) {
                    divisors.push_back(n / f);
                }
            }
        }

        int res = N;
        for(int d : divisors) {
            std::vector<int> vis(n, 0);
            for(int i = 0; i < d; i++) {
                int now = i;
                int color = -1;
                bool ok = true;
                while(!vis[now]) {
                    if(color != -1 && B[cycle[now]] != color) {
                        ok = false;
                        break;
                    }
                    color = B[cycle[now]];
                    vis[now] = 1;
                    now = (now + d) % n;
                }

                if(ok) {
                    res = std::min(res, d);
                    break;
                }
            }
        }
        return res;
    };

    std::vector<int> vis(N, 0);
    int ans = N;
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        int now = i;
        std::vector<int> cycle;
        while(!vis[now]) {
            vis[now] = 1;
            cycle.push_back(now);
            now = A[now];
        }

        ans = std::min(ans, solve(cycle));
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
