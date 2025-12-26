#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case_1() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> dist(N, INF);
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;
    
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int v = q.front();
            q.pop();
            
            for(int nei : G[v]) {
                if(dist[nei] > dist[v] + 1) {
                    dist[nei] = dist[v] + 1;
                    q.push(nei);
                }
            }
        }
    }

    std::string output(N, 'r');
    for(int i = 0; i < N; i++) {
        if(dist[i] % 3 == 0) {
            output[i] = 'r';
        } else if(dist[i] % 3 == 1) {
            output[i] = 'g';
        } else {
            output[i] = 'b';
        }
    }
    std::cout << output << std::endl;
}

void run_case_2() {
    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int N;
        std::cin >> N;

        std::string S;
        std::cin >> S;

        std::array<int, 3> a = {};

        for(int i = 0; i < N; i++) {
            if(S[i] == 'r') {
                a[0] += 1;
            } else if(S[i] == 'g') {
                a[1] += 1;
            } else {
                a[2] += 1;
            }
        }

        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            cnt += a[i] ? 1 : 0;
        }

        if(cnt == 1) {
            std::cout << 1 << '\n';
            continue;
        }

        assert(cnt == 2);

        char c = 'r';
        for(int i = 0; i < 3; i++) {
            if(a[i] == 0) {
                if(i == 0) {
                    c = 'b';
                } else if(i == 1) {
                    c = 'r';
                } else {
                    c = 'g';
                }
                break;
            }
        }

        for(int i = 0; i < N; i++) {
            if(S[i] == c) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    std::cin >> S;
    
    if(S == "first") {
        int T;
        std::cin >> T;
        while(T--) {
            run_case_1();
        }
    } else {
        int T;
        std::cin >> T;
        while(T--) {
            run_case_2();
        }
    }
    
}
