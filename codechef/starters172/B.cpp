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
    }
    
    // odd: or
    // eve: and
    std::set<int> odd;
    std::set<int> eve;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0 && A[i] == 1) {
            eve.insert(i);
        }
        if(i % 2 == 1 && A[i] == 0) {
            odd.insert(i);
        }
    }
    
    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;

        if(P % 2 == 0 && A[P] == 1) {
            eve.erase(P);
        }
        if(P % 2 == 1 && A[P] == 0) {
            odd.erase(P);
        }

        A[P] = X;
        if(P % 2 == 0 && A[P] == 1) {
            eve.insert(P);
        }
        if(P % 2 == 1 && A[P] == 0) {
            odd.insert(P);
        }

        int res = 0;
        if(!eve.empty() && (odd.empty() || *eve.rbegin() > *odd.rbegin())) {
            res = 1; 
        }
        std::cout << res << '\n';
    }
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
