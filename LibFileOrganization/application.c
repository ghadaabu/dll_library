#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*Application specific data structures*/
typedef struct person_{

    char name[32];
    int age;
    int weight;
} person_t;

static void
print_person_details(person_t *person){

    printf("Name = %s, Age = %d, weight = %d\n", person->name, person->age, person->weight);
}

static void
print_person_db(dll_t *person_db) {

    if(!person_db || !person_db->head) return;

    dll_node_t *head = person_db->head;
    person_t *data = NULL;

    while(head){
        data = head->data;
        print_person_details(data);
        head = head->right;    
    }
}

int 
main(int argc, char **argv){

    person_t *person1 = calloc(1, sizeof(person_t));
    strncpy(person1->name, "Abhishek", strlen("Abhishek"));
    person1->age = 31;
    person1->weight = 75;
    person_t *person2 = calloc(1, sizeof(person_t));
    strncpy(person2->name, "Joseph", strlen("Joseph"));
    person2->age = 41;
    person2->weight = 70;
    person_t *person3 = calloc(1, sizeof(person_t));
    strncpy(person3->name, "Jack", strlen("Jack"));
    person3->age = 29;
    person3->weight = 55;
	person_t *person4 = calloc(1, sizeof(person_t));
    strncpy(person4->name, "Bnbn", strlen("Bnbn"));
    person4->age = 26;
    person4->weight = 60;

    /*Create a new Linked List*/

    dll_t *person_db = get_new_dll();
    add_data_to_dll(person_db, person1);
    add_data_to_dll(person_db, person2);
    add_data_to_dll(person_db, person3);
    add_data_to_dll(person_db, person4);

    print_person_db(person_db);

    return 0;
}
