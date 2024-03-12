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
    int N, M, X;
    std::cin >> N >> M >> X;
    X -= 1;
    
    std::set<int> cur;
    cur.insert(X);

    for(int i = 0; i < M; i++) {
        std::set<int> nxt;
        int C;
        char D;
        std::cin >> C >> D;

        for(int p : cur) {
            if(D == '1') {
                nxt.insert((p - C + N) % N);
            } else if(D == '0') {
                nxt.insert((p + C) % N);
            } else {
                nxt.insert((p - C + N) % N);
                nxt.insert((p + C) % N);
            }
        }

        std::swap(nxt, cur);
    }

    int k = cur.size();
    std::cout << k << '\n';
    for(int p : cur) {
        std::cout << p + 1 << ' ';
    }
    std::cout << '\n';
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
