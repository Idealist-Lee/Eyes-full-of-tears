#include<stdio.h>
#include<string.h>

struct Park
{
    char name[100];
    char free[10];
};

//游客登录
int visitor_login();
//管理员登录
int manager_login(char manager_ID[100], char manager_password[100]) {
    char correct_ID[] = "yuanzhang";
    char correct_password[] = "abcd1234";

    printf("请输入账号：\n");
    scanf_s("%99s", manager_ID, 100);

    printf("请输入密码：\n");
    scanf_s("%99s", manager_password, 100);

    if (strcmp(manager_ID, correct_ID) == 0 && strcmp(manager_password, correct_password) == 0)
    {
        printf("登录成功！\n");
        return 1;
    }
    else {
        printf("账号或密码错误！\n");
        return 0;
    }
}


int visitor_menu();


int manager_menu() {
    printf("***********\n");
    printf("请选择您想要查看的内容：\n");
    printf("1.查看游玩项目：\n");
    printf("2.增加游玩项目：\n");
    printf("3.删除游玩项目：\n");
    printf("4.修改游玩项目：\n");
    printf("5.保存游玩项目：\n");
    printf("6.查找游玩项目：\n");
    printf("7.退出游玩项目：\n");
    printf("***********\n");

    int i;

    scanf_s("%d", &i);
    if (i < 1 || i>7)return 0;
    switch (i)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        return 4;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
        /*default:
            return -1;*/
    }
}
void manager_printf();
void manager_entry();
void manager_save();
void manager_alter();
void manager_delete();

int main()
{
    int choice;
    printf("欢迎来到xx游乐园:\n");
    printf("\n");
    printf("请选择身份：\n");
    printf("1.游客\n");
    printf("2.工作人员\n");
    printf("3.退出程序\n");
    printf("\n");
    printf("请输入选项：");

    while (1)
    {
        scanf_s("%d", &choice);
        if (choice == 1)
        {
            visitor_login();
            continue;
        }
        if (choice == 2)
        {
            char manager_ID[100];
            char manager_password[100];
            if (manager_login(manager_ID, manager_password))
            {
                //登录成功后的操作
            }
            else {
                //登录失败后的操作
            }
            continue;
        }
        if (choice == 3)
        {
            printf("欢迎下次使用！\n\n");
            break;
        }
        if (choice > 3 || choice < 1)
        {
            printf("输入错误，请重新输入：");
            continue;
        }
    }


};