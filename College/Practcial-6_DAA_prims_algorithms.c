//Gaurav Patil (A-33)  DAA Practical-6
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define INF 9999999
#define V 5//Gaurav Patil (A-33)  DAA Practcical-6

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};//Gaurav Patil (A-33)  DAA practical-6

int main() {
  int no_edge;

  int selected[V];

  memset(selected, false, sizeof(selected));//Gaurav Patil (A-33)  DAA practical-6

  no_edge = 0;

  selected[0] = true;//Gaurav Patil (A-33)  DAA practical-6

  int x;
  int y;

  printf("Edge : Weight\n");//Gaurav Patil (A-33)  DAA practical-6

  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {//Gaurav Patil (A-33)  DAA practical-6
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;//Gaurav Patil (A-33)  DAA practical-6
              y = j;
            }
          }
        }
      }//Gaurav Patil (A-33)  DAA practical-6
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}//Gaurav Patil (A-33)  DAA practical-6
