#include <stdio.h>
#include <stdlib.h>

#define N 9  // Number of vertices in the graph

// Queue related operations
int queue[N], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == N - 1) {
        printf("\nQueue is full");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = data;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty");
        return -1;
    } else {
        int d = queue[front];
        front++;
        return d;
    }
}

int isEmpty() {
    if(front==-1 || front>rear) {
        return 1;
    }
    return 0;
}

// BFS algorithm
void BFS(int G[N][N], int start) {
    int i = start;
    int visited[N] = {0};
 
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty()) {
        i = dequeue();
 
        for (int j = 0; j < N; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                enqueue(j);
                visited[j] = 1;
                printf("%d ", j);
            }
        }
    }
}

// Driver code
int main() {
    int G[N][N] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    printf("Vertices in BFS order: ");
    BFS(G, 0);

    return 0;
}

