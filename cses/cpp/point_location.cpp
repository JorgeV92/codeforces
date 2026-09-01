#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct P {
    int x, y;
    P(int a = 0, int b = 0) : x(a), y(b) {}
    friend istream &operator>>(istream &in, P& p) {
        in >> p.x >> p.y;
        return in;
    }
};

ll collinear(P p, P p1, P p2) {
    return 1LL * (p.y - p1.y) * (p2.x - p1.x) - 1LL * (p.x - p1.x) * (p2.y - p1.y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        P p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        ll ans = collinear(p1,p2,p3);
        if (ans == 0) {
            cout << "TOUCH\n";
        } else if (ans < 0) {
            cout << "RIGHT\n"; 
        } else {
            cout << "LEFT\n";
        }
    }
    return 0;
}