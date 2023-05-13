#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� 0 �� max ֮��������
int randInt(int max) {
    return rand() % (max + 1);
}

// ��ȡ�����
char getOperator() {
    char operators[] = {'+', '-', '*', '/'};
    int index = randInt(3);
    return operators[index];
}

// ������Ŀ���������ַ���
char* generateQuestion(int max, char Opera, int hasBrackets, int hasDecimal){
    char *question = (char *)malloc(sizeof(char) * 20);
    int num1 = randInt(max), num2 = randInt(max);  // �������������
    if (hasDecimal) {  // �Ƿ��С��
        double d1 = (double)randInt(max * 10) / 10, d2 = (double)randInt(max * 10) / 10;
        num1 = d1;
        num2 = d2;
    }
    if (hasBrackets) {  // �Ƿ������
        sprintf(question, "(%d %c %d)", num1, Opera, num2);
    } else {
        sprintf(question, "%d %c %d", num1, Opera, num2);
    }
    return question;
}

int main() {
    srand((unsigned)time(NULL));  // ��ʼ�����������
    int numQuestions, max;
    char Opera;
    int hasBrackets, hasDecimal;
    char outputMethod;
    printf("��������Ŀ������");
    scanf("%d", &numQuestions);
    printf("�������������");
    scanf("%d", &max);
    printf("��ѡ���������+��-��*��/����");
    scanf(" %c", &Opera);
    printf("�Ƿ�����ţ�1-�ǣ�0-�񣩣�");
    scanf("%d", &hasBrackets);
    printf("�Ƿ��С����1-�ǣ�0-�񣩣�");
    scanf("%d", &hasDecimal);
    printf("��ѡ�������ʽ��T-�նˣ�F-�ļ�����");
    scanf(" %c", &outputMethod);
    if (outputMethod == 'T' || outputMethod == 't') {  // ������ն�
        for (int i = 0; i < numQuestions; i++) {
            printf("%s ", generateQuestion(max, Opera, hasBrackets, hasDecimal));
        }
    } else if (outputMethod == 'F' || outputMethod == 'f') {  // ������ļ�
        char filename[20];
        printf("�������ļ�����");
        scanf("%s", filename);
        FILE* fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("�޷����ļ�\n");
        } else {
            for (int i = 0; i < numQuestions; i++) {
                char *question = generateQuestion(max, Opera, hasBrackets, hasDecimal);
                fprintf(fp, "%s ", question);
                free(question);  // �ͷ��ڴ�
            }
            fclose(fp);
            printf("�ѱ��浽�ļ���%s\n", filename);
        }
    } else {
        printf("����������ʽ��");
    }
    return 0;
}
