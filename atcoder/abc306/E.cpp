#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using LL = long long;

void run_case() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    std::map<int, std::set<int>> m1;
    std::map<int, std::set<int>> m2;
    std::vector<int> where(N, 0);
    std::vector<int> A(N, 0);
    for(int i = 0; i < K; i++) {
        m1[0].insert(i);
        where[i] = 1;
    }

    for(int i = K; i < N; i++) {
        m2[0].insert(i);
        where[i] = 2;
    }

    LL sum = 0LL;
    for(int i = 0; i < Q; i++) {
        int X, Y;
        std::cin >> X >> Y;
        X -= 1;

        if(where[X] == 1) {
            int v = A[X]; 
            m1[v].erase(X);
            if(m1[v].empty()) {
                m1.erase(v);
            }
            sum -= v;

            m1[Y].insert(X);
            sum += Y;

            A[X] = Y;
        } else {
            int v = A[X];
            m2[v].erase(X);
            if(m2[v].empty()) {
                m2.erase(v);
            }

            m2[Y].insert(X);
            A[X] = Y;
        }

        if(m1.begin()->first < m2.rbegin()->first) {
            int v1 = m1.begin()->first;
            int p1 = *m1.begin()->second.begin();
            int v2 = m2.rbegin()->first;
            int p2 = *m2.rbegin()->second.begin();

            m1[v1].erase(p1);
            m2[v2].erase(p2);
            if(m1[v1].empty()) {
                m1.erase(v1);
            }
            if(m2[v2].empty()) {
                m2.erase(v2);
            }

            m1[v2].insert(p2);
            m2[v1].insert(p1);

            sum -= v1;
            sum += v2;

            where[p1] = 2;
            where[p2] = 1;
        }

        std::cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
