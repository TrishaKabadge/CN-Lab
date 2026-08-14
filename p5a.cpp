#include <iostream>
#include <string>
using namespace std;

int main() {
    string data;

    cout << "Enter the binary data word: ";
    cin >> data;

    // Check input
    for (char c : data) {
        if (c != '0' && c != '1') {
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

    int hamming[100] = {0};

    int j = 0;

    for (int position = n; position >= 1; position--) {
        
        if ((position & (position - 1)) != 0) {
            hamming[position] = data[j] - '0';
            j++;
        }
    }

    
    for (int i = 0; i < r; i++) {
        int p = 1 << i;
        int parity = 0;

        for (int position = 1; position <= n; position++) {
            if (position & p) {
                parity = parity ^ hamming[position];
            }
        }

        hamming[p] = parity;
    }

    
    cout << endl;
    cout << "Input data: " << data << endl;
    cout << "Number of redundant bits: " << r << endl;
    cout << "Total number of bits in codeword: " << n << endl;

    cout << "Hamming code: ";

    
    for (int position = n; position >= 1; position--) {
        cout << hamming[position];
    }

    cout << endl;

    return 0;
}

//Input data: 1011001
//Number of redundant bits: 4
//Total number of bits in codeword: 11
//Hamming code: 10101001110