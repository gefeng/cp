#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> A(K);
    for(int i = 0; i < K; i++) {
        int M;
        std::cin >> M;

        A[i].resize(M, 0);
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            A[i][j] -= 1;
        }
    }

    auto query = [](std::vector<int>& a) {
        std::cout << "? ";   
        int size = a.size();
        std::cout << size << ' ';
        for(int i = 0; i < size; i++) {
            std::cout << a[i] + 1;
            if(i != size - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
        
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> a(N);
    std::iota(a.begin(), a.end(), 0);

    int max_v = query(a);

    int lo = 0;
    int hi = N - 1;
    int p = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        a.clear();
        for(int i = lo; i <= mid; i++) {
            a.push_back(i);
        }

        int v = query(a);
        
        if(v == max_v) {
            p = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::vector<int> ans(K, 0);
    for(int i = 0; i < K; i++) {
        bool found = false;
        for(int x : A[i]) {
            if(x == p) {
                found = true;
                break;
            }
        }

        if(!found) {
            ans[i] = max_v; 
        } else {
            a.clear();
            int m = A[i].size();
            std::sort(A[i].begin(), A[i].end());
            for(int k = 0, j = 0; k < N; k++) {
                if(j == m || A[i][j] != k) {
                    a.push_back(k);
                } else {
                    j += 1;
                }
            }
            ans[i] = query(a);
        }
    }

    std::cout << "! ";
    for(int i = 0; i < K; i++) {
        std::cout << ans[i];
        if(i != K - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
    
    std::string S;
    std::cin >> S;

    assert(S == "Correct");
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
