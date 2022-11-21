#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Stack
{
    private:
        int top; //keeping number of entries in the stack
        int arr[5];

    public:
        Stack ()
        {
            top = -1;// stack is empty. Once a value is added, it reads 0, showing the index of the entry
            for (int i=0; i<5; i++)
            {
                arr[i]=0; //everything inside the array at the beginning is assigned to 0
            }
        }
        bool isEmpty ()//bool because it returns true or false
        {
            if (top ==-1)//if empty, return true, if not, return false.
                return true;
            else 
                return false;
        }
        bool isFull()
        {
            if (top==4)//stack has a maximum of 5 slots
                 return true;
            else
                 return false;     
        }
        void push(int val )
        {
            if (isFull())
            {
                cout <<"Chill bro, no space left"<<endl;
            }
            else 
            {
                top++;//add one value, top = 0.
                arr [top]= val;//at the first position of the array, store the value passed at the beginning of the function
            }
        }
        int pop()
        {
            if (isEmpty())
            {
                cout <<"There's nothing left here, tough luck"<<endl;
                return 0;
            }
            else 
            {
                int popValue = arr[top]; //pop the value at the top of the stack, in the index that top contains
                arr[top]=0;//after the value is popped, the place where that value was is replaced with zero
                top --;//decrement thne value of top.
                return popValue;
            }
        }
        int count ()
            {
                return (top + 1); //top is index, so the count should be index +1 since indexes start at 0.
            }
        int peek(int pos)
        {
            if (isEmpty())
            {
                cout <<"There's nothing left here, tough luck"<<endl;
                return 0;
            }
            else 
            {
                return arr[pos];
            }
        }
        void change(int pos, int val) 
        {
            arr[pos] = val;
            cout << " Value changed at location " <<pos << endl;
        }
        void display ()
        {
            cout <<"All values in the stack are "<< endl;
            for (int i = 4; i>=0; i--)
            {
                cout <<arr[i]<<endl;
            }
        }

};

int main ()
{
    Stack s1;
    int option, position, value;

    do
    {   
        cout <<"What operations do you want to perform? Select options, Enter 0 to exit"<<endl;
        cout <<"1. Push"<<endl;
        cout <<"2. Pop"<<endl;
        cout <<"3. isEmpty()"<<endl;
        cout <<"4. isFull"<<endl;
        cout <<"5. Peek"<<endl;
        cout <<"6. Count"<<endl;
        cout <<"7. Change"<<endl;
        cout <<"8. Display"<<endl;
        cout <<"9. Clear Screen"<<endl <<endl;
        
        cin >> option;
        switch (option)
        {
            case 1:
                cout << " Enter an item to push in the stack"<<endl;
                cin >>value;
                s1.push (value);
                break;
            case 2:
                cout << " Pop function called. Pop value is " << s1.pop() <<endl;
                break;
            case 3:
                if (s1.isEmpty())
                    cout << "Empty stack"<<endl;
                else 
                    cout << "Stack is not empty"<< endl;
                break;
            case 4:
                if (s1.isFull())
                    cout << "The stack is full"<< endl;
                else 
                    cout << "There are slots available in the stack"<<endl;
                break;
            case 5:
                cout << " What position do you wanna peek?"<<endl;
                cin >> position; //declared as we declared the s1 stack
                cout <<"Peak Function called. Value at position"<< position<< " is  "<<endl<<s1.peek(position)<<endl;
                break;
            case 6:
                cout <<"Count function called. No. of items in stack: "<<s1.count()<<endl;
                break;
            case 7:
                cout << "The Change function has been summoned"<<endl;
                cout <<"What position of yhe stack do you want to change?"<<endl;
                cin >> position ;
                cout << endl;
                cout << "What do you want to change it to?"<<endl;
                cin >> value;
                s1.change(position, value);//pass two arguments since the two are the ones involved in this execution
                break;
            case 8:
                cout << "The display function has been called" << endl;
                s1.display();
                break;
            case 9:
                system("cls");//clear everything 
                break;
            default:
                cout << "Pick from the displayed menu, you dolt"<<endl;
        }
    } 
    while 
    (
        option!=0
    );
    

    return 0;
}