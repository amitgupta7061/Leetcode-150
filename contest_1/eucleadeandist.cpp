#include <bits/stdc++.h>
using namespace std;

int main() {

    int testcase;
     cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;

        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x;
        }

        long long dx = qx - px;
        long long dy = qy - py;

        long double dist = sqrtl(dx * dx + dy * dy);

        if (dist > sum) {
            cout << "No\n";
        } else {
            long long diff = roundl(sum - dist);
            if ((diff % 2) == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
