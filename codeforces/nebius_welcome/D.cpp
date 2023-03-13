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

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_v = 0;
    int min_v = 0;
    
    for(int i = 0; i < N; i++) {
        string s = A[i];

        int sum = 0;
        for(int j = 0; j < M; j++) {
            if(s[j] == '1') {
                sum += 1;
            }
        }

        int cnt_2 = M / 4;
        for(int j = 0; j < M; ) {
            int k = j;
            while(j < M && (j == k || s[j] == '0' || s[j] != s[j - 1])) {
                j += 1;
            }

            int len = j - k;
            cnt_2 = max(0, cnt_2 - len / 2);
        }

        max_v += sum - cnt_2;
    }

    for(int j = 0; j < N; j++) {
        int cnt_2 = M / 4;
        int cnt_1 = M / 2;
        string s = A[j];

        for(int i = 1; i < M; i++) {
            if(s[i] == '1' && s[i - 1] == '1') {
                if(cnt_2) {
                    min_v += 1;
                    cnt_2 -= 1;
                    s[i] = '*';
                    s[i - 1] = '*';
                } else {
                    break;
                }
            }
        }

        for(int i = 0; i < M; i++) {
            if(s[i] == '1') {
                min_v += 1;
            }
        }
    }

    cout << min_v << ' ' << max_v << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
