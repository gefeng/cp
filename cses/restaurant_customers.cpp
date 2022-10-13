#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> events(2 * N, {0, 0});
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        events[2 * i] = {A, 0};
        events[2 * i + 1] = {B, 1};
    }

    sort(events.begin(), events.end());

    int cnt = 0;
    int ans = 0;
    for(pair<int, int>& e : events) {
        if(e.second == 0) {
            cnt++;
        } else {
            cnt--;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    run_case();
}
