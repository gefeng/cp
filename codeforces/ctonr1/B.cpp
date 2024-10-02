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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    for(int x : A) {
        m[x] += 1; 
    } 

    for(int x : A) {
        if(--m[x] == 0) {
            m.erase(x);
        }
        if(m.find(x + K) != m.end()) {
            std::cout << "YES" << '\n';
            return;
        }
        m[x] += 1;
    }

    std::cout << "NO" << '\n';
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
