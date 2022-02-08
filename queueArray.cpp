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
        cout << "\nqueue is full. Sorry Senpai !\n";
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
        cout << "Can't Pop, queue is already empty Senpai !!\n";
        return;
    }

    if (Size() <= 1)
        fId = lId = -1;
    else
        fId = (fId+1) % mx;
}

void Display(void){
    if (isEmpty()){
        cout << "\nqueue is empty.\n"; return;
    }

    cout << "queue : \n";
    if (fId > lId){
        for (int i=fId; i < mx; i++)
            cout << arr[i] << ' ';
        for (int i=0; i <= lId; i++)
            cout << arr[i] << ' ';
    }
    else {
        for (int i=fId; i <= lId; i++)
            cout << arr[i] << ' ';
    }

    cout << '\n';
}

int main(void){
    for (int i=1; i <= mx; i++)
        Push(i);

    cout << "size of queue is " << Size() << '\n';

    Display();

    for (int cnt = 1; cnt <= mx/2; cnt++)
        Pop();
    Display();

    for (int i=11; i <= 16; i++)
        Push(i);
    Display();

    cout << Front() << ' ' << Back() << '\n';

    //Pop();


    cout << fId << ' ' << lId << '\n';

    return 0;
}
