/*Header file for Doubly Linked List*/

typedef struct dll_node_{

    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
} dll_t;


/* Public Function declaration to create and return
 * a new empty doubly linked list*/
dll_t * get_new_dll();

/* Public Function Implementation to add a new application data to DLL.
 * Returns 0 for succsessful insertion else -1 */
int add_data_to_dll (dll_t *dll, void *app_data);

/* Public Function Implementation to add a new application data to end of the DLL.
 * Returns 0 for succsessful insertion else -1 */
int add_data_to_dll_end (dll_t *dll, void *app_data);

/* Public Function Implementation to delete a node from DLL.
 * Returns 0 upon succsessful deletion, else -1 */
int delete_node (dll_t *dll, dll_node_t *node);

/* Public Function Implementation to delete the head node from DLL.
 * Returns 0 upon succsessful deletion, else -1 */
int delete_head (dll_t *dll);

/* Public Function Implementation to reverse a DLL.
 * Returns 0 upon succsessful reversion, else returns -1.*/
int reverse_dll (dll_t *dll);

/* Public Function Implementation to search for node based data.
 * Returns pointer to the node if found, else returns NULL.*/
dll_node_t * search (dll_t *dll, void *app_data);

/* Public Function Implementation to find the position of a node based data.
 * Returns the postion of the node if found (pos starts from 0), else returns -1.*/
int find_node_pos (dll_t *dll, void *app_data);
