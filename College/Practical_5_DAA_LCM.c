#include <stdio.h>
#include <string.h>
int i, j, m, n, LCS_table[20][20];//Gaurav Patil (A-33)  DAA Practcial-5
char S1[20] = "0011101", S2[20] = "0110101", b[20][20];

void lcsAlgo() {
  m = strlen(S1);
  n = strlen(S2);
  for (i = 0; i <= m; i++)//Gaurav Patil (A-33)  DAA Practcial-5
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      if (S1[i - 1] == S2[j - 1]) {//Gaurav Patil (A-33)  DAA Practcial-5
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
      } else {
        LCS_table[i][j] = LCS_table[i][j - 1];//Gaurav Patil (A-33)  DAA Practcial-5
      }
    }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';//Gaurav Patil (A-33)  DAA Practcial-5

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];//Gaurav Patil (A-33)  DAA Practcial-5
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;//Gaurav Patil (A-33)  DAA Practcial-5
    else
      j--;
  }

  printf("S1 : %s \nS2 : %s \n", S1, S2);
  printf("LCS: %s", lcsAlgo);
}
//Gaurav Patil (A-33)  DAA Practcial-5
int main() {
  lcsAlgo();
  printf("\n");
}
//Gaurav Patil (A-33)  DAA Practcial-5
