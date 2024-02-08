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
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::set<int> sa;
    std::set<int> sb;
    for(int x : A) {
        sa.insert(x);
    }

    for(int x : B) {
        sb.insert(x);
    }

    int cnta = 0;
    int cntb = 0;
    int cntab = 0;
    std::set<int> s;
    for(int i = 1; i <= K; i++) {
        if(sa.find(i) != sa.end() && sb.find(i) == sb.end() && cnta < K / 2) {
            cnta += 1;
            s.insert(i);
        }

        if(sb.find(i) != sb.end() && sa.find(i) == sa.end() && cntb < K / 2) {
            cntb += 1;
            s.insert(i);
        }
    }

    for(int i = 1; i <= K; i++) {
        if(sa.find(i) != sa.end() && sb.find(i) != sb.end()) {
            cntab += 1;
        }
    }

    std::cout << (cnta + cntb + cntab == K ? "Yes" : "No") << '\n';
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
