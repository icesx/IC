#include <stdio.h>
main()
{
    int a[4] = {1, 2, 3, 4};
    printf("数组首位置指针%d", a);
    printf("数组第二个位置指针%d", a + 1);
    printf("数组指针%d", &a);
    printf("下一个数组指针%d", &a + 1);
    printf("相当于打印了a%d", *(&a));
    printf("打印了数字第二个位置%d", *(&a) + 1);
}