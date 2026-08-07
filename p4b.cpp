#include <iostream>
using namespace std;

int main()
{
    string s;

    cout << "Enter stuffed data: ";
    cin >> s;

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
            i++;   // Skip stuffed 0
            count = 0;
        }
    }

    return 0;
}