//Sender side hamming code

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter no. of data bits: ";
    cin >> n;

    string input;
    int data[100];

    cout << "Enter data bits: ";
    cin >> input;

    // Store data bits
    for (int i = 0; i < n; i++)
    {
        data[i] = input[i] - '0';
    }

    // Calculate number of redundant bits
    int redundant = 0;

    while ((1 << redundant) < (n + redundant + 1))
    {
        redundant++;
    }

    cout << "Number of redundant bits: " << redundant << endl;

    // Display redundant bit positions
    cout << "Redundant bit positions: ";

    for (int i = 0; i < redundant; i++)
    {
        cout << (1 << i) << " ";
    }

    cout << endl;

    int total = n + redundant;
    int h[100] = {0};

    // Insert data bits
    // First input bit goes to highest data position
    int j = n - 1;

    for (int i = 1; i <= total; i++)
    {
        // Check whether position is NOT a power of 2
        if ((i & (i - 1)) != 0)
        {
            h[i] = data[j];
            j--;
        }
    }

    // Calculate parity bits
    for (int p = 0; p < redundant; p++)
    {
        int position = 1 << p;
        int parity = 0;

        for (int i = 1; i <= total; i++)
        {
            if (i & position)
            {
                parity = parity ^ h[i];
            }
        }

        h[position] = parity;
    }

    // Display actual redundant bits
    cout << "Redundant bits: ";

    for (int p = 0; p < redundant; p++)
    {
        int position = 1 << p;
        cout << h[position] << " ";
    }

    cout << endl;

    // Display positions
    cout << "\nPosition: ";

    for (int i = total; i >= 1; i--)
    {
        cout << i << " ";
    }

    // Display codeword
    cout << "\nCodeword: ";

    for (int i = total; i >= 1; i--)
    {
        cout << h[i] << " ";
    }

    // Display final Hamming code
    cout << "\n\nHamming Code: ";

    for (int i = total; i >= 1; i--)
    {
        cout << h[i];
    }

    cout << endl;

    return 0;
}

//Output:
//Enter no. of data bits: 7
//Enter data bits: 1011001
//Number of redundant bits: 4
//Redundant bit positions: 1 2 4 8
//Redundant bits: 0 1 1 0

//Position: 11 10 9 8 7 6 5 4 3 2 1
//Codeword: 1 0 1 0 1 0 0 1 1 1 0

//Hamming Code: 10101001110