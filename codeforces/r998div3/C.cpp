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
    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]] += 1;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(m.find(A[i]) != m.end()) {
            int t = K - A[i];
            if(t != A[i]) {
                if(m.find(t) != m.end()) {
                    ans += 1;
                    if(--m[t] == 0) {
                        m.erase(t);
                    }
                    if(--m[A[i]] == 0) {
                        m.erase(A[i]);
                    }
                }
            } else {
                if(m[t] > 1) {
                    ans += 1;
                    m[t] -= 2;
                    if(m[t] == 0) {
                        m.erase(t);
                    }
                }
            }
        }
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
