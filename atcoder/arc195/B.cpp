#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int cnt = 0;
    std::vector<int> a;
    std::vector<int> b;
    for(int i = 0; i < N; i++) {
        if(A[i] == -1) {
            cnt += 1;
        } else {
            a.push_back(A[i]);
        }
        if(B[i] == -1) {
            cnt += 1;
        } else {
            b.push_back(B[i]);
        }
    }

    if(cnt >= N) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), std::greater<int>());

    std::map<int, int> freq;
    int max_f = 0;
    int t = 0;
    for(int x : a) {
        for(int y : b) {
            if(++freq[x + y] > max_f && x + y >= b[0] && x + y >= a.back()) {
                max_f = freq[x + y];
                t = x + y;
            }
        }
    }

    std::map<int, int> ma;
    std::map<int, int> mb;
    for(int x : a) {
        ma[x] += 1;
    }
    for(int x : b) {
        mb[x] += 1;
    }

    int cnt_a = N - a.size();
    int cnt_b = N - b.size();
    for(auto [x, fx] : ma) {
        int y = t - x;
        int fy = mb.find(y) == mb.end() ? 0 : mb[y];

        int d = std::min(fx, fy);
        fx -= d;
        fy -= d;

        if(fx) {
            cnt_b -= fx;
        }
        if(fy) {
            cnt_a -= fy;
        }

        if(cnt_a < 0 || cnt_b < 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
