#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person {
    char name[50];
    char phone[50];
    struct _person *next;
} person;

void search(person *head, char *query);


int main(void) {
    int s, i;
    person *head, *p, *tmp;

    printf("How many people?\n");
    scanf("%d", &s);
    printf("\n");

    head = NULL;
    for (i = 1; i <= s; i++) {
        p = (person *) malloc(sizeof(person));
        if (p == NULL) {
            printf("can't get a memory space\n");
            return 1;
        }

        printf("Input name : ");
        scanf("%s", p->name);

        printf("Input phone number : ");
        scanf("%s", p->phone);

        p->next = head;
        head = p;
    }

    printf("\n");

    /* 後から入力した順に出力 */
    p = head;
    while (p != NULL) {
        printf("name : %s\t phone number : %s\n", p->name, p->phone);
        p = p->next;
    }
    printf("\n");

    search(head, "a");

    /* 後から入力した順に解放 */
    p = head;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }

    return 0;
}


void search(person *head, char *query) {
    person *p;

    p = head;
    while (p != NULL) {
        if (strcmp(p->name, query) == 0) {
            printf("The name: \"%s\" found in the linear list.\n", query);
            return;
        }

        p = p->next;
    }

    printf("No match found in the linear list. (query: \"%s\")\n", query);
    return;
}
