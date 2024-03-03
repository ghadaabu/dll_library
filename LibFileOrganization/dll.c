#include "dll.h"
#include <memory.h>
#include <stdlib.h>

/* Public Function Implementation to create and return
 * new empty doubly linked list*/
dll_t * get_new_dll(){

    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;
}

/* Public Function Implementation to add a new application data to DLL.
 * Returns 0 for succsessful insertion else -1 */
int add_data_to_dll (dll_t *dll, void *app_data){

    if(!dll || !app_data) return -1;

    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    /*Now add this to the front of DLL*/
    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    dll_new_node->right = first_node;
    first_node->left = dll_new_node;
    dll->head = dll_new_node;
    return 0;
}

/* Public Function Implementation to add a new application data to DLL.
 * Returns 0 for succsessful insertion else -1 */
int add_data_to_dll_end (dll_t *dll, void *app_data){
	if(!dll || !app_data) return -1;

	dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
	dll_new_node->left = NULL;
	dll_new_node->right = NULL;
	dll_new_node->data = app_data;

	// inserts the new node to the bigining if the list is empty
	if(!dll->head){
		dll->head = dll_new_node;
		return 0;
	}
	
	dll_node_t *tmp = dll->head;
	while (!tmp){
		tmp = tmp->right;
	}

	tmp->right = dll_new_node;
	dll_new_node->left = tmp;
	return 0;
}

/* Public Function Implementation to delete a node from DLL.
 * Returns 0 upon succsessful deletion, else -1 */
int delete_node (dll_t *dll, dll_node_t *node){
	
	if (!dll || !node) return -1;

	// the node to delete is the head of the list
	if (node == dll->head){
		dll->head = dll->head->right;
		dll->left = NULL;
		free(node);
		return 0;
	}

	// the node to delete is the last node in the list
	if (node->right == NULL){
		node->left = NULL;
		free(node);
		return 0;
	}
	
	node->left->right = node->right;
	node->right->left = node->left;
	free(node);
	return 0;
}

/* Public Function Implementation to delete the head node from DLL.
 * Returns 0 upon succsessful deletion, else -1 */
int delete_head (dll_t *dll){
	if (!dll || !dll->head) return -1;

	//if the list contains only the head
	if (!dll->head->right){
		free(dll->head);
		dll->head = NULL;
		return 0;
	}

	dll_node_t *tmp = dll->head;
	dll->head = tmp->right;
	dll->head->left = NULL;
	free(tmp);
	return 0;
}

/* Public Function Implementation to reverse a DLL.
 * Returns 0 upon succsessful reversion, else returns -1.*/
int reverse_dll (dll_t *dll){
	if (!dll) return -1;

	dll_node_t *tmp1 = dll->head;
	dll_node_t *tmp2 = NULL;

	while (!tmp2){
		tmp2 = tmp1->right;
		tmp1->right = tmp1->left;
		tmp1->left = tmp2;
		tmp1 = tmp2;
	}
	dll->head = tmp1;
	return 0;
}

/* Public Function Implementation to search for node based data.
 * Returns pointer to the node if found, else returns NULL.*/
dll_node_t * search (dll_t *dll, void *app_data){
	if (!dll || !app_data) return NULL;

	dll_node_t *tmp = dll->head;
	while (!tmp && tmp->data == app_data){
		tmp = tmp->right;
	}
	if (!tmp) return NULL;

	return tmp;
}

/* Public Function Implementation to find the position of a node based data.
 * Returns the postion of the node if found (pos starts from 0), else returns -1.*/
int find_node_pos (dll_t *dll, void *app_data){
	if (!dll || !app_data) return -1;

	dll_node_t *tmp = dll->head;
	int pos = 0;
	while (!tmp && tmp->data == app_data){
		tmp = tmp->right;
		pos++;
	}
	if (!tmp) return -1;

	return pos;
}

