#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of frames: ";
    cin >> n;

    
    srand(time(0));
    int lostFrame = rand() % n + 1;

    cout << "\nStop and Wait ARQ\n\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "Sending Frame " << i << "..." << endl;

        
        this_thread::sleep_for(chrono::seconds(1));

        if (i == lostFrame)
        {
            cout << "Frame " << i << " lost!" << endl;

           
            cout << "Waiting for ACK..." << endl;
            this_thread::sleep_for(chrono::seconds(2));

            cout << "Timeout occurred." << endl;

            
            cout << "Retransmitting Frame " << i << "..." << endl;
            this_thread::sleep_for(chrono::seconds(1));

            cout << "Frame " << i << " received successfully." << endl;

            cout << "ACK " << i << " received." << endl;
        }
        else
        {
            cout << "Frame " << i << " received successfully." << endl;

           
            this_thread::sleep_for(chrono::milliseconds(500));

            cout << "ACK " << i << " received." << endl;
        }

        cout << endl;
    }

    cout << "Transmission completed successfully." << endl;

    return 0;
}