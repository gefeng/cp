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
    double K, L;
    std::cin >> N >> K >> L;
    
    std::vector<double> A(N);
    std::multiset<double> ms;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        ms.insert(A[i]);
    }

    double t = A[0];
    double p = K;
    ms.erase(ms.find(A[0]));
    while(p < L) {
        auto it = ms.lower_bound(p - t - K + 1);
        if(it != ms.end() && *it <= p) {
            p = std::min(p, *it + t) + K;
            ms.erase(it);
            continue;
        }

        it = ms.lower_bound(p);
        if(it == ms.end()) {
            t += L - p;
            break;
        }

        double sc = *it;
        ms.erase(it);

        if(sc - t <= p) {
            p += K;
            continue;
        }
        
        sc -= t;

        double need = (sc - p) / 2;
        t += need;
        p += need;
        p += K;
    }

    std::cout << int64_t(t * 2) << '\n';
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
