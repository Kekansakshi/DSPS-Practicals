#include <iostream>
using namespace std;

class music {
public:
    int year, duration;
    string name, alb_name;
    music *next, *prev;

    void accept();
    void display();
    void update();
    void remove();
    void search();
};

music *start = nullptr;

void music::accept() {
    music* newnode = new music;
    cout << "\nEnter music details: ";
    cout << "\nEnter name, album name, released year, duration: ";
    cin >> newnode->name >> newnode->alb_name >> newnode->year >> newnode->duration;
    newnode->next = nullptr;

    if (start == nullptr) {
        newnode->prev = nullptr;
        start = newnode;
    } else {
        music* temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void music::display() {
    music* temp = start;
    while (temp != nullptr) {
        cout << "\n" << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << temp->duration;
        temp = temp->next;
    }
}

void music::update() {
    string title;
    cout << "\nEnter title: ";
    cin >> title;

    music* temp = start;
    while (temp != nullptr) {
        if (temp->name == title) {
            cout << "\nEnter new music name, album, year, and duration: ";
            cin >> temp->name >> temp->alb_name >> temp->year >> temp->duration;
            cout << "Music details updated successfully.";
            return;
        }
        temp = temp->next;
    }
    cout << "Music not found.";
}

void music::remove() {
    string title;
    cout << "\nEnter title: ";
    cin >> title;

    music* temp = start;
    while (temp != nullptr) {
        if (temp->name == title) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                start = temp->next; // Update the start if the first node is deleted
            }

            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }

            cout << "\nDeleting: " << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << temp->duration;
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Music not found.";
}

void music::search() {
    string title;
    cout << "\nEnter title: ";
    cin >> title;

    music* temp = start;
    while (temp != nullptr) {
        if (temp->name == title) {
            cout << "\n" << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << temp->duration;
            return;
        }
        temp = temp->next;
    }
    cout << "Music not found.";
}

int main() {
    int ch;
    do {
        cout << "\n1. Accept music details";
        cout << "\n2. Display music details";
        cout << "\n3. Update music details";
        cout << "\n4. Remove music details";
        cout << "\n5. Search music details";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        music m; // Create an instance to call the member functions
        switch (ch) {
            case 1: m.accept(); break;
            case 2: m.display(); break;
            case 3: m.update(); break;
            case 4: m.remove(); break;
            case 5: m.search(); break;
            case 0: cout << "Exiting."; break;
            default: cout << "Invalid choice.";
        }
    } while (ch != 0);

    return 0;
}
