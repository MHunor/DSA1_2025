#include <stdio.h>
#include "simple_queue.h"
int main(void) {
    Simple_Queue_t carQueue;
    createQueue(6, &carQueue);
    bool ok = true;
    while(ok) {
        printf("Choose from the following options:"
               "\n\t- Check if queue is empty: 1"
               "\n\t- Check if queue is full: 2"
               "\n\t- Add a new car to the queue: 3"
               "\n\t- Remove a car from the queue: 4"
               "\n\t- Display the cars waiting in the queue: 5"
               "\n\t- Exit: 0"
               "\n\nChoose an option:");
        int option;
        scanf("%i", &option);
        switch (option) {
            case 0:
                ok= false;
                break;
            case 1:
                if(isEmpty(carQueue)){
                    printf("A sor ures\n");
                }
                else { printf("Nem ures a sor\n");
                }
                break;
            case 2:
                if(isFull(carQueue)){
                    printf("Tele van a sor\n");
                }
                else { printf("A sor nincs tele\n");
                }
                break;
            case 3:
                char item[20];
                printf("Car plate: ");
                scanf("%s",item);
                enqueue(&carQueue, item);
                break;
            case 4:
                char *item2 = dequeue(&carQueue);
                if (item2) {
                    printf("Removed car: %s\n", item2);
                    free(item2);
                }
                break;
            case 5:
                display(carQueue);
                break;
            default:
                printf("Wrong number");
                break;
        }
    }

    return 0;
}


//(kell struct) array stack sor korkoros sor,
// nem int-ek vannak benne(hanem pl. labdak vagy viragok)
