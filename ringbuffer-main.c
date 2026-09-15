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

int isFull(RingBuffer *buffer)
{
    return buffer->count == BUFFER_SIZE;
}

int isEmpty(RingBuffer *buffer)
{
    return buffer->count == 0;
}

int enqueue(RingBuffer *buffer, int value)
{
    if (isFull(buffer))
    {
        return 0;
    }
    
    buffer->data[buffer->head] = value;
    buffer->head = (buffer->head + 1) % BUFFER_SIZE;
    buffer->count++;
    return 1;

}

int dequeue(RingBuffer *buffer, int *value)
{
    if (isEmpty(buffer))
    {
        return 0;
    }
    *value = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
    buffer->count--;
    return 1;
}

void printBuffer (RingBuffer *buffer)
{
    if (isEmpty(buffer))
    {
        printf("The buffer is empty.\n");
    }
    for (int i = 0; i < buffer->count; i++)
        {
            int index = (buffer->tail + i) % BUFFER_SIZE;
            printf("%d ", buffer->data[index]);
        }
}

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
            printf("Add the value you want: ");
            scanf("%d", &value);

            if (enqueue(&buffer, value) == 0)
            {
                printf("Buffer is full.\n");
            }
            break;

            //if (isFull(&buffer))
            //{
            //    printf("Buffer is full. \n");
            //    break;
            //}
            //
            //printf("Add the value you want: ");
            //scanf("%d", &value);
            //buffer.data[buffer.head] = value;
            //buffer.head = (buffer.head + 1) % BUFFER_SIZE;
            //buffer.count++;
            //break;
        }
        case 2:
        {
            if (dequeue(&buffer, &value) == 0)
            {
                printf("Buffer is empty.\n");
            }
            else
            {
                printf("Removed value: %d\n", value);
            }
            break;

            //if (isEmpty(&buffer))
            //{
            //    printf("Buffer is empty. \n");
            //    break;
            //}
//
//
            //if (dequeue(&buffer, value) == 1)
            //{
            //    printf("Removed value: %d\n", value);
            //}
            //
//
            //value = buffer.data[buffer.tail];
            //buffer.tail = (buffer.tail + 1) % BUFFER_SIZE;
            //buffer.count--;
            //printf("Removed value: %d\n", value);
            //break;
        }
        case 3:
        {
            printBuffer(&buffer);
            break;           

            //if (isEmpty(&buffer))
            //{
            //    printf("Buffer is empty.\n");
            //    break;
            //}
//
            //for (int i = 0; i < buffer.count; i++)
            //{
            //    int index = (buffer.tail + i) % BUFFER_SIZE;
            //    printf("%d ", buffer.data[index]);
            //}
            //
            //break;
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