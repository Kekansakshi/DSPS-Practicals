#include <iostream>
using namespace std;

class PizzaOrder
{
private:
    int front, rear, capacity;
    int *orderQueue;

public:
    PizzaOrder(int m)
    {
        capacity = m;
        front = rear = -1;
        orderQueue = new int[capacity];
        cout << "Pizza parlor having capacity of " << capacity << " orders." << endl;
    }

    ~PizzaOrder()
    {
        delete[] orderQueue;
        cout << "Deleted" << endl;
    }

    bool isFull()
    {
        return rear == capacity - 1; // Fixed comparison
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void placeOrder(int orderId)
    {
        if (isFull())
        {
            cout << "Cannot place order " << orderId << ". The queue is full!" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear++;
        orderQueue[rear] = orderId;
        cout << "Order " << orderId << " placed successfully!" << endl;
    }

    void serveOrder()
    {
        if (isEmpty())
        {
            cout << "No orders to serve!" << endl;
            return;
        }
        cout << "Serving order " << orderQueue[front] << endl;
        front++;
    }

    void displayOrders()
    {
        if (isEmpty())
        {
            cout << "No orders in the queue!" << endl;
            return;
        }
        cout << "Current orders in the queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << orderQueue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int m, ch, orderId;
    cout << "Enter Pizza Parlor's Maximum Order Capacity: ";
    cin >> m;
    PizzaOrder P(m);
    
    do
    {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch (ch)
        {
        case 1:
            cout << "Enter Order ID to place: ";
            cin >> orderId;
            P.placeOrder(orderId);
            break;
        case 2:
            P.serveOrder();
            break;
        case 3:
            P.displayOrders();
            break;
        case 4:
            cout << "Exiting!!!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (ch != 4);

    return 0;
}
