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

    string S;
    cin >> S;

    int x = 0;
    int y = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'U') {
            y += 1;
        } else if(S[i] == 'D') {
            y -= 1;
        } else if(S[i] == 'L') {
            x -= 1;
        } else {
            x += 1;
        }
        if(x == 1 && y == 1) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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
