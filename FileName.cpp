#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define max 100

struct commodity
{
	int serial[max];
	char name[max][max];
	int number[max];
	int prize[max];
	char time[max][max];
	int size;
};
typedef struct commodity* My;

void found(My manage)
{
	int i;
	printf("--------------------------------------------------------------------------------\n");
	printf("     ���        ��Ʒ����          ���        ����        �ܼ�        ��������\n");
	for (i = 0; i < manage->size; i++)
	{
		printf("     %-12d%-18s%-12d%-12d%-12d%-12s\n", manage->serial[i], manage->name[i], manage->number[i], manage->prize[i], manage->number[i] * manage->prize[i], manage->time[i]);
	}
	printf("\n--------------------------------------------------------------------------------");
	printf("\n");
}

void find(My manage)
{
	int i;
	printf("-----------------------------------------------------------\n");
	printf("     ���        ���        �ܼ�\n");
	for (i = 0; i < manage->size; i++)
	{
		printf("     %-12d%-12d%-12d\n", manage->serial[i], manage->number[i], manage->number[i] * manage->prize[i]);
	}
	printf("\n-----------------------------------------------------------");
	printf("\n");
}


int judge(My manage, int serial)
{
	int i;
	for (i = 0; i < manage->size; i++)
	{
		if (manage->serial[i] == serial)
			return 1;
	}
	return 0;
}

void add(My manage, int serial, int num)
{
	int i;
	for (i = 0; i < manage->size; i++)
	{
		if (manage->serial[i] == serial)
			break;
	}
	manage->number[i] += num;
	printf("��ӿ��ɹ���\n");
}

int mydelete(My manage, int serial)
{
	int i;
	for (i = 0; i < manage->size; i++)
	{
		if (manage->serial[i] == serial)
			break;
	}
	if (i == manage->size)
	{
		printf("����Ʒ������\n");
		return 0;
	}
	for (; i < manage->size; i++)
	{
		strcpy(manage->name[i], manage->name[i + 1]);
		strcpy(manage->time[i], manage->time[i + 1]);
		manage->number[i] = manage->number[i + 1];
		manage->serial[i] = manage->serial[i + 1];
		manage->prize[i] = manage->prize[i + 1];
	}
	manage->size--;
	printf("ɾ���ɹ�\n");
}

int search(My manage, int serial)
{
	int i;
	for (i = 0; i < manage->size; i++)
	{
		if (manage->serial[i] == serial)
			break;
	}
	if (i == manage->size)
	{
		printf("����Ʒ������\n");
		return 0;
	}
	printf("--------------------------------------------------------------------------------\n");
	printf("     ���        ��Ʒ����          ���        ����        �ܼ�        ��������\n");
	printf("     %-12d%-18s%-12d%-12d%-12d%-12s\n", manage->serial[i], manage->name[i], manage->number[i], manage->prize[i], manage->number[i] * manage->prize[i], manage->time[i]);
	printf("\n--------------------------------------------------------------------------------\n");

}


int put(My manage)
{
	int t, num;
	printf("��������Ʒ��š����ơ���桢���ۡ��������ڣ�\n");
	char a[max], b[max];
	scanf("%d", &t);
	if (judge(manage, t))
	{
		scanf("%*s %d %*d %*s", &num);
		printf("����Ʒ�Ѵ��ڣ����Զ�Ϊ������ӿ��ҳ�棻\n");
		add(manage, t, num);
		return 0;
	}
	manage->serial[manage->size] = t;
	scanf("%s %d %d %s", manage->name[manage->size], &manage->number[manage->size], &manage->prize[manage->size], b);
	//strcpy(manage->name[manage->size], a);
	strcpy(manage->time[manage->size], b);
	manage->size++;
	printf("���ɹ�\n");
}

int out(My manage, int serial, int num)
{
	int i;
	for (i = 0; i < manage->size; i++)
	{
		if (manage->serial[i] == serial)
			break;
	}
	if (i == manage->size)
	{
		printf("����Ʒ������\n");
		return 0;
	}
	manage->number[i] -= num;
	if (manage->number[i] < 0)
	{
		printf("�ֿⴢ�����㣬����������������");
		manage->number[i] += num;
		scanf("%d", &num);
		out(manage, serial, num);
	}
	printf("����ɹ���\n");
	if (manage->number[i] == 0)
	{
		printf("����Ʒ����ѿգ����Զ�Ϊ��ɾ����\n");
		mydelete(manage, serial);
	}
}

int change(My manage, int serial)
{
	int i;
	char a[max], b[max];
	for (i = 0; i < manage->size; i++)
	{
		if (manage->serial[i] == serial)
			break;
	}
	if (i == manage->size)
	{
		printf("����Ʒ������\n");
		return 0;
	}
	printf("���������Ʒ�����ơ���桢���ۡ��������ڣ�");
	scanf("%s %d %d %s", a, &manage->number[i], &manage->prize[i], b);
	strcpy(manage->name[i], a);
	strcpy(manage->time[i], b);
	printf("�޸���ɣ�\n");
}


int main()
{
	int i, serial, number;
	struct commodity manage;
	manage.size = 0;
	while (1)
	{
		printf("----------------------------------------\n");
		printf("����  1  �����Ʒ��Ϣ\n");
		printf("����  2  �鿴���п���嵥\n");
		printf("����  3  ����\n");
		printf("����  4  ɾ��ָ����Ʒ\n");
		printf("����  5  ���ָ����Ʒ���\n");
		printf("����  6  ����ָ����Ʒ�嵥\n");
		printf("����  7  �޸�ָ����Ʒ��Ϣ\n");
		printf("����  8  ��ʾ������Ʒ����Ϣ1��3��5λ\n");
		printf("���� -1  ��������\n");
		printf("----------------------------------------\n\n");
		scanf("%d", &i);
		if (i == 1)
		{
			put(&manage);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 2)
		{
			found(&manage);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 3)
		{
			printf("��������Ҫ������Ʒ�ı�źͳ���������");
			scanf("%d %d", &serial, &number);
			out(&manage, serial, number);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 4)
		{
			printf("��������Ҫɾ����Ʒ�ı�ţ�");
			scanf("%d", &serial);
			mydelete(&manage, serial);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 5)
		{
			printf("��������Ҫ�����Ʒ�ı�ź�������");
			scanf("%d %d", &serial, &number);
			add(&manage, serial, number);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 6)
		{
			printf("��������Ҫ���ҵ���Ʒ�ı�ţ�");
			scanf("%d", &serial);
			search(&manage, serial);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 7)
		{
			printf("��������Ҫ�޸���Ʒ�ı�ţ�");
			scanf("%d", &serial);
			change(&manage, serial);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == 8)
		{
			find(&manage);
			printf("\n\n");
			printf("���������ַ������˵���");
			scanf("%d", &number);
		}
		if (i == -1)
		{
			printf("��ӭ�´�ʹ�ã�");
			printf("\n\n");
			printf("\n\n");
		}
	}
}