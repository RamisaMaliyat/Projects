#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<conio.h>
#include <ctype.h>

#define N 1000000
// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
            ch == '\'')
        return (true);
    return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' ||
            ch == '=')
        return (true);
    return (false);
}

// Returns 'true' if the character is an Separtor.
bool Separator(char ch)
{
    if (ch == ',' || ch == ';'|| ch == '"')
        return true;
    return false;
}

// Returns 'true' if the character is an Paranthesis.
bool isParathesis(char ch)
{
    if (ch == '(' || ch == ')'||ch == '{' || ch == '}'||ch == '[' || ch == ']')
        return true;
    return false;
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
            str[0] == '3' || str[0] == '4' || str[0] == '5' ||
            str[0] == '6' || str[0] == '7' || str[0] == '8' ||
            str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}

// Returns flag if the string is a KEYWORD.
int Keyword(char buffer[])
{
    char keywords[32][10] =
    {
        "auto","break","case","char","const","continue",
        "default","do","double","else","enum","extern",
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "switch","typedef","union","unsigned","void","volatile","while"
    };
    int i, flag = 0;
    for(i = 0; i < 32; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' && str[i] != '.' ||
                (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Extracts the SUBSTRING.
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// categorized the Lexemes the input STRING.
void lexemes(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (isDelimiter(str[right]) == false)
        {
            if(isOperator(str[right]) == true)
                printf("[op %c]", str[right]);
            right++;
        }

        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
                printf("[op %c]", str[right]);
            if (Separator(str[right]) == true)
                printf("[sp %c]", str[right]);
            if (isParathesis(str[right]) == true)
                printf("[par %c]", str[right]);

            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right
                 || (right == len && left != right))
        {
            char* subStr = subString(str, left, right - 1);

            if (Keyword(subStr) == 1)
                printf("[kw %s]", subStr);

            else if (isRealNumber(subStr) == true)
                printf("[num %s]", subStr);
            else if( isInteger(subStr) == true )
                printf("[num %s]", subStr);

            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                printf("[id %s]", subStr);

            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("[unkn %s]",subStr);

            left = right;
        }
    }
    return;
}







typedef struct Stack Stack;

struct Stack
{
    char data[1001];
    Stack* next;
};

Stack* newNode(char data[1000])
{
    Stack* stackNode =(Stack*)malloc(sizeof(Stack));
    strcpy(stackNode->data,data);
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(Stack* root)
{
    return !root;
}

void push(Stack** root, char data[1000])
{
    Stack* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

Stack* pop(Stack** root)
{
    if (isEmpty(*root))
        return NULL;
    Stack* temp = *root;
    *root = (*root)->next;
    return temp;
}

Stack* peek(Stack* root)
{
    if (isEmpty(root))
        return NULL;
    return root;
}

void getData(Stack** root)
{
    if (isEmpty(*root))
        return ;

    Stack* temp = *root;

    printf("%s\n",temp->data);
}

typedef struct SymbolTable SymbolTable;

struct SymbolTable
{
    int id;
    char name[101] ;
    char id_type[101] ;
    char data_type[101];
    char scope[101] ;
    char value[101] ;
    SymbolTable *next;
    SymbolTable *prev;
    SymbolTable *start;
};

SymbolTable* newNodeSymbolTable(char name[100],char id_type[100],char data_type[100],
                                char scope[100], char value[100])
{
    SymbolTable* symbolTable =(SymbolTable*)malloc(sizeof(SymbolTable));
    strcpy(symbolTable->name,name);
    strcpy(symbolTable->id_type,id_type);
    strcpy(symbolTable->data_type,data_type);
    strcpy(symbolTable->scope,scope);
    strcpy(symbolTable->value,value);
    symbolTable->next = NULL;
    symbolTable->prev = NULL;
    return symbolTable;
}


int isEmptySymbolTable(SymbolTable* root)
{
    return !root;
}

void addSymbolTable(SymbolTable** root,char name[100], char id_type[100],
                    char data_type[100], char scope[100], char value[100])
{
    SymbolTable* symbolTableNode = newNodeSymbolTable(name,id_type,data_type,scope,value);
    symbolTableNode->prev = *root;
    symbolTableNode->next = NULL;
    if(!isEmptySymbolTable(*root))
        {
            SymbolTable* tmp = *root;
            tmp->next = symbolTableNode;
            symbolTableNode->id = tmp->id + 1;
            symbolTableNode->start = tmp->start;
        }
    else
    {
        symbolTableNode->id = 1;
        symbolTableNode->start = symbolTableNode;
    }
    *root = symbolTableNode;
}

SymbolTable* popSymbolTable(SymbolTable** root)
{
    if (isEmptySymbolTable(*root))
        return NULL;
    SymbolTable* temp = *root;
    *root = (*root)->next;
    return temp;
}

int findAndAddBy(SymbolTable ** root,char name[100],char id_type[100],
                 char data_type[100], char scope[100], char value[100])
{
    int tableId = 0;
    SymbolTable* temp = *root;
    int isFind = 0;
    while(!isEmptySymbolTable(temp))
        {
            if(strcmp(temp->name , name) == 0 &&strcmp(temp->id_type , id_type) == 0 &&
             strcmp(temp->scope , scope) == 0)
             {
                isFind = 1;
                break;
             }
            temp = temp->prev;
        }
    if(isFind)
        {
          strcpy(temp->value , value);
          tableId = temp->id;
        }
    else
        {
          addSymbolTable(root, name, id_type, data_type,scope, value);
          tableId = (*root)->id;
        }

    return tableId;

}


void getAllValue(SymbolTable ** root)
{

    if(isEmptySymbolTable(*root))
        {
          return;
        }
    else
        {
           SymbolTable* temp = (*root)->start;

           while(!isEmptySymbolTable(temp))
            {
                printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n" , temp->id, temp->name, temp->id_type, temp->data_type, temp->scope, temp->value);
                temp = temp->next;
            }
    }
}

SymbolTable* peekSymbolTable(SymbolTable* root)
{
    if (isEmptySymbolTable(root))
        return NULL;
    return root;
}

char input[1000000] ;
char allVal[1000000][100] ;
int token = 0;

char current_scope[15] = "Global";
Stack *scopeStack = NULL;
SymbolTable *symbolTable = NULL;


void fileRead(char *fileName)
{
    FILE *fptr;
    char c;
    int i = 0;
    if ((fptr = fopen(fileName, "r")) == NULL)
        {
            printf("Error! opening file");
        }
    else
        {
            while((c = fgetc(fptr)) != EOF)
            {
                input[i] = c;
                i++;
            }
        }
	fclose(fptr);
}

void printOutput(char str[])
{
    printf("%s\n",str);
}

void convertString()
{
    char output[1000000];
    int j = 0;
    for(int i = 0; i < strlen(input); i++)
        {
            if(input[i]=='[' && input[i+1]=='k' && input[i+2]=='w')
            {
                output[j++] = '[';
                i+=4;
            }
            else if(input[i]=='[' && input[i+1]=='o' && input[i+2]=='p')
                {
                    output[j++] = '[';
                    i+=4;
                }
            else if(input[i]=='[' && input[i+1]=='n' && input[i+2]=='u' && input[i+3]=='m')
                {
                    output[j++] = '[';
                    i+=5;
                }
            else if(input[i]=='[' && input[i+1]=='s' && input[i+2]=='e' && input[i+3]=='p')
                {
                    output[j++] = '[';
                    i+=5;
                }
            else if(input[i]=='[' && input[i+1]=='b' && input[i+2]=='r' && input[i+3]=='c')
                {
                    output[j++] = '[';
                    i+=5;
                }
            else if(input[i]=='[' && input[i+1]=='p' && input[i+2]=='a' && input[i+3]=='r')
                {
                    output[j++] = '[';
                    i+=5;
                }
            output[j++] = input[i];
      }

     output[j] = '\0';
     strcpy(input , output);
}


void createToken()
{
    int j = 0;
    char buffer[500];
    for(int i = 0; i < strlen(input);i++)
        {
            if(input[i] == '[')
            {
                i++;
                while(input[i] != ']')
                {
                    buffer[j++] = input[i];
                    i++;
                }
                buffer[j] = '\0';
                strcpy(allVal[token],buffer);
                j = 0;
                ++token;
              }
        }
}


int findIdentifier(char str[])
{
    if(str[0] == 'i' && str[1] == 'd')
        return 1;
    return 0;
}


int isDatatype(char str[])
{
    int word = 7;
    char datatype[7][10]=
    {
        "auto","double","int","long","char","float","void",
    } ;
    int flag=0;
    for(int i = 0; i < word; i++)
        {
            if(strcmp(str,datatype[i])==0)
             {
                 flag=1;
                 break;
             }
        }
    if(flag==1)
      return 1;
   else
      return 0;
}


void insertSyntaxAnalysisValue(int IdentifierPosition, int whichValue)
{
    if(whichValue >= 1)
        {
            char intToDigit[] = {'0' + whichValue, '\0'};
            char outputSyntaxAnalysis[] = "id ";
            strcat(outputSyntaxAnalysis,intToDigit);
            strcpy(allVal[IdentifierPosition] , outputSyntaxAnalysis);
        }
}

int insertIntoSymbolTable(char name[100], char id_type[100],char data_type[100],
                          char value[100])
{
    int IdentifierId;
    Stack *s = peek(scopeStack);
    IdentifierId = findAndAddBy(&symbolTable , name,id_type,data_type,s->data,value);
    return IdentifierId;
}

int isNumber(char str[])
{
    int flag = 1;
    int numberOfpoint = 0;
    char str1[strlen(str) + 1];
    strcpy(str1,str);

    for (int i = 0; i < strlen(str1); i++)
        {
            if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str1[i] = str1[i] + 32;
            }
        }
    if(str1[0] == '0' && str1[1] == 'x')
        {
            for(int i = 2; i < strlen(str1); i++)
            {
                if((str1[i] >= '0' && str1[i] <= '9') ||
                   (str1[i] >= 'a' && str1[i] <= 'z') )
                    {
                        continue;
                    }
                else
                    {
                        return 0;
                    }
           }
          return 1;
       }
    for(int i = 0; i < strlen(str1); i++)
        {
            if(isdigit(str1[i]))
            {
                flag = 1;
                continue;
		    }
		    else if(str1[i] == '.')
		    {
               numberOfpoint++;
		    }
            else
                {
                    flag = 0;
                    break;

                }
	   }
	if(numberOfpoint <=1 && flag == 1)
        return 1;
    else
        return 0;
}

void removeID(char str[],char newStr[])
{

    if(str[0] == 'i' && str[1] == 'd')
        {
            int j = 0;
            for(int i = 3; i <strlen(str) ;i++)
            {
                newStr[j] = str[i];
                j++;
            }
          newStr[j] = '\0';
        }

}

typedef struct table table;

struct table
{
    int id;
    char name[100], iT[100], dT[100], sc[100], val[100];
} tabVal[100];

char check[100], cur[100], dType[100][50], scope[100][50];
int cnt, iType, topD, topS, elseCnt, lineNum;

void step1();
void step2();
void step3();
void step4();

char* subString1(char* str, int left, int right);
bool isKeyword(char* str);
bool isIdentifier(char* str, int len);
bool isSeparator(char ch);
bool isSingOprtr(char ch);
bool isMultOprtr(char* str);
bool isBinary(char* str, int len);
bool isDecimal(char* str, int len);
bool isOctal(char* str, int len);
bool isHexadecimal(char* str, int len);


void stepOne();
void stepTwo();

void tabInsert();
void tabSearch();
void scopeVal();

int main(void)
{
    FILE *f1,*f2,*f3,*f4;
    f1 = fopen("inputCode.c", "w");
    f2=fopen("removecomment.txt","w");
    f3 = fopen("syntaxanalysis.txt", "w");
    f4 = fopen("lexemeanalysis.txt", "w");
    int backslash=0,star=0,space=0;
    char c;
    char data;
    if(f1 == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }
    printf("Press $ Key to stop user input : \n");
    printf("Enter contents to store in file : \n");
    while( (data = getchar()) != '$' )
    {
        putc(data, f1);
    }

    fclose(f1);
    printf("File created and saved successfully.\n");
    f1 = fopen("inputCode.c", "r");

    if(f1==NULL)
    {
        printf("Error while opening a file for reading");

    }
    else
    {
        printf("Successfully open a file for reading\n");
    }
    fclose(f1);

    printf("\nAfter removing newline and comments\n\n");
    f1=fopen("inputCode.c","r");
    if(!f1)
        printf("\nFile can't be opened!");
    else
    {
        while((c=fgetc(f1))!=EOF)
        {
            if(c== '/')
            {
                backslash++;
            }
            if(c=='*')
            {
                star++;
            }
            if(c==' ')
            {
                space++;
            }
            if(backslash==2 && star==2  && c=='\n')
            {
                backslash=0;
                star=0;
            }
            else if(backslash==2 && star==0 && c=='\n')
            {
                backslash=0;
            }

            else if(backslash==0 && star==0  && c!='\n')
                fputc(c,f2);
        }

    }
    fclose(f1);
    fclose(f2);

    f2=fopen("removecomment.txt","r");
    while((c=fgetc(f2)) != EOF)
        printf("%c",c);
    if(!f2)
        printf("\nFile haven't anything to print.");
    fclose(f2);

    printf("\n\n");
    char s[10000],x;
    int i=0;

    f2=fopen("removecomment.txt","r");
    while ((x = fgetc(f2)) != EOF)
    {
        s[i++] = x;
    }
    fclose(f2);
    printf("After categorize lexemes\n\n");
    lexemes(s);

    f4 = fopen("lexemeanalysis.txt", "w");

    int fd=fileno(f4), copy=dup(1);
	dup2(fd,1);
	lexemes(s);
	fflush(stdout);
    fclose(f4);
	dup2(copy,1); /* return stdout to normal */
	lexemes(s);



	push(&scopeStack, "Global");
    getAllValue(&symbolTable);
    fileRead("lexemeanalysis.txt");
    printf("\n");
    printf("\nAll the lexemes only identifiers are kept in pairs:\n");
    convertString();
    printf("\n");
    printOutput(input);
    createToken();
    printf("\n");

    for(int i = 0 ; i < token ; i++)
        {
            int IdentifierId = 0;
            if(allVal[i][0] == '{')
            {
                printf("have  { \n");
            }
            else if(allVal[i][0] == '}')
                {
                    printf("function  =  %s\n",pop(&scopeStack));
                    printf("have  }\n");
                }
            else if(findIdentifier(allVal[i]) )
            {
                char idVal[strlen(allVal[i])] ;
                removeID(allVal[i],idVal);
                if(isDatatype(allVal[i-1]))
                    {
                        if(strcmp(allVal[i+1] , "=") == 0)
                        {
                            IdentifierId = insertIntoSymbolTable(idVal,"var",allVal[i-1],allVal[i+2]);
                             printf("variable assign : %s %s %s %s\n",allVal[i-1],allVal[i],
                                    allVal[i+1],allVal[i+2] );
                        }
                        else if(strcmp(allVal[i+1] , "(") == 0)
                            {
                                if(strcmp(allVal[i+2] , ")") == 0)
                                {
                                    printf("function empty par = %s %s %s\n",allVal[i-1],idVal,allVal[i+1] );
                                }
                                else
                                {
                                    printf("function with par = %s %s %s\n",allVal[i-1],allVal[i],allVal[i+1] );
                                }
                                 IdentifierId = insertIntoSymbolTable(idVal,"func",allVal[i-1],"");
                                 push(&scopeStack, idVal);
                            }
                        else
                        {
                            printf("variable init = %s %s %s\n",allVal[i-1],allVal[i],allVal[i+1] );
                            IdentifierId = insertIntoSymbolTable(idVal,"var",allVal[i-1],"");
                        }

                   }
                else if(strcmp(allVal[i+1] , "=") == 0)
                {
                    if(isNumber(allVal[i+2]))
                    {
                        printf("variable assign : %s %s %s %s\n",allVal[i-1],allVal[i],allVal[i+1],allVal[i+2] );
                        IdentifierId = insertIntoSymbolTable(idVal,"var","",allVal[i+2]);
                    }
                }
           }
         insertSyntaxAnalysisValue(i,IdentifierId);
    }
    printf("\n\n---Symbol Table---\n\n");
    printf("Sl.no\t\tName\t\tId Type\t\tData Type\tScope\t\tValue\n\n");
    getAllValue(&symbolTable);

    printf("\n\n---Syntax Analysis---\n\n");

    for(int i = 0 ; i < token ; i++)
        {
            printf("[%s] ",allVal[i]);
            fprintf(f3,"[%s] ",allVal[i]);
        }
    printf("\n\n---Syntax error---\n\n");
    step1();
    step2();
    step3();
    step4();
    return (0);
}


void step1()
{
    FILE *codeFile, *extractFile, *filterFile;
    char str[200];
    int i, j, l, cnt = 0, stat = 0;

    codeFile = fopen("inputCode.c", "r");
    extractFile = fopen("step1.txt", "w");

    if(!codeFile)
        printf("No File Available.\n");

    else
    {
        while(fgets(str, N, codeFile))
        {
            //fprintf(extractFile, "%d ", ++cnt);
            l = strlen(str);
            i = 0;

            while(i < l)
            {
                if(str[i] != ' ')
                    break;
                ++i;
            }

            for(; i < l; ++i)
            {
                if(stat == 0 && str[i] == '/')
                {
                    if(i < l-1 && str[i + 1] == '/')
                    {
                        for(j = i + 1; j < l; ++j);
                        break;
                    }
                    else if(i < l-1 && str[i + 1] == '*')
                    {
                        stat = 1;
                        ++i;
                        continue;
                    }
                }

                if(stat == 1)
                {
                    if(str[i] == '*' && str[i + 1] == '/')
                    {
                        stat = 0;
                        ++i;
                        continue;
                    }
                }
                else
                {
                    if(str[i] == ' ')
                    {
                        for(j = i + 1; j < l; ++j)
                        {
                            if(str[j] != ' ')
                                break;
                        }
                        if(str[j] == '/')
                        {
                            if(str[j + 1] == '/')
                            {
                                ++j;
                                while(j < l)
                                    ++j;
                                break;
                            }
                            else if(str[j + 1] == '*')
                            {
                                stat = 1;
                                ++i;
                                continue;
                            }
                        }

                        i = j;
                        fputc(' ', extractFile);
                        fputc(str[i], extractFile);
                        continue;
                    }
                    if(str[i] != '\n')
                        fputc(str[i], extractFile);
                }
            }
            fputc('\n', extractFile);
        }
    }

    fclose(codeFile);
    fclose(extractFile);
}

void step2()
{
    FILE *inFile, *outFile;
    int len, left, right;
    char str[N];
    int i, j, l, stat = 0;

    elseCnt = -1;

    inFile = fopen("step1.txt", "r");
    outFile = fopen("step2.txt", "w");

    if(!inFile)
        printf("No File Available.\n");

    else
    {
        lineNum = 0;
        while(fgets(str, N-1, inFile))
        {
            ++lineNum;
            len = strlen(str);

            if(strcmp(str, "\n") == 0)
            {
                fprintf(outFile, "\n");
                continue;
            }

            left = 0;
            right = 0;
            while (right <= len && left <= right)
            {
                if(!isSeparator(str[right]) && !isSingOprtr(str[right]))
                    right++;
                if((isSeparator(str[right]) || isSingOprtr(str[right])) && left == right)
                {
                    if (isSeparator(str[right]) == true)
                        fprintf(outFile, "[sep %c] ", str[right]);
                    else
                    {
                        if(isSingOprtr(str[right + 1]))
                        {
                            ++right;
                            char* subStr = subString(str, left, right);
                            if(isMultOprtr(subStr))
                                fprintf(outFile, "[op %s] ", subStr);
                            else
                                fprintf(outFile, "[unkn %s] ", subStr);
                        }
                        else
                            fprintf(outFile, "[op %c] ", str[right]);
                    }
                    ++right;
                    left = right;
                }
                else if(isSeparator(str[right]) || isSingOprtr(str[right]) || (right == len && left != right))
                {
                    char* subStr = subString(str, left, right - 1);
                    if (isKeyword(subStr))
                        fprintf(outFile, "[kw %s] ", subStr);

                    else if (isBinary(subStr, right - left) || isOctal(subStr, right - left) ||
                             isHexadecimal(subStr, right - left) || isDecimal(subStr, right - left))
                        fprintf(outFile, "[number %s] ", subStr);

                    else if (isIdentifier(subStr, right - left) == true && isSeparator(str[right - 1]) == false)
                        fprintf(outFile, "[id %s] ", subStr);

                    else
                        fprintf(outFile, "[unkn %s] ", subStr);
                    left = right;
                }
                if(str[right] == '\n')
                {
                    fprintf(outFile, "\n");
                    break;
                }
            }
        }
    }

    fclose(inFile);
    fclose(outFile);
}

void step3()
{
    topD = topS = -1;
    stepOne();
    stepTwo();

}

void step4()
{
    int brcktCnt[3], i, j, len;

    brcktCnt[0] = brcktCnt[1] = brcktCnt[2] = - 1;
    lineNum = 0;

    FILE *inFile, *dupFile;
    char ch[100], cur[100], prev[100], comm[100];

    inFile = fopen("inputCode.c", "r");
    dupFile = fopen("step2.txt", "r");

    if(!inFile)
        printf("File Not Found.\n");
    else
    {
        // Bracket Balance check
        while(fgets(ch, N, inFile))
        {
            ++lineNum;
            len = strlen(ch);

            for(i = 0; i < len; ++i)
            {
                if (ch[i] == '[')
                    ++brcktCnt[0];
                else if(ch[i] == '{')
                    ++brcktCnt[1];
                else if(ch[i] == '(')
                    ++brcktCnt[2];
                else if(ch[i] == ')')
                    --brcktCnt[2];
                else if(ch[i] == '}')
                    --brcktCnt[1];
                else if(ch[i] == ']')
                    --brcktCnt[0];

                if(brcktCnt[0] < -1)
                {
                    brcktCnt[0] = -1;
                    printf("Unbalanced ']' at line %d\n", lineNum);
                }
                if(brcktCnt[1] < -1)
                {
                    brcktCnt[1] = -1;
                    printf("Unbalanced '}' at line %d\n", lineNum);
                }
                if(brcktCnt[2] < -1)
                {
                    brcktCnt[2] = -1;
                    printf("Unbalanced ')' at line %d\n", lineNum);
                }
            }
        }

        if(brcktCnt[0] != -1)
            printf("Unbalanced ']' at line %d\n", lineNum);
        if(brcktCnt[1] != -1)
            printf("Unbalanced '}' at line %d\n", lineNum);
        if(brcktCnt[2] != -1)
            printf("Unbalanced ')' at line %d\n", lineNum);

        // Duplicate token detect
        lineNum = 0;
        strcpy(prev, "");
        while(fgets(ch, N, dupFile))
        {
            ++lineNum;
            if(!strcmp(ch, "\n"))
                continue;
            len = strlen(ch);

            for(i = 0; i < len;)
            {
                while(ch[i] != '[' && i < len)
                    ++i;
                if(i == len)
                    break;
                ++i;
                j = 0;
                while(ch[i] != ' ' && i < len)
                {
                    cur[j] = ch[i];
                    ++i;
                    ++j;
                }
                cur[j] = '\0';
                if(i == len)
                    break;
                ++i;
                j = 0;
                while(ch[i] != ']' && i < len)
                {
                    comm[j] = ch[i];
                    ++i;
                    ++j;
                }
                comm[j] = '\0';
                if(i == len)
                    break;

                if(!strcmp(comm, "for"))
                {
                    ++i;
                    char tmp[100];
                    while(ch[i] != ']')
                        ++i;
                    if(ch[i-1] != '(')
                        printf("Expected '(' at line %d\n", lineNum);
                    else
                    {
                        while(1)
                        {
                            while(ch[i] != '[' && i < len)
                                ++i;
                            if(i == len)
                                break;
                            ++i;
                            j = 0;
                            while(ch[i] != ' ' && i < len)
                            {
                                tmp[j] = ch[i];
                                ++i;
                                ++j;
                            }
                            tmp[j] = '\0';
                            if(strcmp(tmp, "sep"))
                            {
                                while(ch[i] != ']' && i < len)
                                    ++i;
                                continue;
                            }
                            ++i;
                            j = 0;
                            while(ch[i] != ']' && i < len)
                            {
                                tmp[j] = ch[i];
                                ++i;
                                ++j;
                            }
                            tmp[j] = '\0';
                            if(!strcmp(tmp, ";"))
                                break;
                            else
                                continue;
                        }
                        if(strcmp(tmp, ";"))
                            printf("Expected ';' at line %d.\n", lineNum);
                        else
                        {
                            while(1)
                            {
                                while(ch[i] != '[' && i < len)
                                    ++i;
                                if(i == len)
                                    break;
                                ++i;
                                j = 0;
                                while(ch[i] != ' ' && i < len)
                                {
                                    tmp[j] = ch[i];
                                    ++i;
                                    ++j;
                                }
                                tmp[j] = '\0';
                                if(strcmp(tmp, "sep"))
                                {
                                    while(ch[i] != ']' && i < len)
                                        ++i;
                                    continue;
                                }
                                ++i;
                                j = 0;
                                while(ch[i] != ']' && i < len)
                                {
                                    tmp[j] = ch[i];
                                    ++i;
                                    ++j;
                                }
                                tmp[j] = '\0';
                                if(!strcmp(tmp, ";"))
                                    break;
                                else
                                    continue;
                            }
                            if(strcmp(tmp, ";"))
                                printf("Expected ';' at line %d.\n", lineNum);
                            else
                            {
                                ++i;
                                while(ch[i] != ']')
                                    ++i;
                                if(ch[i-1] != ')')
                                    printf("Expected ')' at line %d\n", lineNum);
                            }
                        }
                    }
                }
                else if(!strcmp(cur, prev) && strcmp(comm, "(") && strcmp(comm, "{") && strcmp(comm, ")")
                        && strcmp(comm, "}"))
                    printf("Duplicate token at line %d\n", lineNum);
                strcpy(prev, cur);
            }
        }

    }
    fclose(inFile);
    fclose(dupFile);
}

char* subString1(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
//if else check
bool isKeyword(char* str)
{
    if (!strcmp(str, "if"))
        ++elseCnt;
    if (!strcmp(str, "else"))
        --elseCnt;
    if(elseCnt < -1)
    {
        printf("'else' without a previous 'if' at line %d\n", lineNum);
        elseCnt = -1;
    }
    if (!strcmp(str, "void") || !strcmp(str, "int") || !strcmp(str, "float") || !strcmp(str, "char") ||
            !strcmp(str, "for") || !strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") ||
            !strcmp(str, "return") || !strcmp(str, "main") || !strcmp(str, "double"))
        return true;
    return false;
}

bool isIdentifier(char* str, int len)
{
    int i;

    if(!isalpha(str[0]) &&  str[0] != '_')
        return false;
    for(i = 1; i < len; ++i)
        if(!isalnum(str[i]) && !(str[i] == '_'))
            return false;
    return true;
}

bool isSeparator(char ch)
{
    if (ch == ' ' || ch == ',' || ch == ';' || ch == '(' ||
            ch == ')' || ch == '[' || ch == ']' || ch == '{' ||  ch == '}')
        return true;
    return false;
}

bool isSingOprtr(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' ||
            ch == '=' || ch == '>' || ch == '!' || ch == '<')
        return true;
    return false;
}

bool isMultOprtr(char* str)
{
    if (!strcmp(str, "==") || !strcmp(str, "++") || !strcmp(str, "--") || !strcmp(str, "+=") ||
            !strcmp(str, "-=") || !strcmp(str, "*=") || !strcmp(str, "/=") || !strcmp(str, "%=") ||
            !strcmp(str, "<=") || !strcmp(str, ">=") || !strcmp(str, "!=") || !strcmp(str, "&&") ||
            !strcmp(str, "||"))
        return true;
    return false;
}

bool isBinary(char* str, int len)
{
    int i;

    if(len < 3 || str[0] != '0' || str[1] != 'b')
        return false;

    for(i = 2; i < len; ++i)
        if(str[i] < '0' || str[i] > '1')
            break;

    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(str[i] < '0' || str[i] > '1')
            return false;
        ++i;
    }

    return true;
}

bool isDecimal(char* str, int len)
{
    int i;

    for(i = 0; i < len; ++i)
        if(!isdigit(str[i]))
            break;
    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(!isdigit(str[i]))
            return false;
        ++i;
    }

    return true;
}

bool isOctal(char* str, int len)
{
    int i;

    if(len < 2 || str[0] != '0')
        return false;

    for(i = 1; i < len; ++i)
        if(str[i] < '0' || str[i] > '7')
            break;

    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(str[i] < '0' || str[i] > '7')
            return false;
        ++i;
    }

    return true;
}

bool isHexadecimal(char* str, int len)
{
    int i;

    if(len < 3 || str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
        return false;

    for(i = 2; i < len; ++i)
        if(!isdigit(str[i]) && (str[i] < 'A' || str[i] > 'F'))
            break;

    if(i == len)
        return true;

    if(str[i] != '.')
        return false;

    ++i;
    while(i < len)
    {
        if(!isdigit(str[i]) && !(str[i] >= 'A' && str[i] <= 'F'))
            return false;
        ++i;
    }

    return true;
}

void stepOne()
{
    FILE *inFile, *oneFile;
    int i, len, left = 0, right = 0;
    char str[N];

    inFile = fopen("step2.txt", "r");
    oneFile = fopen("stepOne.txt", "w");

    if(!inFile)
        printf("No File Available.\n");

    else
    {
        lineNum = 0;
        while(fgets(str, N-1, inFile))
        {
            ++lineNum;
            if(strcmp(str, "\n") == 0)
            {
                fprintf(oneFile, "\n");
                continue;
            }
            len = strlen(str);
            for(i = 0; i < len; ++i)
            {
                if(ferror(inFile) || feof(inFile))
                    break;
                if(str[i] == '[')
                {
                    fprintf(oneFile, "[");
                    ++i;
                    if(str[i] == 'i')
                    {
                        while(str[i] != ']')
                        {
                            fprintf(oneFile, "%c", str[i]);
                            ++i;
                        }
                        fprintf(oneFile, "]");
                    }
                    else
                    {
                        if(str[i] == 'u')
                        {
                            printf("Unknown Value Found at line %d.\n", lineNum);
                            while(str[i] != ']')
                                ++i;
                        }
                        else
                        {
                            while(str[i] != ' ')
                                ++i;
                            ++i;
                            while(str[i] != ']')
                            {
                                fprintf(oneFile, "%c", str[i]);
                                ++i;
                            }
                            fprintf(oneFile, "]");
                        }
                    }
                }
            }
            fprintf(oneFile, "\n");
        }
    }

    fclose(inFile);
    fclose(oneFile);
}

void stepTwo()
{
    FILE *oneFile, *outFile;
    int i, j, len;
    char str[N];

    oneFile = fopen("stepOne.txt", "r");
    outFile = fopen("output.txt", "w");

    if(!oneFile)
        printf("No File Available.\n");

    else
    {
        lineNum = 0;
        while(fgets(str, N-1, oneFile))
        {
            ++lineNum;
            if(strcmp(str, "\n") == 0)
            {
                continue;
            }
            len = strlen(str);
            for(i = 0; i < len; ++i)
            {

                if(str[i] == '[')
                {
                    fprintf(outFile, "[");
                    ++i;
                    if(str[i] == 'i' && str[i+1] == 'd')
                    {
                        fprintf(outFile, "id ");
                        i += 2;
                        j = 0;
                        while(str[i] != ']')
                        {
                            check[j] = str[i];
                            ++i;
                            ++j;
                        }
                        check[j] = '\0';

                        if(str[i+2] == '(')
                            iType = 1;
                        else
                            iType = 0;
                        tabSearch();
                        int x;
                        for(x = cnt; x >= 0; --x)
                            if(strcmp(tabVal[x].name, check) == 0)
                                break;
                        fprintf(outFile, "%d]", x+1);
                        if(str[i+2] == ';')
                            --topD;
                        else if (str[i+2] == ')' || str[i+2] == '}')
                            topD = -1;
                        if(str[i+2] == '=')
                        {
                            fprintf(outFile, "[=][");
                            i += 5;
                            j = 0;
                            int k, l, m;
                            for(m = cnt; m >= 0; --m)
                                if(strcmp(tabVal[m].name, check) == 0)
                                    break;
                            while(str[i] != ']')
                            {
                                check[j] = str[i];
                                ++i;
                                ++j;
                            }
                            check[j] = '\0';
                            l = strlen(check);

                            for(k = 0; k < l; ++k)
                                if(!isdigit(check[k]))
                                    break;
                            if(k == l)
                            {
                                fprintf(outFile, "%s]", check);
                                strcpy(tabVal[m].val, check);
                            }
                            else if(check[k] == '.')
                            {
                                ++k;
                                for(; k < l; ++k)
                                    if(!isdigit(check[k]))
                                        break;
                                if(k == l)
                                {
                                    fprintf(outFile, "%s]", check);
                                    strcpy(tabVal[m].val, check);
                                }
                            }
                            else if(k == 0)
                            {
                                cur[0] = ' ';
                                for(m = 3; m < l; ++m)
                                    cur[m-2] = check[m];
                                cur[m] = '\0';
                                for(m = cnt-1; m >= 0; --m)
                                {
                                    if(strcmp(tabVal[m].name, cur) == 0
                                       && strcmp(tabVal[m].iT, "func") == 0 && str[i+2] == '(')
                                    {
                                        fprintf(outFile, "id %d]", tabVal[m].id);
                                        break;
                                    }
                                    else if(strcmp(tabVal[m].name, cur) == 0
                                            && strcmp(tabVal[m].iT, "var") == 0 && str[i+2] != '(')
                                    {
                                        fprintf(outFile, "id %d]", tabVal[m].id);
                                        break;
                                    }
                                }
                            }

                        }
                    }
                    else
                    {
                        j = 0;
                        while(str[i] != ']')
                        {
                            check[j] = str[i];
                            ++i;
                            ++j;
                        }
                        check[j] = '\0';
                        fprintf(outFile, "%s]", check);

                        if(strcmp(check, "int") == 0 ||
                           strcmp(check, "float") == 0 || strcmp(check, "double") == 0 ||
                           strcmp(check, "char") == 0)
                        {
                            ++topD;
                            strcpy(dType[topD], check);
                        }
                        if(strcmp(check, "}") == 0)
                            --topS;
                    }
                }
            }
        }
    }
    fclose(oneFile);
    fclose(outFile);
}

void tabInsert()
{
    tabVal[cnt].id = cnt + 1;
    strcpy(tabVal[cnt].name, cur);
    strcpy(tabVal[cnt].dT, dType[topD]);
    if(topS == -1)
        strcpy(tabVal[cnt].sc, "global");
    else
        strcpy(tabVal[cnt].sc, scope[topS]);

    if(iType == 1)
    {
        strcpy(tabVal[cnt].iT, "func");
        scopeVal();
    }
    else
        strcpy(tabVal[cnt].iT, "var");
    strcpy(tabVal[cnt].val, "NULL");

    ++cnt;
}

void tabSearch()
{
    int i;

    strcpy(cur, check);

    for(i = 0; i < cnt; ++i)
    {
        if(strcmp(check, tabVal[i].name) == 0 && strcmp(tabVal[i].sc, scope[topS]) == 0)
        {
            if(topD != -1)
                printf("Duplicate Identifier Declaration at line %d.\n", lineNum);
            break;
        }
        else if(strcmp(check, tabVal[i].name) == 0 && strcmp(tabVal[i].sc, "global") == 0)
            break;
        else if(strcmp(check, tabVal[i].name) == 0 && iType == 1 && strcmp(tabVal[i].iT, "func") == 0)
            break;
    }
    if(i == cnt)
    {
        if(topD == -1)
            printf("Undefined Identifier at line %d.\n", lineNum);
        else
            tabInsert();
    }
}

void scopeVal()
{
    int i;

    for(i = cnt; i >= 0; --i)
        if(strcmp(tabVal[i].iT, "func") == 0)
            break;

    if(i >= 0)
    {
        ++topS;
        strcpy(scope[topS], tabVal[i].name);
    }
}

