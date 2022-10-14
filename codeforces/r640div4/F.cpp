#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<int, 3> A{0};
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    string ans = "";
    for(int i = 0; i < A[0]; i++) {
        ans.push_back('0');
    }

    for(int i = 0; i < (A[1] + 1) / 2; i++) {
        ans.append("01");
    }

    for(int i = 0; i < A[2]; i++) {
        ans.push_back('1'); 
    }

    if(A[1] % 2 == 0 && A[1] > 0) {
        ans.push_back('0'); 
    }

    if(A[1] == 0) {
        ans.push_back(A[0] == 0 ? '1' : '0');
    }

    cout << ans << '\n';
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
