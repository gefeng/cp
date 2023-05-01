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

    std::map<int, std::multiset<int>> b_m;
    std::map<int, std::set<int>> c_m;

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int C, B;
            std::cin >> C >> B;

            b_m[B].insert(C);
            c_m[C].insert(B);
        } else if(T == 2) {
            int B;
            std::cin >> B;

            for(int c : b_m[B]) {
                std::cout << c << ' ';
            }
            std::cout << '\n';
        } else {
            int C;
            std::cin >> C;
            
            for(int b : c_m[C]) {
                std::cout << b << ' ';
            }
            std::cout << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
