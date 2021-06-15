#include <stdio.h>
//Gaurav Patil (A-54)
int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;       //cost 2 number of time 1
    printf("Enter the number of terms: ");
    scanf("%d", &n);                          //cost 1 number of time 1
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {                //cost 3  number of time n+1
        printf("%d, ", t1);                   //cost 1 number of time n
        nextTerm = t1 + t2;                   //cost 2 number of time n
        t1 = t2;                              //cost 1 number of time n
        t2 = nextTerm;                        //cost 1 number of time n
    }

    return 0;                                 //cost 1 number of time 1
}
