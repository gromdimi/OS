// main.c
#include <stdio.h>
#include "functions.h"

int main() {
    greet();  // Call the greet function from functions.c

    int result = add(12, 2);  // Call the add function from functions.c
    printf("The result of adding 12 and 2 is: %d\n", result);
	printf("Hello word\n");
   
 return 0;
}
