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

    std::vector<int> pre(N, -1);
    std::vector<int> nxt(N, N);

    std::set<std::pair<int, int>> s;
    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            std::swap(A[i], B[i]);
        }
        s.emplace(A[i], i);
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }

    while(s.size() > 1) {
        auto [x, i] = *s.begin();
        s.erase(s.begin());

        int l = pre[i];
        int r = nxt[i];

        if(l == -1 || (l != -1 && r != N && A[r] <= A[l])) {
            int j = r;
            std::array<int, 3> a = {B[i], A[j], B[j]};
            std::ranges::sort(a);
            
            s.erase({A[j], j});

            A[i] = a[0];
            B[i] = a[1];
            nxt[i] = nxt[j];
            if(nxt[i] != N) {
                pre[nxt[i]] = i;
            }
            s.emplace(A[i], i);
        } else {
            int j = pre[i];
            std::array<int, 3> a = {B[i], A[j], B[j]};
            std::ranges::sort(a);
            
            s.erase({A[j], j});
            
            A[j] = a[0];
            B[j] = a[1];
            nxt[j] = nxt[i];
            if(nxt[j] != N) {
                pre[nxt[j]] = j;
            }
            s.emplace(A[j], j);
        }
    }

    std::cout << s.begin()->first << '\n';
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
