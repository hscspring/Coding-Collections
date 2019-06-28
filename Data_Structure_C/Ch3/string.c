#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SNode *String;
struct SNode {
	char *ch;
	int len;
};

#define MAX 10

String createString() {
	String S;
	S = (String)malloc(sizeof(struct SNode));
	// init the pointer
	S->ch = (char*)malloc(sizeof(char));
	S->len = 0;
	char c;
	scanf("%c", &c); 
	while (c!=';') {
		// do not need to give a space, it's a pointer
		// S->ch[S->len] = (char)malloc(sizeof(char));
		S->ch[S->len++] = c;
		scanf("%c", &c); 
	}
	S->ch[S->len] = '\0';
	return S;
}

String strConcat(String S1, String S2) {
	String S;
	S = (String)malloc(sizeof(struct SNode)); // better to use to prevent warning
	S->ch = (char*)malloc(sizeof(char));
	S->len = 0;
	int i = 0, j = 0;
	while(S1->ch[i] != '\0') {
		S->ch[S->len++] = S1->ch[i++];
	}
	while(S2->ch[j] != '\0') {
		S->ch[S->len++] = S2->ch[j++];
	}
	return S;
}

String subString(String S, int loc, int len) {
	String subS;
	subS = (String)malloc(sizeof(struct SNode));  // better to use to prevent warning
	if (loc<0 || loc > len || len < 0 || len > S->len) {
		printf("param error.\n");
	} else {
		// POINTER DO NOT NEED SPACE
		// subS->ch = malloc(sizeof(char) * len);
		subS->ch = (char*)malloc(sizeof(char));
		subS->len = 0;
		for (int k=0; k<len; k++) {
			subS->ch[k] = S->ch[k+loc];
			subS->len++;
		}
	}
	return subS;
}

int strCmp(String s1, String s2) {
	int i = 0;
	while (s1->ch[i] == s2->ch[i] && s1->ch[i] != '\0')
		i++;
	return s1->ch[i] - s2->ch[i];
}

int * findString(String S, String subS) {
	int i=0, j=0, k=0;
	static int loc[MAX] = {-1};
	if (subS->len > S->len) {
		printf("param error.\n");
	}
	while (S->ch[i] != '\0') {
		if (S->ch[i] == subS->ch[j]) {
			++i;
			++j;
		} else {
			if (subS->ch[j] == '\0') {
				loc[k++] = i-j;
			} 
			// else {
			// 	i = i-j+1;
			// }
			i = i-j+1;
			j = 0;
		}
	}
	if (subS->ch[j] == '\0')
		loc[k++] = i-j;
	return loc;
}

int main() {
	String s1, s2;
	s1 = createString();
	s2 = createString();
	printf("play: %d\n", s2->ch[s2->len] == '\0');
	printf("s1 len: %d\n", s1->len);
	for (int i=0; i<s1->len; i++) {
		printf("%c", s1->ch[i]);
	}
	printf("\n");
	printf("s2 len: %d\n", s2->len);
	for (int j=0; j<s2->len; j++) {
		printf("%c", s2->ch[j]);
	}
	printf("\n");

	String s;
	s = strConcat(s1, s2);
	printf("s len: %d\n", s->len);
	for (int k=0; k<s->len; k++) {
		printf("%c", s->ch[k]);
	}
	printf("\n");

	String subS;
	subS = subString(s, 2, 3);
	printf("subS len: %d\n", subS->len);
	for (int k=0; k<subS->len; k++) {
		printf("%c", subS->ch[k]);
	}
	printf("\n");

	int cmp = strCmp(s1, s2);
	printf("cmp: %d\n", cmp);


	// int a[] = {2, 4, 6};
	// int b[] = {2, 4, 6};
	// if (strcmp(a, b)==0) {
	// 	printf("cmp ab");
	// }
	// if (a == b) {
	// 	printf("a==b");
	// }

	int *loc;
	int x;
	loc = findString(s1, s2);
	for (int k=0; k<MAX; k++) {
		x = *loc++;
		if (x > 0 || k==0)
			printf("%d ", x);
	}
	printf("\n");

}