//singly linked l;ist Data Structure

#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* nextNode;

        Node ()
        {
            key = 0; 
            data = 0;
            nextNode = NULL;
        }
        Node (int k, int d)
        {
            key = k;
            data = d;
        }

};

class SinglyLinkedList
{
    public:
        Node* head;

        SinglyLinkedList()
        {
            head = NULL; //head has nothing in it and points to no node
        }
        SinglyLinkedList(Node *n) //creating a node at point n
        {
            head = n;
        }

        //1. CHECK IF NODE EXISTS USING KEY VALUE
        Node *nodeExists(int k) //we pass the key that we wanna check for in K
        {
            Node* temp = NULL;

            Node * ptr = head;
            while (ptr !=NULL) //IF the pointer is pointing at a present node
            {
                if  (ptr -> key ==k) //only executes if the key value of the node which the current pointer is pointing to matches the value of the key that we passed
                {
                    temp = ptr;
                }
                ptr = ptr-> nextNode; //if the head doesn't match the key we are looking for, we move to the next node and store the next node address in the pointer.
            }
            return temp;//we gotta return sth since we are returning a pointer (of node type only)
        }

        //2. APPENDING A NODE TO THE LIST
        void appendNode(Node *n) //pass by address hence the void
        {
            if (nodeExists(n ->key)!=NULL)
            {
                cout <<"Node already ecists with key value "<<n->key<<". Append another node with a different key value"<<endl;
            }
            else 
            {
                if (head ==NULL)//in case there is no node in the entire linkedlist
                {
                    head = n;
                    cout <<" Node Appended (First Node)"<<endl;
                }
                else //transversing code
                {
                    Node * ptr = head;
                    while (ptr ->nextNode!=NULL)
                    {
                        ptr = ptr->nextNode;
                    }
                
                    ptr -> nextNode = n;
                    cout<< " Node Appended"<<endl;
                }

            }
        }

        //3. Prepend Node - Attaching a node at the beginning of a linked list

        void prependNode(Node* n)
        {
             if (nodeExists(n ->key)!=NULL)
            {
                cout <<"Node already ecists with key value "<<n->key<<". Append another node with a different key value"<<endl;
            }
            else //no need to transverse the list since we are just appending the node at the beggining of the list
            {
                n->nextNode = head;
                head = n;
                cout <<" Node prepended"<<endl;
            }
        }

        //4. insert a node after a particular node

        void insertNodeAfter (int k, Node *n) //k - key of the node after which we insert another. n - the node we wanna attach
        {
            Node *ptr = nodeExists(k);
            if (ptr ==NULL)
            {
                cout <<"No node exists with the key value "<<k<<endl;
            }
            else 
            {
                if (nodeExists(n ->key)!=NULL)
                {
                cout <<"Node already ecists with key value "<<n->key<<". Append another node with a different key value"<<endl;
                }
                else 
                {
                    //these two next lines CANNOT be inversed
                    n->nextNode = ptr -> nextNode; //next pointer inside the node we are insering, should store the address in the node that comes before it(which points at the node that comes after it)   
                    ptr->nextNode = n;  
                    cout <<" Node Inserted"  <<endl;            
                } 
            }
        }

        //5. Delete Node by a particular Key
        void deleteNodeByKey (int k)
        {
            if (head == NULL)
            {
                cout << " The Singly List is empty. There is nothing to delete"<<endl;
            }
            else if (head != NULL)
            {
                if (head->key == k)
                {
                    head ==head->nextNode;
                    cout<<" Node Unlinked with keys Value " <<k<<endl;
                }
                else 
                {
                    Node* temp = NULL;
                    Node* PrevPtr = head;
                    Node* CurrentPtr = head->nextNode;
                    while (CurrentPtr!=NULL)
                    {
                        if (CurrentPtr ->key ==k)
                        {
                            temp = CurrentPtr;
                            CurrentPtr = NULL;
                        }
                        else 
                        {
                            PrevPtr = PrevPtr -> nextNode;
                            CurrentPtr = CurrentPtr -> nextNode;
                        }
                    }
                    if (temp != NULL)
                    {
                        PrevPtr -> nextNode = temp -> nextNode;
                        cout<< " Node with key value "<<k<<" unlinked with the rest of the list"<<endl;
                    }
                    else 
                    {
                        cout << "Node with the key "<< k<< " does not exist"<<endl;
                    }
                }
            }
        }

        //6. Update Node ny Key
        void updateNodeByKey(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if (ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node Data Updated Successfully"<<endl;
            }
            else 
            {
                cout<<" Nodfe with the key vale" << k << " does not exist"<< endl;
            }
        }

        //7. Printing
        void printList() 
        {
            if (head == NULL) 
            {
                cout << "No Nodes in Singly Linked List";
            } 
            else  
            {
                cout << endl << "Singly Linked List Values : ";
                Node * temp = head;

                while (temp != NULL) 
                {
                    cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                    temp = temp -> nextNode;
                }
            }
        }
       

};


int main ()

{
  SinglyLinkedList s; //create object s
  int option;
  int key1, k1, data1;
  do //menu-driven program
  {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node(); //dynamic memory allocation. new creates a heap and remains global
   

    switch (option) 
    {
        case 0:
            break;
        case 1:
        cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
        cin >> key1;
        cin >> data1;
        n1 -> key = key1;
        n1 -> data = data1;
        s.appendNode(n1); //argument passed by address
      //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
        cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
        cin >> key1;
        cin >> data1;
        n1 -> key = key1;
        n1 -> data = data1;
        s.prependNode(n1);
            break;

        case 3:
        cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
        cin >> k1;
        cout << "Enter key & data of the New Node first: " << endl;
        cin >> key1;
        cin >> data1;
        n1 -> key = key1;
        n1 -> data = data1;

        s.insertNodeAfter(k1, n1);
            break;

        case 4:

        cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
        cin >> k1;
        s.deleteNodeByKey(k1);

            break;
        case 5:
        cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
        cin >> key1;
        cin >> data1;
        s.updateNodeByKey(key1, data1);

            break;
        case 6:
        s.printList();

            break;
        case 7:
        system("cls");
            break;
        default:
        cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);


    return 0;

}
