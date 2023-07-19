#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<int, 3> A;
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    if((A[1] - A[0]) % 2 == 1 || (A[2] - A[1]) % 2 == 1) {
        cout << -1 << '\n';
        return;
    }

    if(A[0] == A[1] && A[1] == A[2]) {
        cout << 0 << '\n';
        return;
    }

    int x = (A[1] - A[0] + 1) / 2;
    int y = (A[2] - A[1] + 1) / 2;
    int z = (A[2] - A[0] + 4 - 1) / 4;
    int d = min(min(x, y), z);

    A[0] += 7 * d;
    A[1] += 5 * d;
    A[2] += 3 * d;

    sort(A.begin(), A.end());
    
    x = min(A[0], A[1]);
    y = max(A[1], A[2]);

    if((y - x) % 6 == 0) {
        cout << d + (y - x) / 6 * 2 << '\n'; 
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
