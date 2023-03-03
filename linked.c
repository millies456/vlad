#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int num;
    struct node* next;
};
struct node* last_occur(struct node* head, int x) {
    struct node* last = NULL;
    while (head != NULL) {
        if (head->data == x) {
            last = head;
        }
        head = head->next;
    }
    return last;
}
void delete_node(struct node** head_ref, int x) {
    struct node* current = *head_ref;
    struct node* prev = NULL;
    while (current != NULL && current->data != x) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (prev == NULL) {
        *head_ref = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
}

void insert_node(struct node** h, struct node** t, int v) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    new_node->num = v;
    new_node->next = NULL;
    if (*h == NULL) {
        *h = new_node;
        *t = new_node;
    } else {
        (*t)->next = new_node;
        *t = new_node;
    }
}

void print_list(struct node* h) {
    struct node* current = h;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    struct node* head = NULL;
    struct node* tail = NULL;
    srand(time(NULL));
    int count = 0;
    while (1) {
        int num = rand() % 25;
        if (num == 8) {
            break;
        }
        insert_node(&head, &tail, num);
        count++;
    }
    printf("Size of list: %d\n", count);
    printf("List: ");
    print_list(head);
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
