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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end());
    
    std::map<int, int> m;
    for(int i = N - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && A[i].first == A[j].first) {
            i -= 1;
        }

        for(int k = j; k > i; k--) {
            int p = k;
            while(k - 1 > i && A[k - 1].second + 1 == A[k].second) {
                k -= 1;
            }
            // [k to p]
            int l = A[k].second;
            int r = A[p].second;
            
            auto it = m.upper_bound(r);
            if(it != m.end() && it->first - 1 == r) {
                int rr = it->second;
                m.erase(it);
                m[l] = rr;
                continue; 
            }
            
            if(it != m.begin()) {
                it--;
                if(it->second + 1 == l) {
                    it->second = r;
                    continue;
                }
            }

            m[l] = r;
        }
    }

    std::cout << m.size() << '\n';
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
