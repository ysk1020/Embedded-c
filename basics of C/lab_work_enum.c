/* 
Ask user to print 4 chars (as example TALK, MASK) and put them into the char array. 
Write the function, that takes pointer of char array and detects is in this array exists 
word “ASK”. If yes return enum with value “Success”. Write another function, that 
detects if it is Success and prints it out.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum STATUS {
    FAILURE,
    SUCCESS
};
enum STATUS detectWord(char *arr) {
    while (*arr != '\0') {
        if ((*arr == 'A' || *arr == 'a') && (*(arr + 1) == 'S' || *(arr + 1) == 's') && (*(arr + 2) == 'K' || *(arr + 2) == 'k')) {
            return SUCCESS;
        }
        arr++;
    }
    return FAILURE;
}
void printResult(enum STATUS status) {
    if (status == SUCCESS) {
        printf("Success: Word \"ASK\" exists in the array.\n");
    } else {
        printf("Failure: Word \"ASK\" does not exist in the array.\n");
    }
}

int main() {
    char arr[5];
    printf("Enter 4 characters (e.g., TALK, MASK): ");
    scanf("%s", arr);

    for (int i = 0; i < 4; i++) {
        arr[i] = tolower(arr[i]);
    }
    enum STATUS result = detectWord(arr);
    printResult(result);
    return 0;
}
