#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int V, T, S, D;
    cin >> V >> T >> S >> D;

    int l = T * V;
    int r = S * V;
    
    cout << (D < l || D > r ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
