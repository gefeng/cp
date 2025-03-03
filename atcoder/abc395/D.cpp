#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <set>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::set<int>> nest(N);
    std::vector<int> label(N, 0); // idx -> label
    std::vector<int> pos(N, 0); // label -> idx
    std::vector<int> where(N, 0);
    for(int i = 0; i < N; i++) {
        nest[i].insert(i);
        where[i] = i;
        pos[i] = i;
    }

    std::iota(label.begin(), label.end(), 0);

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int A, B;
            std::cin >> A >> B;
            A -= 1;
            B -= 1;
            int pre_p = where[A];
            int new_p = pos[B];  
            nest[pre_p].erase(A);
            nest[new_p].insert(A); 
            where[A] = new_p;
        } else if(T == 2) {
            int A, B;
            std::cin >> A >> B;
            A -= 1;
            B -= 1;
            int pos_a = pos[A];
            int pos_b = pos[B];
            label[pos_a] = B;
            label[pos_b] = A;
            pos[A] = pos_b;
            pos[B] = pos_a;
        } else {
            int A;
            std::cin >> A;
            A -= 1;
            std::cout << label[where[A]] + 1 << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
