#include <stdio.h>
#include "student.h"

void read(FILE *fp, int index);

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("student.data", "r");
	if (fp) {
		fseek(fp, 0L, SEEK_END); // 读写的位置移到尾巴
		long size = ftell(fp); // ftell 得到所在的位置，这个位置就是大小
		int number = size / sizeof(Student);
		int index = 0;
		printf("有%d个数据，你要看第几个：", number);
		scanf("%d", &index);
		read(fp, index-1);
		fclose(fp);
	}
	return 0;
}

void read(FILE *fp, int index)
{
	fseek(fp, index*sizeof(Student), SEEK_SET); // 从头开始走到第 index 个 Student 的结构
	Student stu;
	// 读一个 Student 结构
	if (fread(&stu, sizeof(Student), 1, fp) == 1) {
		printf("第%d个学生：\n", index+1);
		printf("\t姓名：%s\n", stu.name);
		printf("\t性别：");
		switch (stu.gender) {
			case 0: printf("男\n"); break;
			case 1: printf("女\n"); break;
			case 2: printf("其他\n"); break;
		}
		printf("\t年龄：%d\n", stu.age);
	}
}