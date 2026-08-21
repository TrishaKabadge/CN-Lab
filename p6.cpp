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

/*Enter number of frames: 6

Stop and Wait ARQ

Sending Frame 1...
Frame 1 lost!
Waiting for ACK...
Timeout occurred.
Retransmitting Frame 1...
Frame 1 received successfully.
ACK 1 received.

Sending Frame 2...
Frame 2 received successfully.
ACK 2 received.

Sending Frame 3...
Frame 3 received successfully.
ACK 3 received.

Sending Frame 4...
Frame 4 received successfully.
ACK 4 received.

Sending Frame 5...
Frame 5 received successfully.
ACK 5 received.

Sending Frame 6...
Frame 6 received successfully.
ACK 6 received.

Transmission completed successfully.*/