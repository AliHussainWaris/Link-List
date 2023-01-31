#include <iostream>
using namespace std;
// ADT Single Linked List
class LL{
    private: // Access Specifier
    // We make the Node private not any of the other class access Node
    // Node class to create new Node
    class Node{  
        public: // Access Specifier
        int data; 
        Node * next; // Next data type is Node
        Node(int data){
            this->data = data;
            next = NULL;
        }
    };
    Node * head; // this is pointing to the head
    public:
    LL(){
        head = NULL;
    }
    void Insert(int data){
        if( head == NULL){ // check the head is null
            head = new Node (data); // insertin the data in head
            head->next = head;
        }
        else{
            Node * temp = head; // we don't miss the head that's why we make the temp
            Node * temp2 = new Node(data); // create a new node next to the oldest node
            while(temp->next != head){ // run until the temp next get equal to NULL 
                temp = temp->next; // move to the next node
            }
            temp->next = temp2; // temp next will be the new Node temp2
            temp2->next = head; // temp2 next will be head
        }
    }
    void Search(int search){
        Node * temp = head;
        while (temp->data != search) // run until the temp data get equal to search
        {
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
    void Delete(int del){
        // Head Delete
        if(del == head->data){ // check that the head data and deletation data is equal
            Node * temp = head;
            Node * temp2 = head;
            do{
                temp = temp->next;
            }while(temp->next != head); // get the last node
                head = head->next; // head move to the next node
                temp->next = head; // last node pointing to the head
                delete temp2; // deleting the head
                temp2 = NULL; // NULL the alocated memory
        }
        else{
            // Middle Delete
            Node * temp = head;
            Node * temp2;
            do{
                if(temp->next->data == del){ // temp next data get Equal to delete data
                    temp2 = temp->next; // temp2 is Equal to the deletation node
                    temp->next = temp->next->next; // temp next get equal to the temp next next
                    delete temp2; // Delete the node
                    temp2 = NULL; // NULL the alocated memory
                    break;
                }
                temp = temp->next;
            }while(temp != head); // Run until temp get equal to head
            // End Delete
            // Uncomment this part to delete the last node
            // Node * temp = head;
            // Node * temp2;
            // do{
            //     temp = temp->next;
            // }while (temp->next->next != head);
            // temp2 = temp->next; // deleting the last node
            // temp->next = head; // pointing to the head
            // delete temp2; // Delete the last node
            // temp2 = NULL; // NULL the alocated memory
        }
    }
    void Display(){
        Node * temp = head; // we don't miss the head that's why we make the temp
        do{
            cout<<temp->data; // output the every single node
            temp = temp->next; // move to the next node
        }while(temp != head); // run until the temp get equal to head
    }
};
int main(){
    LL obj; // Creating an object of a class
    obj.Insert(1);
    obj.Insert(2);
    obj.Insert(3);
    obj.Insert(4);
    cout<<"- - - DISPLAY - - -"<<endl;
    obj.Display();
    cout<<"\n- - - SEARCH - - -"<<endl;
    obj.Search(4);
    cout<<"- - - DELETE - - -"<<endl;
    obj.Delete(4);
    obj.Display();
    return 0;
}