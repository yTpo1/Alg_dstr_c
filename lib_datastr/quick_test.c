#include <stdio.h>
//#include "lib_datastr/linked_list.h"
#include "linked_list.h"
#include "circ_link_list.h"

int main(int argc, char *argv[]){
    init_cl(3);
    insert_cl(9);
    insert_cl(8);
    insert_cl(7);
    insert_cl(6);
    traverse_list();
    /*init(3);*/
    /*insert(9);*/
    /*insert(8);*/
    /*insert(7);*/
    /*insert(6);*/
    /*print_list();*/
    return 0;
}
