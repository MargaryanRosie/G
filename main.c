#include "get_next_line_bonus.h"
#include <stdio.h>

// foo(int  i){
//     static int *fds;
//     static char** parts;
// }

int main()
{
    char *str;
    char *str1;
    char *str2;

    int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("test1.txt", O_RDONLY);
    int fd3 = open("test2.txt", O_RDONLY);
    

    str = get_next_line(fd1);
    str1 = get_next_line(fd1);
    // str1 = get_next_line(fd2);
    // str2 = get_next_line(fd3);

    printf("%s", str);
    printf("%s", str1);
    // printf("%s", str2);
    return 0;
}