#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    set<int> seen;

    bool ok = true;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if(seen.find(X) != seen.end()) {
            ok = false;
        }
        seen.insert(X);
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
