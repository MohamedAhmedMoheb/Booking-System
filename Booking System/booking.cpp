#include <iostream>
#include <string>
#include "BookingSystem.h"
using namespace std;

int main() {
    BookingSystem system;
    int choice;
    string name, category;

    do {
        cout << "\n\n";
        cout << "===============================================\n";
        cout << "            *** Welcome to the ***             \n";
        cout << "    === Ticket Booking System Menu ===         \n";
        cout << "===============================================\n";
        cout << "\n";
        cout << "---------------------- Menu -------------------\n";
        cout << "1 => Book Ticket\n";
        cout << "2 => Cancel Ticket\n";
        cout << "3 => Display All Queues\n";
        cout << "4 => Serve Next Passenger (Priority)\n";
        cout << "5 => Exit\n";
        cout << "----------------------------------------------\n";
        cout << "\nEnter your choice (1-5): ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter name:\n";
            cin >> name;
            cout << "\nEnter category (VIP / Regular / Economy):\n";
            cin >> category;
            cout << "\n";
            system.bookTicket(name, category);
            break;
        case 2:
            cout << "Enter name to cancel: ";
            cin >> name;
            system.cancelTicket(name);
            break;
        case 3:
            system.displayQueues();
            break;
        case 4:
            system.serveNextPassenger();
            break;
        case 5:
            cout << " Goodbye!\n";
            break;
        default:
            cout << " Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
