#include<iostream>
#include<cstring>
using namespace std;

class student
{
public:
    int rollno;
    string name,branch,div,tn;

    void accept()
    {
        cout << "Enter the roll no of the student: ";
        cin >> rollno;
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the branch of the student: ";
        cin >> branch;
        cout << "Enter the class of the student: ";
        cin >> div;
        cout << "Enter the name of training program which student have done: ";
        cin >> tn;
    }

    void display()
    {
        cout << "\nThe roll no of the student is: "<<rollno<<endl;
        cout << "The name of the student is: "<<name<<endl;
        cout << "The branch of the student is: "<<branch<<endl;
        cout << "The class of the student is: "<<div<<endl;
        cout << "The name of training program which student have attended is: "<<tn<<endl;
       
    }

    static void linearsearch(int n,int r,student s[])
    {
        int i;
        int flag=0;
        for(int i=0;i<n;i++)
        {
           if(s[i].rollno==r)
           {
               flag=1;
               cout<<"The Data of the student who attended the training program is :"<<endl;
               s[i].display();
            }
        }      
        if(flag==0)
        {
            cout<<"Student was not present for the training program.";
        }
    }
   
    static void binarysearch(int n,int r,student s[])
    {
        int low = 0, high = n - 1;
        int flag=0;
   
        while(low<=high)
        {
            int mid =low + (high - low)/ 2;
   
            if (s[mid].rollno == r)
            {
                cout<<"The Data of the student who attended the training program is :"<<endl;
                s[mid].display();
                flag=1;
            }
                           
            else if (s[mid].rollno < r)
                low = mid + 1;      
            else
                high = mid - 1;      
        }
        if(flag==0)
        {
            cout<<"Student was not present for the training program.";
        }
    }
   
}s[100];

int main()
{
 
    int n;
    int r;
    int choice;

    while (true)
    {
        cout << "\n\n--- Menu ---";
        cout << "\n1. Add the data of students who attended the training program";
        cout << "\n2. Display the data of students who attended the training program";
        cout << "\n3. Search wheather the perticular student attented the training program or not with linear search";
        cout << "\n4. Search wheather the perticular student attented the training program or not with linear search";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the number of students who attended the training program:";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    s[i].accept();
                }
                break;

            case 2:
                cout<<"The data of students who attended the training program is as follows:"<<endl;
                for (int i = 0; i < n; i++)
                {
                    s[i].display();
                }
                break;


            case 3:
                cout<<"Enter the roll no of student to check he/she attended the training program or not:";
                cin>>r;
                student::linearsearch(n,r,s);
                break;
           
            case 4:
                n = sizeof(s) / sizeof(s[0]);
                cout<<"Enter the roll no of student to check he/she attended the training program or not:";
                cin>>r;
                student::binarysearch(n,r,s);
                break;

            case 5 :
                cout << "Exiting program.";
                return 0;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.";
        }
    }
}