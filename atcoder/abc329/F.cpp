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
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::set<int>> A(N);
    for(int i = 0; i < N; i++) {
        int C;
        std::cin >> C;

        A[i].insert(C);
    }

    for(int i = 0; i < Q; i++) {
        int X, Y;
        std::cin >> X >> Y;
        X -= 1;
        Y -= 1;
    
        int size1 = A[X].size();
        int size2 = A[Y].size();
        if(size1 < size2) {
            for(int c : A[X]) {
                A[Y].insert(c);
            }
            A[X].clear();
        } else {
            for(int c : A[Y]) {
                A[X].insert(c); 
            }
            A[Y].clear();
            std::swap(A[X], A[Y]);
        }

        std::cout << A[Y].size() << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
