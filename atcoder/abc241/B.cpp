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
    int N, M;
    cin >> N >> M;

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;

        m[X] += 1;
    }

    for(int i = 0; i < M; i++) {
        int X;
        cin >> X;
        
        if(m.find(X) == m.end()) {
            cout << "No" << '\n';
            return;
        }
        
        if(--m[X] == 0) {
            m.erase(X);
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
