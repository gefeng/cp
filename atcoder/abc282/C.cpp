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

    int open = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == ',') {
            if(open == 0) {
                S[i] = '.';
            }    
        } else if(S[i] == '\"') {
            if(open == 0) {
                open += 1;
            } else {
                open -= 1;
            }
        }
    }

    cout << S << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
