#include "iostream"
using namespace std;
#define mx 100
// empty, size, front, back, push, pop

int arr[mx];
int fId = -1, lId = -1; // front and rear

bool isEmpty(void){
    return fId == lId && fId == -1;
}

int Size(void){
    return isEmpty() ? 0 : lId-fId + 1;
}

int Front(void){
    return isEmpty() ? -1 : arr[fId];
}

int Back(void){
    return isEmpty() ? -1 : arr[lId];
}

void Push(int x){
    // check if queue is full
    if ((lId+1) % mx == fId){
        cout << "queue is full. Sorry Senpai !\n";
        return;
    }

    if (isEmpty())
        fId = lId = 0;
    else
        lId = (lId + 1) % mx ;

    arr[lId] = x;
}

void Pop(void){
    if (isEmpty()){
        cout << "queue is already empty Senpai !\n";
        return;
    }

    if (Size() <= 1)
        fId = lId = -1;
    else
        fId = (fId+1) % mx;
}

int main(void){
    for (int i=1; i <= 10; i++)
        Push(x);

}
