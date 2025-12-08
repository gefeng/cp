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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<int> s;
    for(int x : A) {
        s.insert(x);
    }

    std::vector<int> b;
    std::set<int> picked;
    while(!s.empty()) {
        while(!s.empty() && picked.find(*s.begin()) != picked.end()) {
            s.erase(s.begin());
        }

        if(s.empty()) {
            break;
        }
        
        int x = *s.begin();
        
        for(int i = x; i <= K; i += x) {
            if(s.find(i) == s.end()) {
                std::cout << -1 << '\n';
                return;
            }
            picked.insert(i);
        }

        b.push_back(x);
    }

    int size = b.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << b[i] << " \n"[i == size - 1];
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
