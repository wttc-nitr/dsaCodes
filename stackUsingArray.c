#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define mx 100

int *arr = NULL;
int id = -1;

int Top(void){
    return arr[id];
}

bool isEmpty(void){
    if (id >= 0)
        return false;
    return true;
}

void Pop(void){
    if (isEmpty())
        printf("stack is already empty.\n");
    else
        id--;
}

void Push(int x){
    if (id == mx -1)
        arr = realloc(arr, 2*mx * sizeof(int));

    id++;
    arr[id] = x;
}

void Display(void){
    for (int i=0; i <= id; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void){
    arr = (int*)calloc(mx , sizeof(int));

    for (int i=1; i <= 10; i++)
        Push(i);

    Display();

    for (int cnt=1; cnt <= 5; cnt++) {
        printf("top element is %d.\n", Top());
        Pop();
    }

    printf("top element is %d.\n", Top());

return 0;
}
