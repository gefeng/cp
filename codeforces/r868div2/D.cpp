#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(K);
    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < K; i++) {
        if(B[i] > A[i]) {
            std::cout << "NO" << '\n';
            return;
        }
        if(i && A[i] - A[i - 1] < B[i] - B[i - 1]) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::vector<std::pair<int, int>> v;
    v.emplace_back(A[0], B[0]);
    for(int i = 1; i < K; i++) {
        if(B[i] == B[i - 1]) {
            v.back().first = A[i];
        } else {
            v.emplace_back(A[i], B[i]);
        }
    }

    std::cout << "YES" << '\n';

    std::string ans = "";
    for(int i = 0; i < v[0].second - 2; i++) {
        ans.push_back('a');
    }

    ans.push_back('y');
    ans.push_back('z');
    
    char c1 = 'a';
    char c2 = 'y';
    for(int i = ans.size(); i < v[0].first; i += 3) {
        ans.push_back(c1);
        if(i + 1 < v[0].first) {
            ans.push_back(c2);
            c2 = c2 == 'y' ? 'z' : 'y';
        }
        if(i + 2 < v[0].first) {
            ans.push_back(c2);
            c2 = c2 == 'y' ? 'z' : 'y';
        }
    }
    
    int sz = v.size();
    for(int i = 1; i < sz; i++) {
        int d = v[i].second - v[i - 1].second - 1;

        c1 += 1;
        
        for(int j = 0; j < d; j++) {
            ans.push_back(c1);
        }

        for(int j = ans.size(); j < v[i].first; j += 3) {
            ans.push_back(c1);
            if(j + 1 < v[i].first) {
                ans.push_back(c2);
                c2 = c2 == 'y' ? 'z' : 'y';
            }
            if(j + 2 < v[i].first) {
                ans.push_back(c2); 
                c2 = c2 == 'y' ? 'z' : 'y';
            }
        }
    }

    std::cout << ans << '\n';
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
