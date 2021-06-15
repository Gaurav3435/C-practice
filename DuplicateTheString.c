#include<stdio.h>
void copy_string(char [], char []);

int main() {
  char s[1000], d[1000];

  printf("Input a string\n");
  gets(s);

  copy_string(d, s);
  printf("The string: %s\n", d);

  return 0;
}

void copy_string(char d[], char s[]) {
  int c = 0;

  while (s[c] != '\0') {
    d[c] = s[c];
    c++;
  }
  d[c] = '\0';
}
