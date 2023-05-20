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
    int N, Q;
    std::cin >> N >> Q;

    std::map<int, std::set<int>> m;
    int cnt = N;

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int U, V;
            std::cin >> U >> V;

            m[U].insert(V);
            m[V].insert(U);

            if(m[U].size() == 1) {
                cnt -= 1;
            }
            if(m[V].size() == 1) {
                cnt -= 1;
            }
        } else {
            int V;
            std::cin >> V;

            for(int nei : m[V]) {
                m[nei].erase(V); 
                if(m[nei].empty()) {
                    cnt += 1; 
                }
            }

            if(!m[V].empty()) {
                m[V] = std::set<int>();
                cnt += 1;
            }
        }

        std::cout << cnt << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
