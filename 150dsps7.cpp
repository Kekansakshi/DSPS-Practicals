#include <iostream>
using namespace std;

#define MAX 10

int q[MAX];
int front = -1, rear = -1;

void insertAtRear(int no)
 {
    if (rear == MAX) {
        cout << "Queue is overflow" << endl;
        return;
    }
    if(front==-1)
    {
     front=0;
    }
     rear = rear + 1;
    q[rear] = no;
   cout<<"\nElement ["<<no<<"] added."<<endl;

}

void insertAtFront(int no) {
    if (front <=0) {
        cout << "Cannot add item at front end" << endl;
        return;
    }
    else{
    front = front - 1;
    q[front ] = no;
    cout<<"\nElement ["<<no<<"] added."<<endl;
    }
 
}

void deleteFromFront() {
    if (front == -1 || front > rear) {
        cout << "Queue is underflow" << endl;
        return;
    }
    int no = q[front ];
    cout << "Deleted element from front is: " << no << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = front + 1;
    }
}

void deleteFromRear() {
    if (rear == -1) {
        cout << "Cannot delete value at rear end" << endl;
        return;
    }
    int no = q[rear ];
    cout << "Deleted element from rear is: " << no << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        rear = rear - 1;
    }
}

void displayDeque() {
    if (front == -1) {
        cout << "Deque is empty" << endl;
        return;
    }
    cout << "Deque elements are: [";
    for (int i = front ; i <= rear; i++) {
        cout << q[i] << " ";
    }
     cout << "]";
    cout << endl;
}

int main() {
 
 int ch,n,m;
 while(true){
  cout<<"Menu\n1. insertAtRear\n2. insertAtFront\n3 .deleteFromFront\n4. deleteFromRear\n5. displayDeque\n6. Exit...\n Enter your choice";
  cin>>ch;
  switch(ch)
  {
  case 1:
  cout<<"Enter the element:";
  cin>>n;
  insertAtRear(n);
  break;
  case 2:
  cout<<"Enter the element:";
  cin>>m;
  insertAtFront(m);
  break;
  case 3:
  deleteFromFront();
  break;
  case 4:
  deleteFromRear();
  break;
 
  case 5:
  displayDeque();
  break;
  case 6:
  return 0;
  }
 }
   
    return 0;
}
