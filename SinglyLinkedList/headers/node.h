/* 
   Node class 
   
   Fields:
   id - unique number of node in linked list
   data - data stored in node
   next - pointer to the next node of linked list 

*/

#include <iostream>

class Node
{
    private:
        int id, data;
        Node* next;

    public:
        Node(int m_id, int m_data): id(m_id), data(m_data), next(nullptr){}
        Node(int m_id, int m_data, Node* m_next): id(m_id), data(m_data), next(m_next){}
        ~Node(){}
        
        Node* get_next_node();
        int get_id();

        void set_next(Node* next_node);

        void print_node();

};