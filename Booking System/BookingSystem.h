#include <iostream>
#include <string>
using namespace std;


class Queue {
private:
    static const int MAX_SIZE = 100;
    string data[MAX_SIZE];
    int frontIndex;
    int lastIndex;

public:
    Queue() {
        frontIndex = 0;
        lastIndex = -1;
    }

    void push(string value) {
        if (lastIndex >= MAX_SIZE - 1) {
            cout << "Queue overflow!" << endl;
            return;
        }
        lastIndex++;
        data[lastIndex] = value;
    }

    void pop() {
        if (empty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        frontIndex++;
    }

    string front() {
        if (empty()) {
            return "";
        }
        return data[frontIndex];
    }

    bool empty() {
        return frontIndex > lastIndex;
    }

    int size() {
        return empty() ? 0 : lastIndex - frontIndex + 1;
    }

    bool remove(string name) {
        bool found = false;
        string temp[MAX_SIZE];
        int tempIndex = 0;

        while (!empty()) {
            string curr = front();
            pop();
            if (curr == name && !found) {
                found = true;
            }
            else {
                temp[tempIndex++] = curr;
            }
        }

        frontIndex = 0;
        lastIndex = -1;
        for (int i = 0; i < tempIndex; i++) {
            push(temp[i]);
        }

        return found;
    }

    void print(const string& label) {
        cout << "- " << label << ": ";
        if (empty()) {
            cout << "Empty\n";
        }
        else {
            for (int i = frontIndex; i <= lastIndex; i++) {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
    }

    void serveNext(const string& label) {
        if (!empty()) {
            cout << "Serving from " << label << ": " << front() << endl;
            pop();
        }
    }
};


class BookingSystem {
private:
    Queue VIP;
    Queue Regular;
    Queue Economy;

public:
    void bookTicket(const string& name, const string& category) {
        if (category == "VIP" || category == "vip") {
            VIP.push(name);
            cout << "Booked VIP for: " << name << endl;
        }
        else if (category == "Regular" || category == "regular") {
            Regular.push(name);
            cout << "Booked Regular for: " << name << endl;
        }
        else if (category == "Economy" || category == "economy") {
            Economy.push(name);
            cout << "Booked Economy for: " << name << endl;
        }
        else {
            cout << "Invalid category!" << endl;
        }
    }

    void cancelTicket(const string& name) {
        if (VIP.remove(name)) {
            cout << name << " removed from VIP queue.\n";
        }
        else if (Regular.remove(name)) {
            cout << name << " removed from Regular queue.\n";
        }
        else if (Economy.remove(name)) {
            cout << name << " removed from Economy queue.\n";
        }
        else {
            cout << "No booking found for " << name << ".\n";
        }
    }

    void serveNextPassenger() {
        if (!VIP.empty()) {
            VIP.serveNext("VIP");
        }
        else if (!Regular.empty()) {
            Regular.serveNext("Regular");
        }
        else if (!Economy.empty()) {
            Economy.serveNext("Economy");
        }
        else {
            cout << "No passengers to serve.\n";
        }
    }

    void displayQueues() {
        cout << "Current Queues:\n";
        VIP.print("VIP");
        Regular.print("Regular");
        Economy.print("Economy");
    }
};