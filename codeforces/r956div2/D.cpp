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
    std::vector<int> B(N);
    std::set<int> sa;
    std::set<int> sb;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sa.insert(A[i]);
    }
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        sb.insert(B[i]);
    }


    for(int x : sa) {
        if(sb.find(x) == sb.end()) {
            std::cout << "No" << '\n';
            return;
        }
    }

    for(int x : sb) {
        if(sa.find(x) == sa.end()) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::map<int, int> m;
    for(int x : A) {
        m[x] = 0;
    }
    int val = 0;
    for(auto& [_, v] : m) {
        v = val++;
    }

    for(int i = 0; i < N; i++) {
        A[i] = m[A[i]];
        B[i] = m[B[i]];
    }
    
    // for(int i = 0; i < N; i++) {
    //     std::cout << A[i] << " \n"[i == N - 1];
    // }
    // for(int i = 0; i < N; i++) {
    //     std::cout << B[i] << " \n"[i == N - 1];
    // }

    std::vector<int> pos_a(N, 0);
    std::vector<int> pos_b(N, 0);
    for(int i = 0; i < N; i++) {
        pos_a[A[i]] = i;
        pos_b[B[i]] = i; }

    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            continue;
        }

        if(i == N - 2) {
            std::cout << "No" << '\n';
            return;
        }

        int j = pos_b[A[i]];        
        if(j == N - 1) {
            pos_a[A[N - 1]] = N - 2;
            pos_a[A[N - 2]] = N - 1;
            pos_b[B[N - 1]] = N - 2;
            pos_b[B[N - 2]] = N - 1;
            std::swap(A[N - 1], A[N - 2]);
            std::swap(B[N - 1], B[N - 2]);
            j -= 1;
        }

        pos_a[A[i + 1]] = j + 1;
        pos_a[A[j + 1]] = i + 1;
        pos_b[B[i]] = j;
        pos_b[B[j]] = i; 
        std::swap(A[i + 1], A[j + 1]);
        std::swap(B[i], B[j]);
    }

    std::cout << "Yes" << '\n';
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
