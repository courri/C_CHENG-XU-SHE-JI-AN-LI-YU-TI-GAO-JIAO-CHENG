int main()
{int a = 1, b = 2;
 extern void f1(int,int), f2(int, int);
 f1(a,b);
 f2(a,b);
 getch();
 return 0;
}