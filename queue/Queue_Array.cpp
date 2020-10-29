#include <bits/stdc++.h>
using namespace std;
#define size 3 //it also can be user input
int Queue[size], front = -1, rear = -1;

void enqueue(int Queue[], int temp)
{
    if (rear == size - 1)
    {
        cout << "\n QUEUE OVERFLOW";
        return;
    }
    else if (rear == -1)
    {
        front = rear = 0;
        Queue[rear] = temp;
    }
    else
    {
        rear++;
        Queue[rear] = temp;
    }
}

void dequeue(int Queue[])
{
    if (front == -1)
    {
        cout << "\n QUEUE UNDERFLOW";
        return;
    }
    if (front == rear)
    {
        cout << "\n THE DELETED ITEM IS " << Queue[front];
        front = -1;
    }

    else
    {
        cout << "\n THE DELETED ITEM IS " << Queue[front];
        front++;
    }
}
//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com
void display_Queue(int Queue[], int front, int rear)
{
    if (front == -1)
        cout << "\n QUEUE UNDERFLOW";
    else
    {
        cout << "\n QUEUE IS :";
        for (int i = front; i < rear; ++i)
        {
            cout << Queue[i] << " ";
        }
        cout << Queue[rear];
    }
}

int main()
{
    int item, choice, ret;

    cout << "\n\n OPERATION MENU\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT ";
    do
    {
        cout << "\n\n ENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n ENTER THE ITEM :";
            cin >> item;
            enqueue(Queue, item);
            break;
        }
        case 2:
        {
            dequeue(Queue);
            break;
        }
        case 3:
        {
            display_Queue(Queue, front, rear);
            break;
        }
        case 4:
        {
            break;
        }
        }
    } while (choice != 4);
    return 0;
}
