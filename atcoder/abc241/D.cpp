#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int Q;
    cin >> Q;

    multiset<LL> s;
    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        
        if(T == 1) {
            LL X;
            cin >> X;

            s.insert(X); 
        } else if(T == 2) {
            LL X, K;
            cin >> X >> K;

            auto it = s.upper_bound(X);
            while(it != s.begin() && K) {
                it--;
                K -= 1;
            }

            if(K) {
                cout << -1 << '\n';
            } else {
                cout << *it << '\n';
            }
        } else if(T == 3) {
            LL X, K;
            cin >> X >> K;

            K -= 1;

            auto it = s.lower_bound(X);
            while(it != s.end() && K) {
                it++;    
                K -= 1;
            }

            if(K || it == s.end()) {
                cout << -1 << '\n';
            } else {
                cout << *it << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
