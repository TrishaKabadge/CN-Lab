//Receiver side hamming code

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter no. of data bits: ";
    cin >> n;

    string input;
    int data[100];

    cout << "Enter received hamming code: ";
    cin >> input;

    int total = input.length();

    // Store received hamming code
    int h[100] = {0};

    int j = 0;

    for (int i = total; i >= 1; i--)
    {
        h[i] = input[j] - '0';
        j++;
    }

    // Calculate number of redundant bits
    int redundant = 0;

    while ((1 << redundant) < (total + 1))
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

    // Calculate R1
    int R1 = 0;

    for (int i = 1; i <= total; i++)
    {
        if (i & 1)
        {
            R1 = R1 ^ h[i];
        }
    }

    cout << "R1 = " << R1 << endl;

    // Calculate R2
    int R2 = 0;

    for (int i = 1; i <= total; i++)
    {
        if (i & 2)
        {
            R2 = R2 ^ h[i];
        }
    }

    cout << "R2 = " << R2 << endl;

    // Calculate R4
    int R4 = 0;

    for (int i = 1; i <= total; i++)
    {
        if (i & 4)
        {
            R4 = R4 ^ h[i];
        }
    }

    cout << "R4 = " << R4 << endl;

    // Display error word
    cout << "\nError word is: ";

    cout << R4 << R2 << R1;

    cout << endl;

    // Calculate error position
    int error = R4 * 4 + R2 * 2 + R1 * 1;

    cout << "Decimal equivalent is: " << error << endl;

    // Check error
    if (error == 0)
    {
        cout << "Received codeword is correct." << endl;
    }
    else
    {
        cout << "Error is located at " << error << "th position." << endl;

        // Invert the error bit
        h[error] = h[error] ^ 1;

        cout << "Correct codeword is: ";

        for (int i = total; i >= 1; i--)
        {
            cout << h[i];
        }  
        cout << endl;
    }

    return 0;
}

//Output :
//Enter no. of data bits: 7
//Enter received hamming code: 1011011
//Number of redundant bits: 3
//Redundant bit positions: 1 2 4
//R1 = 1
//R2 = 0
//R4 = 1

//Error word is: 101
//Decimal equivalent is: 5
//Error is located at 5th position.
//Correct codeword is: 1001011
