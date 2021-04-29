#include "headerA4.h"

void sortID(tweet **head, tweet **tail)
{
    int i, j;
    int temp;
    tweet *front;
    tweet *nextNode;
    char user[51];
    char text[141];

    int count = numberOfIds(*head); // count the total number of user ids in the queue
    *tail = *head;                  // appoint head and tail to each other as we will be traversing through it to sort our queue
    *head = *tail;

    for (i = count - 2; i >= 0; i--) // number of passes of sort algorithm
    {
        front = *head;           // assign head to front pointer
        nextNode = front->next;  // assign the next node in the queue of the head to nextNode
        for (j = 0; j <= i; j++) // go through each node in queue
        {
            if (front->id > nextNode->id) // if the user id of front is greater than nextNode user id, then go in
            {
                temp = front->id; // swap user ids
                front->id = nextNode->id;
                nextNode->id = temp;
                strcpy(user, front->user); // swap usernames
                strcpy(front->user, nextNode->user);
                strcpy(nextNode->user, user);
                strcpy(text, front->text); // swap tweets
                strcpy(front->text, nextNode->text);
                strcpy(nextNode->text, text);
            }
            front = nextNode;          // increment front so that it can go to the next node in the queue
            nextNode = nextNode->next; // increment nextNode as well so that the next node can be compared with front
        }
    }
}

void reverse(tweet **head, tweet **tail)
{

    tweet *current;
    tweet *previous;
    tweet *next;
    *tail = *head; // appoint head and tail to each other as we will be traversing through it to sort our queue
    *head = *tail;

    current = *head; // assign head to current
    previous = NULL; // declare previous to null (this will be used to break and create new links)

    while (current != NULL) // traverse queue using current
    {
        next = current->next;     // store the address of next node in next
        current->next = previous; // create a link pointing towards previous
        previous = current;       // assign the data of current to previous (resetting pointers to traverse through the list)
        current = next;           // go to next node in queue by assigning the value of next to current (resetting pointers to traverse through the list)
    }
    *head = previous; // appoint head to previous as traversing has completed
}

void sortUsername(tweet **head, tweet **tail)
{
    int i, j;
    int temp;
    tweet *front;
    tweet *nextNode;
    char user[51];
    char text[141];

    int count = numberOfIds(*head); // count the total number of usernames in the queue
    *tail = *head;                  // appoint head and tail to each other as we will be traversing through it to sort our queue
    *head = *tail;

    for (i = count - 2; i >= 0; i--) // number of passes of sort algorithm
    {
        front = *head;           // assign head to front pointer
        nextNode = front->next;  // assign the next node in the queue of the head to nextNode
        for (j = 0; j <= i; j++) // go through each node in the queue
        {
            if (strcmp(front->user, nextNode->user) > 0) // compare the ascii values of usernames and if front is greater than nextNode then go in
            {
                temp = front->id; // swap user ids
                front->id = nextNode->id;
                nextNode->id = temp;
                strcpy(user, front->user); // swap usernames
                strcpy(front->user, nextNode->user);
                strcpy(nextNode->user, user);
                strcpy(text, front->text); // swap tweets
                strcpy(front->text, nextNode->text);
                strcpy(nextNode->text, text);
            }
            front = nextNode;          // increment front so that it can go to the next node in the queue
            nextNode = nextNode->next; // increment nextNode as well so that the next node can be compared with front
        }
    }
}
