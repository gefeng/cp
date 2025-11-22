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

    std::vector<int> pos(N + 1, 0);
    std::set<int> s;
    for(int i = 0; i < N; i++) {
        pos[A[i]] = i;
        s.insert(i + 1);
    }

    int max_v = 0;
    while(!s.empty()) {
        int v = *s.begin();
        int p = pos[v];
        
        std::vector<int> a;
        while(p < N && s.find(A[p]) != s.end()) {
            a.push_back(A[p++]);
        }

        if(v == 1) {
            for(int x : a) {
                s.erase(x);
                max_v = std::max(max_v, x);
            }
        } else {
            int nmax_v = 0;
            for(int x : a) {
                s.erase(x);
                nmax_v = std::max(nmax_v, x);
            }
            if(v > max_v) {
                std::cout << "No" << '\n';
                return;
            }
            max_v = std::max(max_v, nmax_v);
        }
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
