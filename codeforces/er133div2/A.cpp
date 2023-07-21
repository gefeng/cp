#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    if(N == 1) {
        cout << 2 << '\n';
    } else if(N == 2 || N == 3) {
        cout << 1 << '\n';
    } else {
        if(N % 3 == 1) {
            cout << (2 + (N - 4) / 3) << '\n';
        } else if(N % 3 == 2) {
            cout << (1 + (N - 1) / 3) << '\n';
        } else {
            cout << (N / 3) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
