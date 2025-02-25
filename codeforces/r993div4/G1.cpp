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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    int ans = 0;
    std::vector<int> dist(N, -1);
    for(int i = 0; i < N; i++) {
        if(dist[i] != -1) {
            continue; 
        }

        int v = i;
        int d = 0;
        std::set<int> s;
        while(true) {
            if(dist[v] != -1) {
                break;
            }
            if(s.find(v) != s.end()) {
                break;
            }
            s.insert(v);
            d += 1;
            v = A[v];
        }

        if(dist[v] != -1) {
            int x = dist[v];
            v = i;
            while(dist[v] == -1) {
                dist[v] = d + x;
                d -= 1;
                v = A[v];
            }
        } else {
            std::set<int> cycle;
            while(cycle.find(v) == cycle.end()) {
                dist[v] = 0;
                cycle.insert(v);
                v = A[v];
            }
            v = i;
            d = 0;
            while(dist[v] == -1) {
                d += 1;
                v = A[v];
            }
            v = i;
            while(dist[v] == -1) {
                dist[v] = d;
                d -= 1;
                v = A[v];
            }
        }
    }

    for(int i = 0; i < N; i++) {
        ans = std::max(ans, dist[i]);
    }

    std::cout << ans + 2 << '\n';
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
