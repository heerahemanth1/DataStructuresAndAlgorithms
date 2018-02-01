#include<stdio.h>
#include<string.h>

int main() {
 FILE *f;
 char fname[100],temp[20];
 char keyw[20][10] = {"if","break","else","switch","typedef","register","enum","case","extern","return","union","const","continue","for","default","int","float","do","while","sizeof"};
 printf("\nEnter the absolute path of C file: ");
 char op1[] = {'+','-','=','!','<','>','&','|','+','-','*','/','%','&','^','|'};
 char op2[] = {'+','-','=','=','=','=','&','|','=','=','=','=','=','=','=','='};
 scanf("%s",&fname);
 f = fopen(fname,"r");
 char cpro[1000];
 fread(cpro,1000,sizeof(char),f);
 int n = strlen(cpro);
 int i = 0;
 int j,k;
 int top = 0;
 while(i<n) {
  if(cpro[i] != ' ' && cpro[i] != '(' && cpro[i] != ';' && cpro[i] != '\n' && cpro[i] != '\0') {
    if(i<n-1) {
  		for(k=0;k<16;k++) {
  			if(cpro[i]==op1[k]) {
  				if(cpro[i+1]==op2[k]) {
  					printf("\nOperator detected: %c%c\n",cpro[i],cpro[i+1]);
  					i++;
					break;
  				} else {
  					printf("\nOperator detected: %c\n",cpro[i]);
  					break;
  				}
  			}
  		}
  	}
	temp[top] = cpro[i];
    top++;
  } else {
    j = 0;
    while(j<20) {
      if(strcmp(keyw[j],temp)==0) {
        printf("\nKeyword found: %s\n",temp);
        break;
      }
      j++;
    }
    memset(temp,'\0',sizeof(temp));
    top = 0;
  }
  i++;
 }
}
