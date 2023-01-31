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
        }
        else{
            Node * temp = head; // we don't miss the head that's why we make the temp
            while(temp->next != NULL){ // run until the temp next get equal to NULL 
                temp = temp->next; // move to the next node
            }
            temp->next = new Node(data); // create a new node next to the oldest node
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
            Node * temp = head; // temp is equal to he head
            head = head->next; // head move to the next node
            delete temp; // delete the head 
            temp = NULL; // NULL the alocated memory
        }
        else{
            // Middle Delete
            Node * temp = head;
            Node * temp2;
            while (temp != NULL) // Run until temp get equal to NULL
            {
                if(temp->next->data == del){ // temp next data get Equal to delete data
                    temp2 = temp->next; // temp2 is Equal to the deletation node
                    temp->next = temp->next->next; // temp next get equal to the temp next next 
                    delete temp2; // Delete the delete data
                    temp2 = NULL; // NULL the alocated memory
                    break;
                }
                temp = temp->next;
            }
            // End Delete
            // Uncomment this part to delete the last node
            // Node * temp = head;
            // Node * temp2;
            // while (temp->next->next != NULL)
            // {
            //     temp = temp->next;
            // }
            // temp2 = temp->next;
            // temp->next = NULL;
            // delete temp2;
            
        }
    }
    void Display(){
        Node * temp = head; // we don't miss the head that's why we make the temp
        while(temp != NULL){ // run until the temp get equal to NULL
            cout<<temp->data; // output the every single node
            temp = temp->next; // move to the next node
        }   
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
    obj.Delete(2);
    obj.Display();
    return 0;
}