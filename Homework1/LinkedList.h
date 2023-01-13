/*
    CH-231-A by Dr. Kinga Lipskoch
    Name: Sanjay Timilsena
    Mail: s.timilsena@jacobs-university.de
    Problem: h1_p3
*/

#include<iostream>

using namespace std;

//defining a node of the list
template<typename Type>
class node
{
    public:
        Type element;
        node* prev;
        node* next;

        node(Type value){element=value;}
};

//defining the linked list
template<typename Type>
class Linked_list
{
    private:
        node<Type>  *first;
        node<Type>  *last;
        int size;

    public:
        //default constructor
        Linked_list(){ first = NULL; last= NULL; size=0;}
        //destructor
        ~Linked_list(){
            if (first != NULL)
            {
                node<Type> *third;
                node<Type> *newnode = this->first;

                //deleting each node
                while (newnode != NULL)
                {
                    third = newnode;
                    newnode = newnode->next;
                    delete third;
                }
            }
        }

        //defining getters
        Type getFirst(){ return first->element;}
        Type getLast(){ return last->element;}
        Type getSize(){ return this->size;}

        //defining methods of linked list class
        void push_front(Type elem){
            node<Type> *newnode = new node<Type>(elem);
            newnode->next = this->first;
            newnode->prev = NULL;
            this->size++;
            //If the list is initially empty
            if (this->size == 1)
            {
                this->first = this->last = newnode;
            }
            else
            {
                this->first= newnode;
                newnode->next->prev = newnode;
            }
        }

        void push_back(Type elem)
        {
            node<Type> *newnode = new node<Type>(elem);
            newnode->next = NULL;
            newnode->prev = this->last;
            this->size++;

            //If the list is initially empty
            if (this->size == 1)
            {
                this->first = this->last = newnode;
            }
            else
            {
                this->last = newnode;
                newnode->prev->next = newnode;
            }
        }
       
        //defining method to delete the element at last
        Type pop_back()
        {
            node<Type> *temp = NULL;

            if (this->size > 0)
            {
                temp = this->last;
                this->last = temp->prev;
                Type val = temp->element;
                delete temp;
                this->size--;
                return val;
            }
            else
            {
                cout << "Error! The list is empty." << endl;
                return this->first->element;
            }
        }

        //defining method to delete the element at first
        Type pop_front()
        {
            node<Type> *temp = NULL;

            if (this->size > 0)
            {
                temp = this->first;
                this->first = temp->next;
                Type val = temp->element;
                delete temp;
                this->size--;
                return val;
            }
            else
            {
                cout << "Error! The list is empty." << endl;
                return this->first->element;
            }
        }

};
