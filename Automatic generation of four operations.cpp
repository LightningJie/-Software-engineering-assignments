#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成 0 到 max 之间的随机数
int randInt(int max) {
    return rand() % (max + 1);
}

// 获取运算符
char getOperator() {
    char operators[] = {'+', '-', '*', '/'};
    int index = randInt(3);
    return operators[index];
}

// 生成题目，并返回字符串
char* generateQuestion(int max, char Opera, int hasBrackets, int hasDecimal){
    char *question = (char *)malloc(sizeof(char) * 20);
    int num1 = randInt(max), num2 = randInt(max);  // 生成两个随机数
    if (hasDecimal) {  // 是否带小数
        double d1 = (double)randInt(max * 10) / 10, d2 = (double)randInt(max * 10) / 10;
        num1 = d1;
        num2 = d2;
    }
    if (hasBrackets) {  // 是否带括号
        sprintf(question, "(%d %c %d)", num1, Opera, num2);
    } else {
        sprintf(question, "%d %c %d", num1, Opera, num2);
    }
    return question;
}

int main() {
    srand((unsigned)time(NULL));  // 初始化随机数种子
    int numQuestions, max;
    char Opera;
    int hasBrackets, hasDecimal;
    char outputMethod;
    printf("请输入题目数量：");
    scanf("%d", &numQuestions);
    printf("请输入最大数：");
    scanf("%d", &max);
    printf("请选择运算符（+，-，*，/）：");
    scanf(" %c", &Opera);
    printf("是否带括号（1-是，0-否）：");
    scanf("%d", &hasBrackets);
    printf("是否带小数（1-是，0-否）：");
    scanf("%d", &hasDecimal);
    printf("请选择输出方式（T-终端，F-文件）：");
    scanf(" %c", &outputMethod);
    if (outputMethod == 'T' || outputMethod == 't') {  // 输出到终端
        for (int i = 0; i < numQuestions; i++) {
            printf("%s ", generateQuestion(max, Opera, hasBrackets, hasDecimal));
        }
    } else if (outputMethod == 'F' || outputMethod == 'f') {  // 输出到文件
        char filename[20];
        printf("请输入文件名：");
        scanf("%s", filename);
        FILE* fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("无法打开文件\n");
        } else {
            for (int i = 0; i < numQuestions; i++) {
                char *question = generateQuestion(max, Opera, hasBrackets, hasDecimal);
                fprintf(fp, "%s ", question);
                free(question);  // 释放内存
            }
            fclose(fp);
            printf("已保存到文件：%s\n", filename);
        }
    } else {
        printf("错误的输出方式！");
    }
    return 0;
}
