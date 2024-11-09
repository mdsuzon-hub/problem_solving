#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int main() {
    int testcase, subcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        cin >> subcase;
        vector<int> numbers(subcase);

        // Input the elements for each subcase
        for (int j = 0; j < subcase; j++) {
            cin >> numbers[j];  // Corrected access using numbers[j]
        }

        // Sort the vector in ascending order
        sort(numbers.begin(), numbers.end());

        // Output the sorted elements
        cout << "Sorted subcase #" << i + 1 << ": ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
