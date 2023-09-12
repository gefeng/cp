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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        indegree[A[i]] += 1;
    }

    if(K == 1) {
        for(int i = 0; i < N; i++) {
            if(A[i] != i) {
                std::cout << "NO" << '\n';
                return;
            }
        }
        std::cout << "YES" << '\n';
        return;
    }

    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        std::set<int> s;
        int cur = i;
        while(!vis[cur] && s.find(cur) == s.end()) {
            s.insert(cur);
            cur = A[cur];
        }

        if(!vis[cur]) {
            int len = 0;
            int head = cur;
            do {
                cur = A[cur];
                len += 1;
            } while(cur != head); 

            if(len != K) {
                std::cout << "NO" << '\n';
                return;
            }
        }

        for(int x : s) {
            vis[x] = 1;
        }
    }

    std::cout << "YES" << '\n';
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
