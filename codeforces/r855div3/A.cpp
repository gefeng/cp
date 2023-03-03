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

    for(int i = 0; i < N; i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            S[i] = (char)(S[i] - 'A' + 'a');
        }
    }

    string t = "";
    for(int i = 0; i < N; i++) {
        if(i == 0 || S[i] != S[i - 1]) {
            t.push_back(S[i]);
        }
    }

    cout << (t == "meow" ? "YES" : "NO") << '\n';
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
