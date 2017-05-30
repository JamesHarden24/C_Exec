
#include <stdio.h>

void my_print(int res)
{
    printf("Result = %d \n", res);
}

int main(int argc,const char *argv[])
{
    int i;
    long result;

    for (i = 1; i <= 100; i++)
    {
        result += 1;
    }

    my_print(result);

    return 0;
}

