#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<char, 3> A;
    array<char, 3> B;

    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < 3; i++) {
        cin >> B[i];
    }

    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        if(A[i] != B[i]) {
            cnt += 1;
        }
    }

    if(cnt == 0) {
        cout << "Yes" << '\n';
    } else if(cnt == 2) {
        cout << "No" << '\n'; 
    } else {
        cout << "Yes" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
