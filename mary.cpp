#include<stdio.h>
#include<string.h>
int main() {
	int i,j,flag=-1;
	char a[4][10];
	for(i=0; i<4; i++) {
		scanf("%s",&a[i]);
	}
	for(i=0; i<3; i++) {
		if(strlen(a[i])==strlen(a[3])) {
			for(j=0; j<strlen(a[i]); j++) {
				if(a[3][j]!='?' && a[3][j]==a[i][j]) {
					if(j==strlen(a[i])-1) {
						printf("%s",a[i]);
						flag=1;
					}
				} else if(a[3][j]=='?') {
					continue;
				} else {
					break;
				}
			}
		}
	}
	if(flag==-1) {
		printf("%d",flag);
	}
}
