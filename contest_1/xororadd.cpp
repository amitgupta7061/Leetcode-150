#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int x, int y) {
    int maxi = 200; 
    vector<int> dist(maxi + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[a] = 0;
    pq.push({0, a});

    while (pq.size()) {
        auto [cost, curr] = pq.top(); pq.pop();
        if (curr == b) return cost;
        if (curr + 1 <= maxi and dist[curr + 1] > cost + x) {
            dist[curr + 1] = cost + x;
            pq.push({dist[curr + 1], curr + 1});
        }

        int next = curr ^ 1;
        if (dist[next] > cost + y) {
            dist[next] = cost + y;
            pq.push({dist[next], next});
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        cout << f(a, b, x, y) << '\n';
    }

    return 0;
}
