//works only on a sorted array
#include <iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left +((right - left)/2);
        if (arr[mid]== x)
        {
        return mid;
        }
        else if ( arr[mid] < x)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    
    }
    return -1;
}

int main ()
{
    int num;
    int myarr[10];
    int output;//holds the index position where the number resides in the array

    cout <<"Enter 10 integers in ascending order"<<endl;
    for (int i = 0; i <10 ; i++)
    {
        cin >> myarr[i];

    }
    cout <<" What number do you want to search in the array?"<< endl;
    cin >> num;
    output = binarysearch(myarr, 0, 9, num);
    if (output == - 1)
    {
        cout <<"Sorry, no match in this array"<< endl;
    }
    else{
        cout <<"Match found in index position " << output << endl;
    }
    return 0;

}