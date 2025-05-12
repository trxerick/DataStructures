/*
    Linked List class
*/

#include "node.h"

class LinkedList
{
    private:
        Node* head;
        int node_counter;

        void inc_nodes_counter();
        void dec_nodes_counter();

    public:
        
        bool insert_beggining(int data);
        bool insert_after(int id, int data);
        bool insert_before(int id, int data);
        bool remove_beggining();
        bool remove_after(int id);
        bool remove_before(int id);
        int get_nodes_counter();
        void print_list();

        LinkedList(): head(nullptr), node_counter(0){};
        ~LinkedList();
};