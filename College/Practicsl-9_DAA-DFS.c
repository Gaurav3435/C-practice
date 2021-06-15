#include <stdio.h>//Gaurav Patil (A-33)  DAA   Practical-9
#include <stdlib.h>
struct node {
  int vertex;
  struct node* next;//Gaurav Patil (A-33)  DAA   Practical-9
};

struct node* createNode(int v);//Gaurav Patil (A-33)  DAA   Practical-9
struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;//Gaurav Patil (A-33)  DAA   Practical-9
};

void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];//Gaurav Patil (A-33)  DAA   Practical-9
  struct node* temp = adjList;
  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);//Gaurav Patil (A-33)  DAA   Practical-9
  while (temp != NULL) {
    int connectedVertex = temp->vertex;
    if (graph->visited[connectedVertex] == 0) {//Gaurav Patil (A-33)  DAA   Practical-9
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }//Gaurav Patil (A-33)  DAA   Practical-9
}

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;//Gaurav Patil (A-33)  DAA   Practical-9
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {//Gaurav Patil (A-33)  DAA   Practical-9
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));//Gaurav Patil (A-33)  DAA   Practical-9
  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;//Gaurav Patil (A-33)  DAA   Practical-9
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;//Gaurav Patil (A-33)  DAA   Practical-9
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {//Gaurav Patil (A-33)  DAA   Practical-9
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);//Gaurav Patil (A-33)  DAA   Practical-9
      temp = temp->next;
    }
    printf("\n");
  }
}
//Gaurav Patil (A-33)  DAA   Practical-9
int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);//Gaurav Patil (A-33)  DAA   Practical-9
  addEdge(graph, 2, 3);
  printGraph(graph);
  DFS(graph, 2);
  return 0;
}
//Gaurav Patil (A-33)  DAA   Practical-9
