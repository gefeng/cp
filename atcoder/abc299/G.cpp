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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> left;
    std::set<int> have;
    for(int i = 0; i < N; i++) {
        left[A[i]] += 1;
    }

    std::vector<int> s;
    for(int i = 0; i < N; i++) {
        while(!s.empty() && s.back() > A[i] && left.find(s.back()) != left.end() && have.find(A[i]) == have.end()) {
            have.erase(s.back());
            s.pop_back();
        }
        
        if(have.find(A[i]) == have.end()) {
            have.insert(A[i]);
            s.push_back(A[i]);
        }

        if(--left[A[i]] == 0) {
            left.erase(A[i]);
        }
    } 
    
    for(int i = 0; i < M; i++) {
        std::cout << s[i] << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
