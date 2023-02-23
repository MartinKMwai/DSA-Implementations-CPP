#include <iostream>


using namespace std;
void linearsearch(int a[], int n )
{
    int temp = -1; //simple indicator of whether an element has been found or not
    for (int i = 0; i<5; i++)
    {
        if (a[i]== n)
        {
            cout <<"Element found at the location: "<< i <<endl;
            temp = 0;
        }
    }
    if (temp==-1)
    {
        cout <<"The element cannot be found in the array" <<endl;
    }        
}
int main()
{
    int arr [5];
    cout <<"Enter 5 elements you wanna use for the array"<<endl;
    for (int i = 0; i<5; i++)
    {
        cin>>arr[i];
    }
    cout <<" Enter the element you want to search"<<endl;
    int num;
    cin >>num;

    linearsearch(arr, num);

    return 0;
}