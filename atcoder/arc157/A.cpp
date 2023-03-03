#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    
    if(abs(B - C) > 1) {
        cout << "No" << '\n';
        return;
    }

    if(A && D && !B && !C) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
