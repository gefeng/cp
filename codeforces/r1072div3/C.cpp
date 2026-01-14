#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(K > N) {
        std::cout << -1 << '\n';
        return;
    }

    std::queue<int> q;
    std::set<int> s;
    int d = 0;
    q.push(N);
    s.insert(N);
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int now = q.front();
            q.pop();
            if(now == K) {
                std::cout << d << '\n';
                return;
            }
            
            for(int i = 0; i < 2; i++) {
                int x = (now + i) / 2;
                if(s.find(x) == s.end() && x >= K) {
                    s.insert(x);
                    q.push(x);
                }
            }
        }
        d += 1;
    }

    std::cout << -1 << '\n';
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
