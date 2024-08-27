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

    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }

    std::vector<int> a;
    a.push_back(1);
    for(int i = 0; i < N; i++) {
        if(!G[i].empty()) {
            a.push_back(G[i].size());
        }
    }
    
    std::sort(a.begin(), a.end(), std::greater<int>());
    
    int size = a.size();
    int ans = size;
    for(int i = 0, j = size - 1; i < size; i++, j--) {
        a[i] -= 1;
        a[i] = std::max(0, a[i] - j);
    }

    std::vector<int> now;
    for(int i = 0; i < size; i++) {
        if(a[i]) {
            now.push_back(a[i]);
        }
    }

    while(!now.empty()) {
        std::vector<int> nxt;
        
        int m = now.size();
        int max_v = 0;
        int max_p = 0;
        for(int i = 0; i < m; i++) {
            if(now[i] > max_v) {
                max_v = now[i];
                max_p = i;
            }
            now[i] -= 1;
        }

        now[max_p] = std::max(0, now[max_p] - 1);

        for(int i = 0; i < m; i++) {
            if(now[i] > 0) {
                nxt.push_back(now[i]);
            }
        }

        std::swap(now, nxt);
        ans += 1;
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
