#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    auto query = [](std::vector<int>& s, int x) {
        int size = s.size();
        std::cout << "? " << x + 1 << ' ' << size << ' ';

        for(int i = 0; i < size; i++) {
            std::cout << s[i] + 1 << ' ';
        }
        std::cout << std::endl;
        
        int Q;
        std::cin >> Q;
        return Q;
    };

    auto print = [](std::vector<int>& s) {
        int size = s.size();
        std::cout << "! " << size << ' ';
        for(int i = 0; i < size; i++) {
            std::cout << s[i] + 1 << ' ';
        }
        std::cout << std::endl;
    };

    std::vector<int> dist(N, 0);
    std::vector<int> all(N, 0);
    std::iota(all.begin(), all.end(), 0);

    int max_d = 0;
    for(int i = 0; i < N; i++) {
        dist[i] = query(all, i);        
        max_d = std::max(max_d, dist[i]);
    }

    std::vector<std::vector<int>> a(N + 1);
    for(int i = 0; i < N; i++) {
        a[dist[i]].push_back(i);
    }

    std::vector<int> path;
    int d = 2;
    path.push_back(a[max_d].front());
    
    for(int i = max_d - 1; i > 0; i--) {
        for(int v : a[i]) {
            path.push_back(v);
            int q = query(path, path[0]);
            if(q == d) {
                d += 1;
                break;
            }
            path.pop_back();
        } 
    }

    print(path);
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
