#include <stdio.h>
#include <string.h>
int main()
{
    int i, n, at_no;
    char element[20], el[20], symbol[3], type[30];
    float at_mass;
    FILE *f1;
    printf("Enter the element name: ");
    scanf("%s", element);
    f1 = fopen("period_table", "r");

    for (i = 0; i <= 1500; i++)
    {
        fscanf(f1, "%s", el);
        if (strcmp(el, element) == 0)
        {
            n = n + 1;
            fscanf(f1, "%s %d %f %s", symbol, &at_no, &at_mass, type);
            break;
        }
    }
    if (n == 1)
    {
        printf("Symbol: %s\nAtomic number: %d\nAtomic mass: %.3f\nType: %s\n", symbol, at_no, at_mass, type);
    }
    else
    {
        printf("Element with this name doesnot exist\n");
    }
}
