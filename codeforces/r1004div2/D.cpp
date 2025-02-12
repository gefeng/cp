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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    auto query = [](int i, int j) {
        std::cout << "? " << i + 1 << ' ' << j + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    auto output = [](char c) {
        std::cout << "! " << c << std::endl;
    };

    std::set<int> s(A.begin(), A.end()); 
    if(s.size() != N) {
        int j = -1;
        for(int i = 0; i < N; i++) {
            if(s.find(i) == s.end()) {
                j = i;
                break;
            }
        }

        output(query(j, *s.begin()) == 0 ? 'A' : 'B');
        return;
    }

    int x = -1;
    int y = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            x = i; 
        }
        if(A[i] == N - 1) {
            y = i;
        }
    }

    int res = query(x, y);
    if(res < N - 1) {
        output('A');
        return;
    }

    if(res > N - 1) {
        output('B');
        return;
    }

    res = query(y, x);
    output((res < 2 ? 'A' : 'B'));
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
