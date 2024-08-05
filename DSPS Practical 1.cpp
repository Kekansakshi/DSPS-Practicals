/*
Program Definition
*/
#include<iostream>

using namespace std;
int add;
int i;
int flag=0;
int cnt=0;
int linearsearch(int n,int target,int a[])
{

    for(int i=0;i<n;i++)
     {
       if(a[i]==target)
       {
           flag=1;
           cout<<"\nTarget found at position=:"<<i;
           cnt++;
        }
       
    }       
       if(flag==0)
       
       {
           cout<<"Element not found";
       }
       cout<<"\nNumber of times target element present=:  "<<cnt;
       return 0;
}
   


int main()
{
    int i;
    int n;
    int target;
    int a[100];
    cout<<"Enter the size of array=:";
    cin>>n;
    cout<<"Enter the "<<n<<" array elements=:";
    for(int i=0;i<n;i++){
    cin>>a[i];
    }
    cout<<"Enter the target element=:";
    cin>>target;
    linearsearch(n,target,a);
   
    
      
    

    return 0;
}