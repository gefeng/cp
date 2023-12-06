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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
    }

    std::map<int, int> m;
    for(int x : A) {
        m[x] += 1;
    }

    std::set<int> s;
    for(int i = 0; i <= N + 10; i++) {
        if(m.find(i) == m.end()) {
            s.insert(i);
        }
    }

    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;

        if(--m[A[P]] == 0) {
            m.erase(A[P]);
            s.insert(A[P]);
        } 
        
        A[P] = X;
        m[X] += 1;
        if(s.find(X) != s.end()) {
            s.erase(X);
        }

        std::cout << *s.begin() << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
