#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
    string ip;
    cout << "Enter IPv4 Address: ";
    cin >> ip;

    string part[4];
    stringstream ss(ip);

    // Split IP address into 4 parts
    for (int i = 0; i < 4; i++)
    {
        if (!getline(ss, part[i], '.'))
        {
            cout << "\nInvalid IPv4 Address" << endl;
            cout << "Reason: IPv4 address must contain exactly four octets separated by dots." << endl;
            return 0;
        }
    }

    // Check for extra octets
    string extra;
    if (getline(ss, extra, '.'))
    {
        cout << "\nInvalid IPv4 Address" << endl;
        cout << "Reason: IPv4 address must contain exactly four octets." << endl;
        return 0;
    }

    bool hasBinary = false;
    bool hasDecimal = false;

    // Check each part
    for (int i = 0; i < 4; i++)
    {
        if (part[i].empty())
        {
            cout << "\nInvalid IPv4 Address" << endl;
            cout << "Reason: Octet " << i + 1 << " is empty." << endl;
            return 0;
        }

        // Check if it contains only digits
        for (char ch : part[i])
        {
            if (!isdigit(ch))
            {
                cout << "\nInvalid IPv4 Address" << endl;
                cout << "Reason: Octet " << i + 1
                     << " contains an invalid character." << endl;
                return 0;
            }
        }

        // Detect 8-bit binary notation
        bool binary = true;

        if (part[i].length() == 8)
        {
            for (char ch : part[i])
            {
                if (ch != '0' && ch != '1')
                {
                    binary = false;
                    break;
                }
            }
        }
        else
        {
            binary = false;
        }

        if (binary)
            hasBinary = true;
        else
            hasDecimal = true;
    }

    // Binary and decimal mixture
    if (hasBinary && hasDecimal)
    {
        cout << "\nInvalid IPv4 Address" << endl;
        cout << "Reason: Mixture of binary and dotted-decimal notation is not allowed." << endl;
        return 0;
    }

    // If all four parts are binary, reject because this program
    // accepts dotted-decimal IPv4 notation only
    if (hasBinary && !hasDecimal)
    {
        cout << "\nInvalid IPv4 Address" << endl;
        cout << "Reason: Binary notation is not allowed. Enter IPv4 address in dotted-decimal format." << endl;
        return 0;
    }

    int octet[4];

    // Validate decimal octets
    for (int i = 0; i < 4; i++)
    {
        // Leading zero
        if (part[i].length() > 1 && part[i][0] == '0')
        {
            cout << "\nInvalid IPv4 Address" << endl;
            cout << "Reason: Octet " << i + 1
                 << " contains a leading zero." << endl;
            return 0;
        }

        octet[i] = stoi(part[i]);

        // Range check
        if (octet[i] > 255)
        {
            cout << "\nInvalid IPv4 Address" << endl;
            cout << "Reason: Octet " << i + 1
                 << " (" << octet[i]
                 << ") must be between 0 and 255." << endl;
            return 0;
        }
    }

    int a = octet[0];
    int b = octet[1];
    int c = octet[2];
    int d = octet[3];

    cout << "\nValid IPv4 Address" << endl;

    // Class A
    if (a >= 1 && a <= 126)
    {
        cout << "Class: A" << endl;
        cout << "Default Mask: 255.0.0.0" << endl;
        cout << "Network Address: " << a << ".0.0.0" << endl;
        cout << "Host Address: " << b << "." << c << "." << d << endl;
    }

    // Class B
    else if (a >= 128 && a <= 191)
    {
        cout << "Class: B" << endl;
        cout << "Default Mask: 255.255.0.0" << endl;
        cout << "Network Address: " << a << "." << b << ".0.0" << endl;
        cout << "Host Address: " << c << "." << d << endl;
    }

    // Class C
    else if (a >= 192 && a <= 223)
    {
        cout << "Class: C" << endl;
        cout << "Default Mask: 255.255.255.0" << endl;
        cout << "Network Address: " << a << "." << b << "." << c << ".0" << endl;
        cout << "Host Address: " << d << endl;
    }

    // Class D
    else if (a >= 224 && a <= 239)
    {
        cout << "Class: D" << endl;
        cout << "Multicast Address" << endl;
    }

    // Class E
    else if (a >= 240 && a <= 255)
    {
        cout << "Class: E" << endl;
        cout << "Experimental Address" << endl;
    }

    // Special
    else if (a == 0)
    {
        cout << "Special Address: 0.x.x.x" << endl;
    }
    else if (a == 127)
    {
        cout << "Special Address: Loopback" << endl;
    }

    return 0;
}

/*
1)Enter IPv4 Address: 195.78.63.92

Valid IPv4 Address
Class: C
Default Mask: 255.255.255.0
Network Address: 195.78.63.0
Host Address: 92

2)Enter IPv4 Address: 56.911.25.78

Invalid IPv4 Address
Reason: Octet 2 (911) must be between 0 and 255.

3)Enter IPv4 Address: 197.67.04.62

Invalid IPv4 Address
Reason: Octet 3 contains a leading zero.

4)Enter IPv4 Address: 212.11110000.7.4

Invalid IPv4 Address
Reason: Mixture of binary and dotted-decimal notation is not allowed.

5)Enter IPv4 Address: 145.23.78

Invalid IPv4 Address
Reason: IPv4 address must contain exactly four octets separated by dots.

*/
