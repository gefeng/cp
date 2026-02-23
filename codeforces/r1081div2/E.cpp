#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<std::vector<int>> pa(N + 1);    
    std::vector<std::vector<int>> pb(N + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pa[A[i]].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        pb[B[i]].push_back(i);
    }

    std::vector<int> ans;
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        int now = i;
        while(true) {
            vis[now] = 1;
            int v = B[now];

            while(!pa[v].empty() && vis[pa[v].back()]) {
                pa[v].pop_back();
            }
            
            if(pa[v].empty()) {
                while(!pb[v].empty() && vis[pb[v].back()]) {
                    pb[v].pop_back();
                }
                if(pb[v].empty()) {
                    break;
                }
                now = pb[v].back();
                pb[v].pop_back();
                ans.push_back(now);
                std::swap(A[now], B[now]);
            } else {
                now = pa[v].back();
                pa[v].pop_back();
            }
        }
    }

    std::vector<int> fa(N + 1, 0);
    std::vector<int> fb(N + 1, 0);
    for(int i = 0; i < N; i++) {
        fa[A[i]] += 1;
        fb[B[i]] += 1;
    }

    for(int x = 1; x <= N; x++) {
        if(fa[x] != fb[x]) {
            std::cout << -1 << '\n';
            return;
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
