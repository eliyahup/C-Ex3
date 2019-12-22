#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 #define LINE 256
 #define WORD 30

 int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int Getline(char s[]){
    int count=0;
    int count2=0;
    int char1 = 0;
    for (count = 0; (char1= getchar())!=EOF && count<=LINE&&char1!='\n'; count++)
    {
            s[count2]=char1;
            count2++;
    }
    if(char1 =='\n'){
    s[count2]=char1;
    count2++;
   s[count2]= 0;
   count++;
    }
    return count;
}
int getword(char w[]){
 int count=0;
    int count2=0;
    int char1 = 0;
    for (count = 0;(char1= getchar())!=EOF && count<=WORD&&char1!=' '&&char1!='\n'&&char1!='\t'; count++)
    {
            w[count2]=char1;
            count2++;
    }
    w[count2]= 0;

    return count;
}
int substring( char * str1, char * str2){
    if(strlen(str2)>strlen(str1)){
        return 0;
    }
    int count = 0;
   for(int i=0;i<strlen(str1);i++){           //chacks char
       for(int j=0;j<strlen(str2);j++){
       if(*(str1+j+i) == *(str2+j)){
           count++;
       }
   } 
   if(count == strlen(str2)){
       return 1;
   }
   count = 0;
   } 
   return 0;
}
int similar(char *s, char *t){
     int count = 0;
     char a[WORD];
    strcpy(a, s); 
     if(abs(strlen(s)-strlen(t))>1){
         return 0;
     }
   for(int i=0;i<strlen(t);i++){
       for(int j=0;j<strlen(a);j++){
        if(*(t+i) == *(a+j)){
           count++;
           a[j]= '@';
        break;
       } 
    }
   } 
   if(count >= max(strlen(s),strlen(t))-1){
       return 1;
   }
    return 0;
}
void print_lines(char * str){
    char row[LINE];
    
    while(Getline(row)!=0){
        if(substring(row,str)==1){
            printf("%s",row); 
        }
    }
}
void print_similar_words(char * str){
char word[WORD];

while(getword(word)!=0){
 if(similar(word,str)==1){
            printf("%s\n",word); 
        }
}


}
int main(){
char str[WORD];
getword(str);
char operation;
operation = getchar();
getchar();
getchar();

switch (operation)
{
case 'a':
   print_lines(str);
    break;
case 'b':
print_similar_words(str);
    break;

default:
printf("error input");
    break;
}

 return 0;
}