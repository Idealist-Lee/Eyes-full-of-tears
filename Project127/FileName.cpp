#include<stdio.h>
#include<string.h>

struct Park
{
    char name[100];
    char free[10];
};

//�ο͵�¼
int visitor_login();
//����Ա��¼
int manager_login(char manager_ID[100], char manager_password[100]) {
    char correct_ID[] = "yuanzhang";
    char correct_password[] = "abcd1234";

    printf("�������˺ţ�\n");
    scanf_s("%99s", manager_ID, 100);

    printf("���������룺\n");
    scanf_s("%99s", manager_password, 100);

    if (strcmp(manager_ID, correct_ID) == 0 && strcmp(manager_password, correct_password) == 0)
    {
        printf("��¼�ɹ���\n");
        return 1;
    }
    else {
        printf("�˺Ż��������\n");
        return 0;
    }
}


int visitor_menu();


int manager_menu() {
    printf("***********\n");
    printf("��ѡ������Ҫ�鿴�����ݣ�\n");
    printf("1.�鿴������Ŀ��\n");
    printf("2.����������Ŀ��\n");
    printf("3.ɾ��������Ŀ��\n");
    printf("4.�޸�������Ŀ��\n");
    printf("5.����������Ŀ��\n");
    printf("6.����������Ŀ��\n");
    printf("7.�˳�������Ŀ��\n");
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
    printf("��ӭ����xx����԰:\n");
    printf("\n");
    printf("��ѡ����ݣ�\n");
    printf("1.�ο�\n");
    printf("2.������Ա\n");
    printf("3.�˳�����\n");
    printf("\n");
    printf("������ѡ�");

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
                //��¼�ɹ���Ĳ���
            }
            else {
                //��¼ʧ�ܺ�Ĳ���
            }
            continue;
        }
        if (choice == 3)
        {
            printf("��ӭ�´�ʹ�ã�\n\n");
            break;
        }
        if (choice > 3 || choice < 1)
        {
            printf("����������������룺");
            continue;
        }
    }


};