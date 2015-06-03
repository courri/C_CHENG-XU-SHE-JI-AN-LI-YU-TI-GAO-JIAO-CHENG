#include <stdio.h>
int main()
{
 fprintf( stdout, "%s\n", "这些信息是可以被重定向的");
 fprintf( stderr, "%s\n", "这些信息是不能被重定向的");
 return 0;
}