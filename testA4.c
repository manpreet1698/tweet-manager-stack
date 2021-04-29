#include "headerA4.h"
int main()
{
    tweet *node = NULL;
    tweet *head = NULL;
    tweet *tail = NULL;
    tweet *enqueueNode;
    tweet *empty = NULL;

    printf("Beginning A4 program testing ...\n");
    printf("Creating initial queue list ...\n");
    for (int i = 0; i < 5; i++) // create the initial queue by adding 5 nodes to it
    {
        node = createTweet(head);
        enqueue(&head, &tail, node);
        printf("\n");
    }
    printf("Verifying queue content via printQueue\n");
    printQueue(head); // display the contents of queue to the user

    printf("\n");
    fflush(stdin);
    printf("Press enter to continue\n"); // pause the program until user presses enter
    getchar();

    printf("Testing [Enqueue] function\n"); // testing of enqueue function begins
    for (int i = 1; i < 4; i++)             // loop runs 3 times
    {
        printf("Please enter your tweet to be queued in the list\n"); // prompt user to add tweet to queue
        printf("\n");

        enqueueNode = createTweet(head);
        enqueue(&head, &tail, enqueueNode); // add created tweet to queue
        printf("\n");

        // print out contents of node created
        printf("Iteration [%d]: [Node]: %d: Created by %s: %s", i, enqueueNode->id, enqueueNode->user, enqueueNode->text);
        printf("\n\n");
        printf("After enqueue, queue looks like:\n");
        printQueue(head); // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }

    printf("Testing [Dequeue] function\n"); // testing of dequeue function begins
    for (int i = 1; i < 4; i++)
    {
        printf("Iteration [%d]", i);
        printf("\n\n");
        printf("After dequeue #%d, queue looks like:\n", i); // print message after each dequeue executed

        dequeue(&head, &tail); // run the dequeue function and remove the head node
        printQueue(head);      // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }

    // testing of isEmpty function begins
    printf("Testing [isEmpty] function\n");
    printf("Testing with list, expecting !isEmpty\n");
    if (isEmpty(head) == 0) // go inside if current queue is not empty
    {
        printf("SUCCESS: list is not empty\n");
        printf("Verifying queue content via printQueue\n");
        printQueue(head); // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }
    else if (isEmpty(head) == 1) // go inside if current queue is empty
    {
        printf("Sorry the contents of passed pointer to struct is empty :(\n");
        printf("Verifying queue content via printQueue\n"); // verify to user that queue is empty
        printQueue(head);                                   // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }

    printf("Testing with list after two dequeues, expecting !isEmpty\n"); // test by removing top 2 elements in the queue
    dequeue(&head, &tail);                                                // remove first element from top
    dequeue(&head, &tail);                                                // remove second element from top
    if (isEmpty(head) == 0)                                               // go inside if queue is still not empty
    {
        printf("SUCCESS: list is not empty\n");
        printf("Verifying queue content via printQueue\n");
        printQueue(head); // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }
    else if (isEmpty(head) == 1) // go inside if queue is empty
    {
        printf("Sorry the contents of passed pointer to struct is empty :(\n");
        printf("Verifying queue content via printQueue\n"); // verify to user that queue is empty
        printQueue(head);                                   // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }

    printf("Testing with empty queue, expecting isEmpty\n"); // testing isEmpty by passing in an empty pointer to struct
    if (isEmpty(empty) == 1)                                 // go inside if passed queue is empty
    {
        printf("SUCCESS: empty list declared as empty\n");
        printf("Verifying queue content via printQueue\n");
        printQueue(empty); // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }

    else if (isEmpty(empty) == 0) // go inside if queue is not empty
    {
        printf("Sorry the contents of passed pointer to struct is empty :(\n");
        printf("Verifying queue content via printQueue\n"); // verify to user that queue is not empty
        printQueue(empty);                                  // show user the current state of queue

        printf("\n");
        fflush(stdin);
        printf("Press enter to continue\n"); // pause the program until user presses enter
        getchar();
    }

    // we do not need to test out the printQueue function as it has already been verified through our testing
    printf("Testing [printQueue] function\n");
    printf("printQueue was used through the verification process already...\n");

    printf("\n");
    fflush(stdin);
    printf("Press enter to continue\n"); // pause the program until user presses enter
    getchar();

    // testing of sortID function begins
    printf("Testing [sortID] function\n");

    sortID(&head, &tail); // pass in our current head and tail
    printQueue(head);     // show the state of queue after it has been sorted according to user ids

    printf("\n");
    fflush(stdin);
    printf("Press enter to continue\n"); // pause the program until user presses enter
    getchar();

    // testing of sortUsername function begins
    printf("Testing [sortUsername] function\n");

    sortUsername(&head, &tail); // pass in our current head and tail
    printQueue(head);           // show the state of queue after it has been sorted according to user names

    printf("\n");
    fflush(stdin);
    printf("Press enter to continue\n"); // pause the program until user presses enter
    getchar();

    // testing of reverse function begins
    printf("Testing [reverse] function\n");

    reverse(&head, &tail); // pass in our current head and tail
    printQueue(head);      // show the state of queue after it has been reversed

    printf("\n");
    fflush(stdin);
    printf("Press enter to continue\n"); // pause the program until user presses enter
    getchar();

    printf("Program testing completed :)\n");

    while (head != NULL) // free head by traversing through it to avoid memory leaks
    {
        tweet *temp = head->next;
        free(head);  // free memory of each node
        head = temp; // goes to next node in queue
    }

    return 0;
}
