#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    char input[100];
    printf("Enter an arithmetic expression: ");
    gets(input);
    if(Exp(input))
        printf("\nAccepted.\n");
    else
        printf("\nRejected.\n");

    return 0;
}

int Exp(char *str){
    int l = strlen(str);
    int i = 0, j = 0, f = 0;
    int symbol = 0;
    while(i<l){
        if(str[i] == '+' || str[i] == '-'){
            symbol=i;
            f++;
        }
        i++;
    }

    if(f > 1){
        return 0;
    }

    else if(f == 1){
        char leftstr[50], rightstr[50];
        for (i = 0; i < symbol; i++){
            leftstr[i] = str[i];
        }
        leftstr[i] ='\0';

        for (i = symbol+1, j = 0; i<l; i++, j++){
            rightstr[j] = str[i];
        }
        rightstr[j] ='\0';

        if(Term(leftstr)){
            if(Term(rightstr)){
                return 1;
            }
        }
    }

    else if(f == 0){
        if(Term(str)){
                return 1;
        }
    }
    return 0;
}
int Term(char *str){
    int l = strlen(str);
    int f = 0, i = 0, j=0;
    int symbol = 0;
    while(i<l){
        if(str[i] == '*' || str[i] == '/'){
            symbol=i;
            f++;
        }
        i++;
    }
    if(f > 1){
        return 0;
    }
    else if(f == 1){
        char leftstr[50], rightstr[50];
        for (i = 0; i < symbol; i++){
            leftstr[i] = str[i];
        }
        leftstr[i] ='\0';

        for (i = symbol+1, j = 0; i<l; i++, j++){
            rightstr[j] = str[i];
        }
        rightstr[j] ='\0';
        if(Factor(leftstr)){
            if(Factor(rightstr)){
                return 1;
            }
        }
    }

    else if(f == 0){
        if(Factor(str)){
                return 1;
        }
    }
    return 0;

}
int Factor(char *str){
    int l = strlen(str);
    int f = 0, i = 0, j=0;
    int symbol = 0;
    if(strlen(str) == 1){
        if(isId(str))
            return 1;
        else if(isNum(str))
            return 1;
    }
    else if(strlen(str) > 1){
        Exp(str);
    }
}

int isNum(char *str){
    if(str[0]>='0' && str[0]<='9')
        return 1;
    return 0;
}
int isId(char *str){
    if(str[0]>='a' && str[0]<='e')
        return 1;
    return 0;
}
