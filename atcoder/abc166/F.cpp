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

    array<int, 3> A{0};
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<char> choices;      
    for(int i = 0; i < N; i++) {
        int x = S[i][0] - 'A';
        int y = S[i][1] - 'A';

        if(A[x] == 0 && A[y] == 0) {
            cout << "No" << '\n';
            return;
        }
            
        if(A[x] == 0) {
            A[x] += 1;
            A[y] -= 1;
            choices.push_back(S[i][0]);
        } else if(A[y] == 0) {
            A[x] -= 1;
            A[y] += 1;
            choices.push_back(S[i][1]);
        } else if(A[x] == 1 && A[y] == 1 && A[3 - x - y] == 0)  {
            if(i == N - 1 || S[i] == S[i + 1]) {
                A[x] += 1;
                A[y] -= 1;
                choices.push_back(S[i][0]);
            } else {
                if(S[i + 1].find(S[i][0]) != string::npos) {
                    A[x] += 1;
                    A[y] -= 1;
                    choices.push_back(S[i][0]);
                } else {
                    A[x] -= 1;
                    A[y] += 1;
                    choices.push_back(S[i][1]);
                }
            }
        } else {
            if(A[x] == 1) {
                A[x] += 1;
                A[y] -= 1;
                choices.push_back(S[i][0]);
            } else {
                A[x] -= 1;
                A[y] += 1;
                choices.push_back(S[i][1]);
            }
        }
    }

    cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        cout << choices[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
