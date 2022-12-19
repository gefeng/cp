#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_ok(vector<int>& A) {
    return A[0] < A[1] && A[0] < A[3] && A[1] < A[2] && A[3] < A[2];
}

void rotate(vector<int>& A) {
    int last = A[3];
    for(int i = 3; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = last;
}

void run_case() {
    vector<int> A(4);
    for(int i = 0; i < 4; i++) {
        cin >> A[i];
    }
    swap(A[2], A[3]);
    
    for(int i = 0; i < 4; i++) {
        if(is_ok(A)) {
            cout << "YES" << '\n';
            return;
        }
        rotate(A);
    }
    cout << "NO" << '\n';
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
