#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;
 
    if(X != 0 && Y != 0) {
        cout << -1 << '\n';
        return;
    }
    if(X == 0 && Y == 0) {
        cout << -1 << '\n';
        return;
    }
    
    if(X == 0) {
        swap(X, Y); 
    }
 
    if((N - 1) % X) {
        cout << -1 << '\n';
        return;
    }
 
    int winner = 1;
    int cnt = 0;
    for(int i = 1; i < N; i++) {
        if(cnt == X) {
            cnt = 0;
            winner = i + 1;
        }
        cout << winner << " \n"[i == N - 1];
        cnt++;
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
