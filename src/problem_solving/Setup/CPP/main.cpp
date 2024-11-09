#include <iostream>
#include <string>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int n_th;
        cin >> n_th;

        if (n_th == 1) {
            cout << "0" << endl;
        } else {
            for (int i = 0; i < n_th; ++i) {
                cout << (i % 2);
            }
            cout << endl;
        }
    }

    return 0;
}