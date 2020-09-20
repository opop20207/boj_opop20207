#include <stdio.h>
int N;
char file[51][51];
char res[51];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", file[i]);
	}
	int len;
	for (len = 0; file[0][len] != '\0'; len++);
	int i;
	int stat;
	for (i = 0; i < len; i++) {
		char temp=file[0][i];
		stat = 0;
		for(int j=1;j<N;j++){
			if (temp != file[j][i]) {
				stat = -1;
			}
		}
		if (stat == -1) {
			res[i] = '?';
		}
		else {
			res[i] = temp;
		}
	}
	res[i] = '\0';
	printf("%s", res);
}