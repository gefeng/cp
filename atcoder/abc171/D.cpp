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
    int N;
    cin >> N;

    map<int, int> m;
    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        m[X] += 1;
        sum += X;
    }


    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int B, C;
        cin >> B >> C;

        if(m.find(B) != m.end()) {
            sum -= 1LL * B * m[B];
            sum += 1LL * C * m[B];
            m[C] += m[B]; 
            m.erase(B);
        }

        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
