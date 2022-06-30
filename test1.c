#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char *string;
    struct list *next;
};

typedef struct list LIST;

int main(void) {
    FILE *fp;
    char line[128];
    LIST *current, *head;
    int i;

    head = current = NULL;
    fp = fopen("content.txt", "r");

    while(fgets(line, sizeof(line), fp)){
        LIST *node = malloc(sizeof(LIST));
        node->string = strdup(line);//note : strdup is not standard function
        node->next =NULL;

        if(head == NULL){
            current = head = node;
        } else {
            current = current->next = node;
        }
    }
    fclose(fp);
    //test print
    i = 0;
    for(current = head; current ; current=current->next){
        printf("line: %d - content: %s",i,  current->string);
        i++;
    }
    //need free for each node
    return 0;
}