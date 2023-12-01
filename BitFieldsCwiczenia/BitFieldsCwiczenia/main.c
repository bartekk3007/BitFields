#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct information 
{
	int x : 2;
	int y : 4;
};

struct date {
    // d has value between 0 and 31, so 5 bits
    // are sufficient
    int d : 5;

    // m has value between 0 and 15, so 4 bits
    // are sufficient
    int m : 4;

    int y;
};

struct test {
    // Unsigned integer member x
    unsigned int x;
    // Bit-field member y with 33 bits
    long long int y : 33;
    // Unsigned integer member z
    unsigned int z;
};

int main(void)
{
	printf("Size is %llu\n", sizeof(struct information));

	struct information inf1 = {4, 13};

	printf("%d %d\n", inf1.x, inf1.y);

    printf("Size of date is %llu bytes\n", sizeof(struct date));
    struct date dt = { 31, 12, 2014 };
    printf("Date is %d/%d/%d\n", dt.d, dt.m, dt.y);

    struct test t;
    unsigned int* ptr1 = &t.x;
    unsigned int* ptr2 = &t.z;
    ptrdiff_t diff = ptr2 - ptr1;
    printf("%llu", diff);

	return 0;
}