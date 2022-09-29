#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        if(i == 1) {
            cout << 1 << '\n';
        } else {
            cout << 1 << ' ';
            for(int j = 2; j < i; j++) {
                cout << 0 << ' ';
            }
            cout << 1 << '\n';
        }
    }
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
