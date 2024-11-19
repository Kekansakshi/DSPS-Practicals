#include <iostream>
using namespace std;

class Music {
public:
    int year, duration;
    string name, alb_name;
    Music *next, *prev;

    void accept();
    void display();
    void update();
    void remove();
    void search();
};

Music *start = nullptr;

void Music::accept() {
    Music* newnode = new Music;
    cout << "\nEnter music details: ";
    cout << "\nEnter name, album name, released year, duration: ";
    cin >> newnode->name >> newnode->alb_name >> newnode->year >> newnode->duration;
    newnode->next = newnode->prev = nullptr;

    if (start == nullptr) { // If the list is empty
        start = newnode;
        newnode->next = newnode; // Point to itself for circular link
        newnode->prev = newnode; // Point to itself for circular link
    } else {
        Music* last = start->prev; // The last node
        last->next = newnode; // Link last node to the new node
        newnode->prev = last; // Link new node back to last
        newnode->next = start; // Link new node to start (circular)
        start->prev = newnode; // Link start back to new node (circular)
    }
}

void Music::display() {
    if (start == nullptr) {
        cout << "\nThe list is empty.";
        return;
    }

    Music* temp = start;
    do {
        cout << "\n" << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << temp->duration;
        temp = temp->next;
    } while (temp != start);
}

void Music::update() {
    string title;
    cout << "\nEnter title: ";
    cin >> title;

    if (start == nullptr) {
        cout << "The list is empty.";
        return;
    }

    Music* temp = start;
    do {
        if (temp->name == title) {
            cout << "\nEnter new music name, album, year, and duration: ";
            cin >> temp->name >> temp->alb_name >> temp->year >> temp->duration;
            cout << "Music details updated successfully.";
            return;
        }
        temp = temp->next;
    } while (temp != start);
    cout << "Music not found.";
}

void Music::remove() {
    string title;
    cout << "\nEnter title: ";
    cin >> title;

    if (start == nullptr) {
        cout << "The list is empty.";
        return;
    }

    Music* temp = start;
    do {
        if (temp->name == title) {
            if (temp->next == temp) { // If it is the only node
                delete temp;
                start = nullptr; // The list is now empty
                cout << "The last music entry was deleted.";
                return;
            } else {
                // If we are deleting a node other than the last node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                // If the node to be deleted is the start node
                if (temp == start) {
                    start = temp->next; // Update start to be the next node
                }
                cout << "\nDeleting: " << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << temp->duration;
                delete temp;
                return;
            }
        }
        temp = temp->next;
    } while (temp != start);
    cout << "Music not found.";
}

void Music::search() {
    string title;
    cout << "\nEnter title: ";
    cin >> title;

    if (start == nullptr) {
        cout << "The list is empty.";
        return;
    }

    Music* temp = start;
    do {
        if (temp->name == title) {
            cout << "\n" << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << temp->duration;
            return;
        }
        temp = temp->next;
    } while (temp != start);
    cout << "Music not found.";
}

int main() {
    int ch;
    Music m; // Create an instance of the Music class for calling member functions
    do {
        cout << "\n1. Accept music details";
        cout << "\n2. Display music details";
        cout << "\n3. Update music details";
        cout << "\n4. Remove music details";
        cout << "\n5. Search music details";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

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
