#include "headers/linked_list.h"

int main()
{
    LinkedList list;

    for(int i = 0; i < 5; i++)
        list.insert_beggining(i);

    list.insert_before(7, 100);

    /*for(int i = 1 ; i < 5; i++)
        list.insert_after(i, i);

    list.insert_before(3, 6);
    list.insert_before(6, 100);
    list.insert_after(7, 200);*/

    list.print_list();

    std::cout << "\nList contains " << list.get_nodes_counter() << " elements";

    return 0;
}