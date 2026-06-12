#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto is_good = [&]() {
        std::set<int> seen;
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i++;
            }
            if(seen.find(A[j]) != seen.end()) {
                return false;
            }
            seen.insert(A[j]);
        }
        return true;
    };

    if(is_good()) {
        std::cout << "YES" << '\n';
        return;
    }


    std::set<int> bad;
    std::set<int> seen;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i++;
        }
        if(seen.find(A[j]) != seen.end()) {
            bad.insert(A[j]);
        }
        seen.insert(A[j]);
    }

    auto solve = [&](int p) {
        std::vector<std::pair<int, int>> a;
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i++;
            }
            if(A[j] == A[p]) {
                a.emplace_back(j, i - 1);
            }
        }

        if(a.size() > 3) {
            return false;
        }
        
        for(auto [l, r] : a) {
            for(auto [x, y] : a) {
                if(x) {
                    std::swap(A[l], A[x - 1]);
                    if(is_good()) {
                        return true;
                    }
                    std::swap(A[l], A[x - 1]);

                    std::swap(A[r], A[x - 1]);
                    if(is_good()) {
                        return true;
                    }
                    std::swap(A[r], A[x - 1]);
                    
                }
                if(y + 1 < N) {
                    std::swap(A[l], A[y + 1]);
                    if(is_good()) {
                        return true;
                    }
                    std::swap(A[l], A[y + 1]);

                    std::swap(A[r], A[y + 1]);
                    if(is_good()) {
                        return true;
                    }
                    std::swap(A[r], A[y + 1]);
                }
            }
        }

        return false;
    };

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i++;
        }
        if(bad.find(A[j]) != bad.end()) {
            if(solve(j)) {
                std::cout << "YES" << '\n';
                return;
            }
            break;
        }
    }

    if(bad.size() == 1) {
        int t = *bad.begin();
        std::vector<std::pair<int, int>> a;
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i++;
            }
            if(A[j] == t) {
                a.emplace_back(j, i - 1);
            }
        }
        if(a.size() == 2 && a[0].second + 2 == a[1].first) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
