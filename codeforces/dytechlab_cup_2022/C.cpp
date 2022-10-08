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

    array<int, 6> P{0};
    for(int i = 0; i < 6; i++) {
        cin >> P[i];
    }

    int X, Y;
    cin >> X >> Y;

    int c_x = -1;
    int c_y = -1;
    int k = -1;
    for(int i = 0; i < 3; i++) {
        int x = P[i * 2];
        int y = P[i * 2 + 1];
        
        for(int j = 0; j < 3; j++) {
            if(i != j) {
                if(abs(x - P[j * 2]) == 1 && abs(y - P[j * 2 + 1]) == 1) {
                    k = 3 - i - j;        
                }
            }
        }

        if(k != -1) {
            break;
        }
    }

    c_x = P[k * 2];
    c_y = P[k * 2 + 1];

    array<int, 8> corner{1, 1, N, N, 1, N, N, 1};
    for(int i = 0; i < 8; i += 2) {
        if(c_x == corner[i] && c_y == corner[i + 1]) {
            if(c_x == X || c_y == Y) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }
    }

    int d_1 = abs(c_x - X);
    int d_2 = abs(c_y - Y);
    if(d_1 % 2 == 0 || d_2 % 2 == 0) {
        cout << "YES" << '\n'; 
    } else {
        cout << "NO" << '\n';
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
