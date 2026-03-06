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
    
    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        A[i].resize(M, 0);
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> ans;

    std::vector<std::vector<int>> a(N);
    for(int i = 0; i < N; i++) {
        int m = A[i].size();
        std::set<int> s;
        for(int j = m - 1; j >= 0; j--) {
            if(s.find(A[i][j]) == s.end()) {
                a[i].push_back(A[i][j]);
                s.insert(A[i][j]);
            }
        }
    }

    std::set<int> seen;
    while(!a.empty()) {
        std::ranges::sort(a); 
        int n = a[0].size();
        for(int i = 0; i < n; i++) {
            ans.push_back(a[0][i]);
            seen.insert(a[0][i]);
        }
        
        std::vector<std::vector<int>> b;
        n = a.size();
        for(int i = 0; i < n; i++) {
            std::vector<int> c;
            int m = a[i].size();
            for(int j = 0; j < m; j++) {
                if(seen.find(a[i][j]) == seen.end()) {
                    c.push_back(a[i][j]); 
                }
            }
            if(!c.empty()) {
                b.push_back(c);
            }
        }
        a = std::move(b);
    }

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
