#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int x = 0;
    array<int, 4> A = {0};

    cin >> x;
    for(int i = 1; i <= 3; i++) {
        cin >> A[i];
    } 

    bool canOpen = true;
    if(A[x] == 0 || A[1] == 1 || A[2] == 2 || A[3] == 3) {
        canOpen = false;
    }

    cout << (canOpen ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int _t = 0;
    cin >> _t;
    while(_t-- > 0) {
        run_case();
    }
}
