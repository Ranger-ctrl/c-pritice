#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX 100
#define LEN 50
#define LLEN 20

// 车辆信息结构体
typedef struct {
    char t[LEN + 1]; // 类型
    char l[LLEN + 1]; // 车牌
    char n[LEN + 1]; // 名字
    int id; // 学号
    char c[LEN + 1]; // 学院
    char p[LEN + 1]; // 电话
} V;

V vs[MAX]; // 车辆数组
int cnt = 0; // 车辆计数

void inputVehicle(V *v) {
    printf("类型: ");
    scanf("%50s", v->t); // 确保不超出长度限制
    printf("车牌: ");
    scanf("%20s", v->l);
    printf("名字: ");
    scanf("%50s", v->n);
    printf("学号: ");
    scanf("%d", &v->id);
    printf("学院: ");
    scanf("%50s", v->c);
    printf("电话: ");
    scanf("%50s", v->p);
}

// 添加车辆
void add() {
    if (cnt >= MAX) {
        printf("已满。\n");
        return;
    }

    V v;
    inputVehicle(&v);
    vs[cnt++] = v;
    printf("添加成功。\n");
}

// 搜索车辆
void search() {
    printf("输入搜索信息: ");
    char info[LEN + 1];
    scanf("%50s", info);

    int found = 0;
    for (int i = 0; i < cnt; i++) {
        if (strcmp(info, vs[i].t) == 0 ||
            strcmp(info, vs[i].l) == 0 ||
            strcmp(info, vs[i].n) == 0 ||
            (atoi(info) == vs[i].id && atoi(info) != 0) || // 直接比较学号
            strcmp(info, vs[i].c) == 0 ||
            strcmp(info, vs[i].p) == 0) {
            printf("找到:\n类型 %s\n车牌 %s\n名字 %s\n学号 %d\n学院 %s\n电话 %s\n",
                   vs[i].t, vs[i].l, vs[i].n, vs[i].id, vs[i].c, vs[i].p);
            found = 1;
        }
    }
    if (!found) {
        printf("未找到。\n");
    }
}

// 修改车辆
void modify() {
    printf("输入车牌: ");
    char lic[LLEN + 1];
    scanf("%20s", lic);

    for (int i = 0; i < cnt; i++) {
        if (strcmp(lic, vs[i].l) == 0) {
            printf("当前信息:\n类型 %s\n车牌 %s\n名字 %s\n学号 %d\n学院 %s\n电话 %s\n",
                   vs[i].t, vs[i].l, vs[i].n, vs[i].id, vs[i].c, vs[i].p);
            printf("请输入新的信息:\n");
            inputVehicle(&vs[i]);
            printf("修改成功。\n");
            return;
        }
    }
    printf("未找到该车牌。\n");
}

// 显示所有车辆
void display() {
    if (cnt == 0) {
        printf("无记录。\n");
        return;
    }
    for (int i = 0; i < cnt; i++) {
        printf("类型 %s\n车牌 %s\n名字 %s\n学号 %d\n学院 %s\n电话 %s\n----\n",
               vs[i].t, vs[i].l, vs[i].n, vs[i].id, vs[i].c, vs[i].p);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n菜单\n1. 添加\n2. 搜索\n3. 修改\n4. 显示\n5. 退出\n选择: ");
        if (scanf("%d", &ch) != 1) { // 检查输入是否为整数
            printf("无效输入，请重新输入。\n");
            while (getchar() != '\n'); // 清空输入缓冲区
            continue;
        }

        switch (ch) {
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                modify();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("退出系统。\n");
                return 0;
            default:
                printf("无效选项。\n");
        }
    }

    return 0;
}