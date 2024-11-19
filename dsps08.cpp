#include <iostream>
#include <string>
using namespace std;

struct Node {
    string bookTitle;
    string author;
    string isbnNo;
    Node* next;
};

class list {
public:
    Node* head = NULL;

    void insertAtFirst() {
        Node* newNode = new Node;

        cout << "Enter Book Title (use underscores for spaces): ";
        cin >> newNode->bookTitle;
        cout << "Enter Author Name (use underscores for spaces): ";
        cin >> newNode->author;
        cout << "Enter ISBN No: ";
        cin >> newNode->isbnNo;

        newNode->next = head;
        head = newNode;
    }

    void insertAtLast() {
        Node* newNode = new Node;

        cout << "Enter Book Title (use underscores for spaces): ";
        cin >> newNode->bookTitle;
        cout << "Enter Author Name (use underscores for spaces): ";
        cin >> newNode->author;
        cout << "Enter ISBN No: ";
        cin >> newNode->isbnNo;

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAfterPosition() {
        Node* newNode = new Node;
        Node* temp = head;
        int pos, i = 1;

        cout << "Enter the position after which you want to insert the new book: ";
        cin >> pos;

        while (i < pos && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        cout << "Enter Book Title (use underscores for spaces): ";
        cin >> newNode->bookTitle;
        cout << "Enter Author Name (use underscores for spaces): ";
        cin >> newNode->author;
        cout << "Enter ISBN No: ";
        cin >> newNode->isbnNo;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (head == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        Node* temp = head;
        Node* prevNode = NULL;

        while (temp->next != NULL) {
            prevNode = temp;
            temp = temp->next;
        }

        if (prevNode != NULL) {
            prevNode->next = NULL;
        } else {
            head = NULL;
        }

        delete temp;
    }

    void deleteAtPosition() {
        if (head == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        Node* temp = head;
        Node* prevNode = NULL;
        int pos, i = 1;

        cout << "Enter the position from which you want to delete the book: ";
        cin >> pos;

        if (pos == 1) {
            head = temp->next;
            delete temp;
            return;
        }

        while (i < pos && temp != NULL) {
            prevNode = temp;
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        prevNode->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << "Book Title: " << temp->bookTitle 
                 << ", Author: " << temp->author 
                 << ", ISBN No: " << temp->isbnNo << endl;
            temp = temp->next;
        }
    }
} l;

int main() {
    int choice, ch;

    do {
        cout << "\n1. INSERT AT START\n2. INSERT AT LAST\n3. INSERT AFTER POSITION\n4. DELETE FIRST\n5. DELETE LAST\n6. DELETE AT POSITION\n7. DISPLAY\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.insertAtFirst();
                break;
            case 2:
                l.insertAtLast();
                break;
            case 3:
                l.insertAfterPosition();
                break;
            case 4:
                l.deleteFirst();
                break;
            case 5:
                l.deleteLast();
                break;
            case 6:
                l.deleteAtPosition();
                break;
            case 7:
                l.display();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }

        cout << "Do you want to continue? (1 for yes): ";
        cin >> ch;
    } while (ch == 1);

    return 0;
}
