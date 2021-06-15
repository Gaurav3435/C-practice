#include <stdio.h>
#include <stdlib.h>//Gaurav Patil (A-33) DAA Practical-9
#define SIZE 40

struct queue {
  int items[SIZE];//Gaurav Patil (A-33) DAA Practical-9
  int front;
  int rear;
};

struct queue* createQueue();//Gaurav Patil (A-33) DAA Practical-9
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);//Gaurav Patil (A-33) DAA Practical-9
void printQueue(struct queue* q);

struct node {
  int vertex;
  struct node* next;//Gaurav Patil (A-33) DAA Practical-9
};

struct node* createNode(int);

struct Graph {
  int numVertices;//Gaurav Patil (A-33) DAA Practical-9
  struct node** adjLists;
  int* visited;
};
//Gaurav Patil (A-33) DAA Practical-9
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);//Gaurav Patil (A-33) DAA Practical-9

  while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];//Gaurav Patil (A-33) DAA Practical-9

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);//Gaurav Patil (A-33) DAA Practical-9
      }
      temp = temp->next;
    }
  }
}

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));//Gaurav Patil (A-33) DAA Practical-9
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {//Gaurav Patil (A-33) DAA Practical-9
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;//Gaurav Patil (A-33) DAA Practical-9
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  newNode = createNode(src);//Gaurav Patil (A-33) DAA Practical-9
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}
int isEmpty(struct queue* q) {//Gaurav Patil (A-33) DAA Practical-9
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");//Gaurav Patil (A-33) DAA Practical-9
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;//Gaurav Patil (A-33) DAA Practical-9
  }
}

int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");//Gaurav Patil (A-33) DAA Practical-9
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");//Gaurav Patil (A-33) DAA Practical-9
      q->front = q->rear = -1;
    }
  }
  return item;
}

void printQueue(struct queue* q) {//Gaurav Patil (A-33) DAA Practical-9
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {//Gaurav Patil (A-33) DAA Practical-9
      printf("%d ", q->items[i]);
    }
  }
}

int main() {
  struct Graph* graph = createGraph(6);//Gaurav Patil (A-33) DAA Practical-9
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);//Gaurav Patil (A-33) DAA Practical-9
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  bfs(graph, 0);

  return 0;//Gaurav Patil (A-33) DAA Practical-9
}
