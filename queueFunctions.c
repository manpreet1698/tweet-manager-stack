#include "headerA4.h"

tweet *createTweet(tweet *tweetList) // create a new tweet
{
    tweet *root = tweetList;

    tweet *node = malloc(sizeof(tweet));

    int sumOfUsername = 0;
    int userid = 0;
    int userLength = 0;
    int tweetLength = 0;
    int flag = 1;

    if (node == NULL) //checks if memory is allocated or not
    {
        printf("Memory not allocated\n");
        return NULL;
    }

    else
    {
        if (tweetList == NULL) //checks list is empty or not

        {
            printf("List is currently empty. Add your first tweet!\n");
        }

        printf("Enter a username: "); // prompts user for name
        scanf(" %[^\n]*c", node->user);

        userLength = strlen(node->user); // captures the length of username

        if (userLength > 51) // validates the total characters that can be taken in as "username"
        {
            printf("Length of user id excceds the limit\n");
            return NULL; // return if characters exceed 51
        }

        printf("Enter a tweet: "); // prompts user for tweet
        scanf(" %[^\n]*c", node->text);

        tweetLength = strlen(node->text); // captures the length of tweet

        if (tweetLength > 141) // validates the total characters that can be taken in as "tweet"
        {
            printf("Length of tweet excceds the limit\n");
            return NULL; // return if tweet length exceeds 141
        }

        if (userLength == 0) // validates if username length is 0
        {
            printf("User id can't be empty\n");
            return NULL;
        }

        if (tweetLength == 0) // validates if tweet length is 0
        {
            printf("Tweet text can't be empty\n");
            return NULL;
        }

        node->next = NULL; // declaring node

        for (int i = 0; i < userLength; i++) // calculates the user ascii value of username
        {
            sumOfUsername = sumOfUsername + node->user[i];
        }
        userid = sumOfUsername + tweetLength;

        if (root == NULL) // if root pointer is null
        {
            node->id = userid;
        }

        else
        {
            while (flag != 0)
            {
                while (root != NULL)
                {
                    if (userid == root->id) // checks if the userid is the same as an existing one
                    {
                        userid = userid + (1 + (rand() % 999)); // if so, then add a random number between 1 - 999
                        root = tweetList;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                        root = root->next;
                    }
                }
            }
        }

        node->id = userid;
        printf("Your computer generated id = %d\n", node->id);

        return node;
    }
}

int isEmpty(tweet *head) // function that checks if the given queue is empty - returns 1 if empty, 0 if not empty
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(tweet **head, tweet **tail, tweet *node)
{
    int emptyHead = 0;
    int emptyTail = 0;
    emptyHead = isEmpty(*head); // checks if head is null or not
    emptyTail = isEmpty(*tail); // checks if tail is null or not
    tweet *ptr;
    ptr = node; // assign the created node using createTweet function to ptr

    ptr->next = NULL; // declare next to null

    if (emptyHead == 1 && emptyTail == 1) // check if head and tail are empty (meaning if no information in the queue yet)
    {
        *head = *tail = ptr; // if so, appoint both head and tail pointers to ptr
    }
    else
    {
        (*tail)->next = ptr; // else go to the tail of the queue
        *tail = ptr;         // add newly created node to the tail
    }
}

void dequeue(tweet **head, tweet **tail)
{
    tweet *ptr = *head; // appoint head to ptr
    int emptyHead = 0;
    int emptyTail = 0;
    emptyHead = isEmpty(*head);
    emptyTail = isEmpty(*tail);

    if (emptyHead == 1 && emptyTail == 1) // check if both head and tail are null
    {
        *head = *tail = NULL;     // if so make them null
        printf("Queue empty \n"); // let the user know that the queue is empty
    }
    else
    {
        *head = ptr->next; // if queue is not empty, then traverse head
    }
    free(ptr); // delete node at the position of ptr
}

void printQueue(tweet *head) // takes the front of the queue and prints every element of the queue
{
    tweet *temp = head;
    if (isEmpty(temp) == 1) // checks if queue is empty
    {
        printf("Queue is empty!\n");
    }
    while (temp != NULL) // traverses through the queue
    {
        printf("<%d>: Created by <%s>: <%s>\n", temp->id, temp->user, temp->text); // prints out node contents
        temp = temp->next;                                                         // goes to the next node in the queue
    }
}
