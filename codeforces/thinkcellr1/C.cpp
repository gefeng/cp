#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::set<int> missing;
    std::set<int> s;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] += i + 1;
        missing.insert(A[i]);
    } 

    for(int i = N - 1; i >= 0; i--) {
        if(s.find(A[i]) == s.end()) {
            s.insert(A[i]);
            missing.erase(A[i]);
            
            if(s.find(A[i] - 1) == s.end()) {
                missing.insert(A[i] - 1);
            }
        } else {
            auto it = missing.upper_bound(A[i]); 
            if(it != missing.begin()) {
                it--;
                int v = *it;
                s.insert(v);
                missing.erase(v);
                
                if(s.find(v - 1) == s.end()) {
                    missing.insert(v - 1);
                }
            }
        }
    }

    while(!s.empty()) {
        std::cout << *s.rbegin() << ' ';
        s.erase(*s.rbegin());
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
