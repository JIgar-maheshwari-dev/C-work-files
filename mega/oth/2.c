#include <stdio.h>
 
int main()
{
    int a = 10;
    void* ptr = &a;
    // The void pointer 'ptr' is cast to an integer pointer
    // using '(int*)ptr' Then, the value is dereferenced
    // with `*(int*)ptr` to get the value at that memory
    // location
    printf("%d", *(int*)ptr);
    return 0;
}

