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
    int N, Q;
    cin >> N >> Q;

    set<int> waiting;
    set<int> called;

    for(int i = 1; i <= N; i++) {
        waiting.insert(i);
    }
    
    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;

        if(T == 1) {
            int p = *waiting.begin();
            called.insert(p);
            waiting.erase(p);
        } else if(T == 2) {
            int X;
            cin >> X;

            called.erase(X);
        } else {
            cout << *called.begin() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
