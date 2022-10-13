#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N + 1, 0);
    vector<int> P(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        P[A[i]] = i;
    }

    vector<pair<int, int>> B(M, {0, 0});
    for(int i = 0; i < M; i++) {
        cin >> B[i].first;
        cin >> B[i].second;
    }

    vector<int> is_head(N + 1, 0);
    int cnt_head = 1;
    is_head[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(P[i - 1] > P[i]) {
            is_head[i] = 1;
            cnt_head++;
        } 
    }

    for(pair<int, int>& q : B) {
        int i = q.first;
        int j = q.second;
        if(i > j) {
            swap(i, j);
        }

        int x = A[i];
        int y = A[j];

        P[A[i]] = j;
        P[A[j]] = i;
        A[i] = y;
        A[j] = x;
        
        if(x < N) {
            if(!is_head[x + 1] && P[x] > P[x + 1]) {
                is_head[x + 1] = 1;
                cnt_head++;
            }
        }

        if(y < N) {
            if(is_head[y + 1] && P[y] < P[y + 1]) {
                is_head[y + 1] = 0;
                cnt_head--;
            }
        }
        
        if(x != y + 1) {
            if(x != 1 && is_head[x] && P[x - 1] < P[x]) {
                is_head[x] = 0;
                cnt_head--;
            }
        }

        if(y != x + 1) {
            if(y != 1 && !is_head[y] && P[y - 1] > P[y]) {
                is_head[y] = 1;
                cnt_head++;
            }
        }

        cout << cnt_head << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
