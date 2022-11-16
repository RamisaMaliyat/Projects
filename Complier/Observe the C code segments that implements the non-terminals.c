#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[50];
int l,f;
int main()
{
    printf("Enter any string:");
    gets(str);
    if(A())
        printf("String can be Parsed.\n");
    else
        printf("Rejected!\n");
    return 0;
}
int A(){
    int i = 0;
    int l = strlen(str);
    if(str[i]=='a')
    {
        f=1;
        if(X())
        {
            if(str[l-1]=='d')
                return 1;
            else
                return 0;
        }
        return 0;
    }
    return 0;
}
int X()
{
    int i = 0;
    int l = strlen(str);
    if(f==l-1)
        return 1;
    else if(f < l-1 && str[f] == 'b' && str[f+1] == 'b')
    {
        f+=2;
        return X();
    }
    else if(f < l-1 && str[f] == 'b' && str[f+1] == 'c')
    {
        f+=2;
        return X();
    }
    else
        return 0;
}

