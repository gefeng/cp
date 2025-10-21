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

    std::vector<std::pair<int, int>> tables;
    std::vector<std::pair<int, int>> cells;
    
    int d = 2;
    while(tables.size() < N) {
        int t = (d - 2) / 3;
        
        for(int x = 0; x <= t; x++) {
            int y = t - x;
            tables.emplace_back(3 * x + 1, 3 * y + 1);
            cells.emplace_back(3 * x + 1, 3 * y + 1); 
            cells.emplace_back(3 * x + 1, 3 * y + 2); 
            cells.emplace_back(3 * x + 2, 3 * y + 1); 
            cells.emplace_back(3 * x + 2, 3 * y + 2); 
        }

        d += 3;
    }

    auto cmp = [](const auto& x, const auto& y) {
        int d_x = x.first % 3 == 2 && x.second % 3 == 2 ? x.first + x.second + 2 : x.first + x.second;
        int d_y = y.first % 3 == 2 && y.second % 3 == 2 ? y.first + y.second + 2 : y.first + y.second;
        if(d_x == d_y) {
            if(x.first == y.first) {
                return x.second < y.second;
            }
            return x.first < y.first;
        }
        return d_x < d_y;
    };

    std::sort(tables.begin(), tables.end(), cmp);
    std::sort(cells.begin(), cells.end(), cmp);

    int j = 0;
    int k = 0;
    std::set<std::pair<int, int>> s_1; // taken cells
    std::set<std::pair<int, int>> s_2; // taken tables
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            while(k < cells.size() && s_1.find({cells[k].first, cells[k].second}) != s_1.end()) {
                k += 1;
            }
            std::cout << cells[k].first << ' ' << cells[k].second << '\n';
            s_1.emplace(cells[k].first, cells[k].second);
            s_2.emplace(cells[k].first / 3, cells[k].second / 3);
            k += 1;
        } else {
            while(j < tables.size() && s_2.find({tables[j].first / 3, tables[j].second / 3}) != s_2.end()) {
                j += 1;
            }
            std::cout << tables[j].first << ' ' << tables[j].second << '\n';
            s_1.emplace(tables[j].first, tables[j].second);
            s_2.emplace(tables[j].first / 3, tables[j].second / 3);
            j += 1;
        }
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
