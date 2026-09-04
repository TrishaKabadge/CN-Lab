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
    string data, generator;

    cout << "Enter data bits: ";
    cin >> data;

    cout << "Enter generator bits: ";
    cin >> generator;

   
    int zeros = generator.length() - 1;
    string modifiedData =
        data + string(zeros, '0');

    
    string remainder = divide(modifiedData, generator);

    string codeword = data + remainder;

   
    cout << "Data bits      : " << data << endl;
    cout << "Generator      : " << generator << endl;
    cout << "Number of zeros added : " << zeros << endl;
    cout << "Remainder      : " << remainder << endl;
    cout << "Codeword       : " << codeword << endl;

    return 0;
}

/*
Enter data bits: 1001000
Enter generator bits: 1011
Data bits      : 1001000
Generator      : 1011
Number of zeros added : 3
Remainder      : 001
Codeword       : 1001000001
*/
