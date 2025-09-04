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
	printf("     编号        商品名称          库存        单价        总价        生产日期\n");
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
	printf("     编号        库存        总价\n");
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
	printf("添加库存成功！\n");
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
		printf("该商品不存在\n");
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
	printf("删除成功\n");
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
		printf("该商品不存在\n");
		return 0;
	}
	printf("--------------------------------------------------------------------------------\n");
	printf("     编号        商品名称          库存        单价        总价        生产日期\n");
	printf("     %-12d%-18s%-12d%-12d%-12d%-12s\n", manage->serial[i], manage->name[i], manage->number[i], manage->prize[i], manage->number[i] * manage->prize[i], manage->time[i]);
	printf("\n--------------------------------------------------------------------------------\n");

}


int put(My manage)
{
	int t, num;
	printf("请输入商品编号、名称、库存、单价、生产日期：\n");
	char a[max], b[max];
	scanf("%d", &t);
	if (judge(manage, t))
	{
		scanf("%*s %d %*d %*s", &num);
		printf("该商品已存在，将自动为您打开添加库存页面；\n");
		add(manage, t, num);
		return 0;
	}
	manage->serial[manage->size] = t;
	scanf("%s %d %d %s", manage->name[manage->size], &manage->number[manage->size], &manage->prize[manage->size], b);
	//strcpy(manage->name[manage->size], a);
	strcpy(manage->time[manage->size], b);
	manage->size++;
	printf("入库成功\n");
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
		printf("该商品不存在\n");
		return 0;
	}
	manage->number[i] -= num;
	if (manage->number[i] < 0)
	{
		printf("仓库储备不足，请重新输入数量：");
		manage->number[i] += num;
		scanf("%d", &num);
		out(manage, serial, num);
	}
	printf("出库成功！\n");
	if (manage->number[i] == 0)
	{
		printf("该商品库存已空，将自动为您删除！\n");
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
		printf("该商品不存在\n");
		return 0;
	}
	printf("请输入此商品的名称、库存、单价、生产日期：");
	scanf("%s %d %d %s", a, &manage->number[i], &manage->prize[i], b);
	strcpy(manage->name[i], a);
	strcpy(manage->time[i], b);
	printf("修改完成！\n");
}


int main()
{
	int i, serial, number;
	struct commodity manage;
	manage.size = 0;
	while (1)
	{
		printf("----------------------------------------\n");
		printf("输入  1  添加商品信息\n");
		printf("输入  2  查看所有库存清单\n");
		printf("输入  3  出库\n");
		printf("输入  4  删除指定商品\n");
		printf("输入  5  添加指定商品库存\n");
		printf("输入  6  查找指定商品清单\n");
		printf("输入  7  修改指定商品信息\n");
		printf("输入  8  显示所有商品的信息1、3、5位\n");
		printf("输入 -1  结束程序\n");
		printf("----------------------------------------\n\n");
		scanf("%d", &i);
		if (i == 1)
		{
			put(&manage);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 2)
		{
			found(&manage);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 3)
		{
			printf("请输入需要出库商品的编号和出库数量：");
			scanf("%d %d", &serial, &number);
			out(&manage, serial, number);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 4)
		{
			printf("请输入需要删除商品的编号：");
			scanf("%d", &serial);
			mydelete(&manage, serial);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 5)
		{
			printf("请输入需要添加商品的编号和数量：");
			scanf("%d %d", &serial, &number);
			add(&manage, serial, number);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 6)
		{
			printf("请输入需要查找的商品的编号：");
			scanf("%d", &serial);
			search(&manage, serial);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 7)
		{
			printf("请输入需要修改商品的编号：");
			scanf("%d", &serial);
			change(&manage, serial);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == 8)
		{
			find(&manage);
			printf("\n\n");
			printf("输入任意字符调出菜单：");
			scanf("%d", &number);
		}
		if (i == -1)
		{
			printf("欢迎下次使用！");
			printf("\n\n");
			printf("\n\n");
		}
	}
}