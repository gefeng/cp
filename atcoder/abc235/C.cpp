#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    map<int, vector<int>> m;
    for(int i = 0; i < N; i++) {
        int X; 
        cin >> X;
        
        m[X].push_back(i);
    }

    for(int i = 0; i < Q; i++) {
        int X, K;
        cin >> X >> K;

        if(m.find(X) == m.end()) {
            cout << -1 << '\n';
            continue;
        }
        
        vector<int>& v = m[X];
        if(K - 1 >= v.size()) {
            cout << -1 << '\n';
            continue;
        }

        cout << v[K - 1] + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
