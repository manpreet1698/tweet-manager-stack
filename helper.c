// helper function used in this assignment

#include "headerA4.h"

int numberOfIds(tweet *head) // returns the total number of user ids in the queue
{
    tweet *temp = head;
    int count = 0;

    if (isEmpty(temp) == 1) // checks if queue is empty
    {
        printf("Queue is empty\n");
    }

    while (temp != NULL) // traverses through the list
    {
        count++;
        temp = temp->next; // goes to next node in queue
    }

    return count;
}