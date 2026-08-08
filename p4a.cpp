#include <iostream>
using namespace std;

int main()
{
    string s;

    cout << "Enter input frame: ";
    cin >> s;
    cout<<"Stuffed data:";
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];

        if (s[i] == '1')
            count++;
        else
            count = 0;

        if (count == 5)
        {
            cout << "0";
            count = 0;
        }
    }

    return 0;
}