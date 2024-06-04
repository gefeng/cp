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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<int> s;
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        s.insert(B[i]);
    }

    int M;
    std::cin >> M;
    std::vector<int> C(M);
    for(int i = 0; i < M; i++) {
        std::cin >> C[i];
    }

    std::map<int, int> m;
    for(int x : C) {
        m[x] += 1;
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            if(m.find(B[i]) == m.end()) {
                std::cout << "No" << '\n';
                return;
            }            
            if(--m[B[i]] == 0) {
                m.erase(B[i]);
            }
        }
    } 
    
    for(int i = M - 1; i >= 0; i--) {
        if(s.find(C[i]) != s.end()) {
            break;
        }
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
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
