#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N, W;
    cin >> N >> W;

    map<int, LL> m;
    for(int i = 0; i < N; i++) {
        int S, T, P;
        cin >> S >> T >> P;
        
        m[S] += P;
        m[T] -= P;
    }

    LL sum = 0LL;
    for(auto& [k, v] : m) {
        sum += v;
        if(sum > W) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
