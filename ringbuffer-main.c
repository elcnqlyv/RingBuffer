#include <stdio.h>

#define BUFFER_SIZE 5

typedef struct 
{
    int data[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} RingBuffer;

RingBuffer buffer = {0};

int main()
{
    int value = 0;
    int choice;
    do
    {
        printf("\n1. Add value \n");
        printf("2. Remove value\n");
        printf("3. Show buffer\n");
        printf("4. Exit\n");

        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (buffer.count == BUFFER_SIZE)
            {
                printf("Buffer is full. \n");
                break;
            }
            
            printf("Add the value you want: ");
            scanf("%d", &value);
            buffer.data[buffer.head] = value;
            buffer.head = (buffer.head + 1) % BUFFER_SIZE;
            buffer.count++;
            break;
        }
        case 2:
        {
            if (buffer.count == 0)
            {
                printf("Buffer is empty. \n");
                break;
            }

            value = buffer.data[buffer.tail];
            buffer.tail = (buffer.tail + 1) % BUFFER_SIZE;
            buffer.count--;
            printf("Removed value: %d\n", value);
            break;
        }
        case 3:
        {
            if (buffer.count == 0)
            {
                printf("Buffer is empty.\n");
                break;
            }

            for (int i = 0; i < buffer.count; i++)
            {
                int index = (buffer.tail + i) % BUFFER_SIZE;
                printf("%d ", buffer.data[index]);
            }
            
            break;
        }        
        case 4:
        {
            printf("Exiting...\n");
            break;
        }
        default:
            break;
        }
        
    } while (choice != 4);
    

    return 0;
}