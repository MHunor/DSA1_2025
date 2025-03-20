
#include <time.h>
#include "array.h"
int main(void) {

    IntArray array;
    createIntArray(10,&array);
    printArray(array);
    for(int i = 1; i < array.capacity/2;i++){
        insertFirst(&array,i);
    }
    printArray(array);
    for(int i = array.size+1; i <= array.capacity;i++){
        if(i%2==0){
            insertFirst(&array,i);
        }
        else
            insertLast(&array,i);
    }
    printArray(array);
    int n,m;
    int pozicio;
    printf("irj be egy szamot: ");
    scanf("%d",&n);
    pozicio=search(array,n);
    printf("A %d pozicioja: %d\n",n ,pozicio);

    printf("irj be egy szamot: ");
    scanf("%d",&m);
    deleteItemAt(&array,pozicio);
    insertAt(&array,pozicio,m);
    printArray(array);


    srand(time(NULL));
    int temp=array.size;
    while (!isEmpty(array)) {
        int position = rand() % array.capacity;
        deleteItemAt(&array, position);
        if(array.size!=temp)
        {
            printf("Sikeres torles.\n");
            temp--;
            printArray(array);

        } else
        {
            printf("Sikertelen torles.\n");
        }
    }

    deallocateIntArray(&array);
    return 0;
}
