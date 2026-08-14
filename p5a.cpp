#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string data;

    cout << "Enter the binary data word: ";
    cin >> data;

    for (char bit : data) {
        if (bit != '0' && bit != '1') {
            cout << "Invalid input! Enter only 0 and 1." << endl;
            return 0;
        }
    }

    int m = data.length();
    int r = 0;

    while ((1 << r) < (m + r + 1)) {
        r++;
    }

    int n = m + r;

    vector<int> hamming(n + 1, 0);

    int j = 0;

    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) {
            hamming[i] = data[j] - '0';
            j++;
        }
    }

    for (int i = 0; i < r; i++) {
        int position = 1 << i;
        int parity = 0;

        for (int j = 1; j <= n; j++) {
            if (j & position) {
                parity = parity ^ hamming[j];
            }
        }

        hamming[position] = parity;
    }

    cout << endl;
    cout << "Input data: " << data << endl;
    cout << "Number of redundant bits: " << r << endl;
    cout << "Total number of bits in codeword: " << n << endl;

    cout << "Hamming code: ";

    for (int i = 1; i <= n; i++) {
        cout << hamming[i];
    }

    cout << endl;

    return 0;
}

//Input data: 1011001
//Number of redundant bits: 4
//Total number of bits in codeword: 11
//Hamming code: 10100111001