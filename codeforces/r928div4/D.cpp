#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    for(int x : A) {
        m[x] += 1; 
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x = A[i]; 
        if(m.find(x) == m.end()) {
            continue;
        }

        int y = 0;
        for(int i = 0; i <= 30; i++) {
            int b = x & (1 << i) ? 1 : 0;
            y |= (b ^ 1) << i;
        }

        if(--m[x] == 0) {
            m.erase(x);
        }
        if(m.find(y) != m.end()) {
            if(--m[y] == 0) {
                m.erase(y);
            }
        }

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
