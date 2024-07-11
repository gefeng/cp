#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    for(int i = 0; i < N; ) {
        std::set<int> s;
        while(i < N) {
            if(A[i] == 1 || X % A[i] != 0) {
                i += 1;
                continue;
            }

            if(s.find(X / A[i]) != s.end()) {
                break;
            }

            std::set<int> ns(s);
            ns.insert(A[i]);
            
            for(int x : s) {
                if(X % (x * A[i]) == 0) {
                    ns.insert(x * A[i]);
                }
            }
            std::swap(ns, s);
            i += 1;
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
