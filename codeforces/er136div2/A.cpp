#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    if(N == 1 || M == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    } 

    if(N == 2 && M < 4) {
        cout << 1 << ' ' << 2 << '\n'; 
        return;
    }

    if(M == 2 && N < 4) {
        cout << 2 << ' ' << 1 << '\n';
        return;
    }

    if(N == 3 && N == 3) {
        cout << 2 << ' ' << 2 << '\n';
        return;
    }

    cout << 1 << ' ' << 1 << '\n';
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
