#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        indegree[A[i]] += 1;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> ans;
    std::vector<int> vis(N, 0);
    std::queue<int> q;
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        ans.push_back(v);
        vis[v] = 1;
        
        if(--indegree[A[v]] == 0) {
            q.push(A[v]);
        }
    }

    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        int min_v = INF;
        int last = -1;
        for(int j = i; !vis[j]; j = A[j]) {
            vis[j] = 1;
            if(B[j] < min_v) {
                min_v = B[j];
                last = j;
            }
        }

        for(int j = A[last]; j != last; j = A[j]) {
            ans.push_back(j);
        }
        ans.push_back(last);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
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
