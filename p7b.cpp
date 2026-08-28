#include <iostream>
#include <string>
using namespace std;

string divide(string data, string generator)
{
    int n = generator.length();

    for (int i = 0; i <= data.length() - n; i++)
    {
        if (data[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                data[i + j] =
                    (data[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    return data.substr(data.length() - (n - 1));
}

int main()
{
    string codeword, generator;

    cout << "Enter received codeword: ";
    cin >> codeword;

    cout << "Enter generator bits: ";
    cin >> generator;

    
    string remainder = divide(codeword, generator);

    
    cout << "Received Codeword : " << codeword << endl;
    cout << "Generator         : " << generator << endl;
    cout << "Remainder         : " << remainder << endl;

    
    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error detected." << endl;
    else
        cout << "No error detected." << endl;

    return 0;
}


OUTPUT:
Enter received codeword: 1001000001
Enter generator bits: 1011
Received Codeword : 1001000001
Generator         : 1011
Remainder         : 000
No error detected.
