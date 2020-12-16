#include <iostream>
using namespace std;

typedef struct node *lptr;
struct node
{
    int data;
    struct node *next;
};

struct stack
{
    int size;
    int top;
    int elements[100];
};

void push(struct stack &S, int k)
{
    if (S.top == S.size - 1)
        cout << "Stack full" << endl;
    else
        S.elements[++S.top] = k;
}

int pop(struct stack &S)
{
    return (S.top < 0 ? -1 : S.elements[S.top--]);
}

int peek(struct stack S)
{
    return S.top < 0 ? -1 : S.elements[S.top];
}

void input(lptr &L)
{
    int k;
    cin >> k;
    if (k != -1)
    {
        L = new (node);
        L->data = k;
        L->next = NULL;
        input(L->next);
    }
}

// points end node of L1 to the node in L2 with value k
void point(lptr L1, lptr L2, int k)
{
    while (L1->next != NULL)
        L1 = L1->next;
    while (L2->data != k)
        L2 = L2->next;
    L1->next = L2;
}

void intersections(lptr L[])
{
    struct stack S[4];
    for (int x = 0; x < 4; x++)
    {
        S[x].size = 100;
        S[x].top = -1;
        lptr L1 = L[x];
        while (L1 != NULL)
        {
            push(S[x], L1->data);
            L1 = L1->next;
        }
    }

    bool is_same[] = {true, true, true, true};
    bool all_diff = false;
    while (!all_diff)
    {
        all_diff = true;
        int popped1 = pop(S[0]);
        for (int y = 1; y < 4; y++)
        {
            if (is_same[y])
            {
                all_diff = false;
                int popped2 = pop(S[y]);
                if (peek(S[y]) != peek(S[0]))
                {
                    is_same[y] = false;
                    cout << y + 1 << " ";
                    for (int z = 0; z < 4; z++)
                        if (is_same[z])
                            cout << z + 1 << " ";
                    cout << popped2 << endl;
                }
            }
        }
    }
}

int main()
{
    lptr L[4] = {NULL};
    for (int i = 0; i < 4; i++)
        input(L[i]);
    point(L[1], L[0], 36);
    point(L[2], L[0], 5);
    point(L[3], L[0], 27);
    intersections(L);

    return 0;
}