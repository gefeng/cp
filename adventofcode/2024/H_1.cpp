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
    std::vector<std::string> A;
    for(std::string S; std::getline(std::cin, S); ) {
        A.push_back(S);
    }

    int n = A.size();
    int m = A[0].size();
    
    std::map<int, std::vector<std::pair<int, int>>> fm;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] != '.') {
                fm[A[i][j]].emplace_back(i, j);
            }
        }
    }

    for(auto& [c, p] : fm) {
        int size = p.size();
        
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                int dx = p[i].first - p[j].first;
                int dy = p[i].second - p[j].second;
                
                int x1 = p[i].first + dx;
                int y1 = p[i].second + dy;
                int x2 = p[j].first - dx;
                int y2 = p[j].second - dy;

                if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < m) {
                    A[x1][y1] = '#';
                }

                if(x2 >= 0 && y2 >= 0 && x2 < n && y2 < m) {
                    A[x2][y2] = '#';
                }
            } 
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == '#') {
                ans += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
