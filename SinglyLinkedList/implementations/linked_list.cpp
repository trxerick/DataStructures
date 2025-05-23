#include "../headers/linked_list.h"

void LinkedList::inc_nodes_counter()
{
    node_counter++;
}

void LinkedList::dec_nodes_counter()
{
    node_counter--;
}

int LinkedList::get_nodes_counter()
{
    return node_counter;
}

bool LinkedList::insert_beggining(int data)
{
    head = new Node(current_id_in_use++, data, head);
    inc_nodes_counter();

    return true;
}

bool LinkedList::insert_after(int id, int data)
{
    Node* cur_node, *tmp_node, *new_node;

    if(node_counter == 0) // If list is empty return
    {
        return false;
    }

    cur_node = head;

    while(cur_node != nullptr)
    {
        if(cur_node->get_id() == id) // If required id was found
        {
            tmp_node = cur_node->get_next_node();
            new_node = new Node(current_id_in_use++, data, tmp_node);
            cur_node->set_next(new_node);
            inc_nodes_counter();

            return true;
        }

        cur_node = cur_node->get_next_node();
    }

    return false;
}

bool LinkedList::insert_before(int id, int data)
{
    Node* cur_node = head, *tmp_node = nullptr, *prev_node = nullptr, *new_node = nullptr;

    if(get_nodes_counter() == 0) 
    {
        std::cout << "Operation insert_before() failed - The list is empty!\n";
        return false;
    }

    if(cur_node->get_id() == id)
    {
        insert_beggining(data);
        std::cout << "Operation insert_before() inserted element at the beginning of the list!\n";
        return true;
    }

    while(cur_node != nullptr)
    {
        if(cur_node->get_id() == id)
        {
            new_node = new Node(current_id_in_use++, data, cur_node);
            prev_node->set_next(new_node);
            inc_nodes_counter();
            std::cout << "Operation insert_before() inserted element after id = " << id << '\n';
            return true;
        }

        prev_node = cur_node;
        tmp_node = cur_node;
        cur_node = tmp_node->get_next_node();
    }

    return false;
}

bool LinkedList::remove_before(int id)
{
    Node* cur_node, *next_after_current_node, *prev_before_current_node, *next_after_found_node;

    cur_node = head;
    prev_before_current_node = nullptr;

    if(get_nodes_counter() == 0)
    {
        std::cout << "List is empty! There are no elements to delete!\n";
        return false;
    }

    while(cur_node != nullptr)
    {
        next_after_current_node = cur_node->get_next_node();
        if(next_after_current_node != nullptr)
        {
            if(next_after_current_node->get_id() == id)
            {
                next_after_found_node = cur_node->get_next_node()->get_next_node();
                cur_node->set_next(next_after_found_node);
            } else 
            {

            }
        }

        cur_node = next_after_current_node;
    }
}

void LinkedList::print_list()
{
    Node* cur_node = head;

    if(node_counter == 0)
    {
        std::cout << "The list is empty!";
        return;
    }

    while(cur_node != nullptr)
    {
        cur_node->print_node();
        cur_node = cur_node->get_next_node();
    }
}

LinkedList::~LinkedList()
{
    Node* cur_node = head;
    Node* tmp_node;

    while(cur_node != nullptr)
    {
        tmp_node = cur_node->get_next_node();
        delete cur_node;
        cur_node = tmp_node;
    }
}