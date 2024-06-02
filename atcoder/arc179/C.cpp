#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    std::iota(a.begin(), a.end(), 1);

    auto query_c = [](int i, int j) {
        std::cout << "? " << i << ' ' << j << std::endl;
        int q;
        std::cin >> q;
        return q;
    };

    auto query_a = [](int i, int j) {
        std::cout << "+ " << i << ' ' << j << std::endl;
        int q;
        std::cin >> q;
        return q;
    };

    std::sort(a.begin(), a.end(), query_c);

    while(a.size() > 1) {
        std::vector<int> nxt;
        
        int t = query_a(a[0], a.back());
        assert(t != -1);

        int p = std::upper_bound(a.begin() + 1, a.end() - 1, t, query_c) - a.begin();

        for(int i = 1; i < a.size() - 1; i++) {
            if(i == p) {
                nxt.push_back(t);
            }
            nxt.push_back(a[i]);
        }

        if(p == a.size() - 1) {
            nxt.push_back(t); 
        }

        std::swap(a, nxt);
    }


    std::cout << "!" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
