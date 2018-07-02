/*************************************************
Copyright (C����), 2018, Mango Tech. Co., Ltd.
 �ļ���: ���ʹ���.c
 Author:������(117583010128) Version:C���� Date:2,7,2018 
 Description: 
 I. ��Ҫ����:()
 ��ְԱ�Ĺ��ʽ�����ɾ�ļ���ѯ�Ĳ���,�����浽ָ���ļ�(gx.dat);
 II.������Ӧ�Ĵ��룺
 1����ѯfind()��
 2���޸�modify()��
 3�����add()��
 4��ɾ��del();
 5������write();
 6�����list();
 7���˳���
 III.�ṹ������ݣ�
   1.����	�ַ�����	��1~10λ���֣�0~9����ɵ��ַ���
   2.����	�ַ�����	��1~10����ĸ��1~5��������ɵ��ַ���
   3.��λ����	������ʵ��	�ɲ�ͬ������λ�����ʦ��ʵ���ҵ�ȷ���Ĺ���
   4.н������	������ʵ��	�ɹ���ȷ���Ĺ���
   5.ְ�����	������ʵ��	��ְ���ְ��ȷ���Ĺ���
   6.��Ч����	������ʵ��	��ҵ��ȷ���Ĺ���
   7Ӧ������	������ʵ��	ǰ4���֮��
   8.��������˰	˫����ʵ��	����һ���ı�������
   9.ʵ������	˫����ʵ��	Ӧ�����ʣ���������˰
*************************************************/
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<stdio.h>
struct emploees
{
	char num[10];    // ����

	char name[10];   // ����

	float jobz;      // ��λ����

	float agesz;     // н������

	float dutyz;     // ְ�����

	float perz;      // ��Ч����

	float shouldz;   // Ӧ������

	double tax;      // ��������˰

	double realz;    // ʵ������

} zggz[50];


int n=0;   // ȫ�ֱ���,��¼��Ա��

/*************************************************
 Function: grsds();
 Description: �����������˰�����ص����ô�
 Calls: ��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: �˺����ӵ��ô���ȡֵ "zggz[i].shouldz" ����ֵ���β� (float����) ' v ',��������� (double����) ' ctax '����������ĸ�������˰ 
 Output: �����
 Return: ����ֵ����Ϊdouble���͵�"ctax".
 Others: ���������ڸ�����ֵ,��ֱ�ӷ���0ֵ;
*************************************************/ 

double grsds(float v)
{   
	double ctax;

    if (v > 0)
	{
		if(v > 0 && v <= 500)
		{
			ctax = v * 0.05;

			return ctax;
		}
		else
			if ( v > 500 && v <= 2000)
			{
		            ctax = (v-500) * 0.1 + 500 * 0.05;

			    return ctax;
			}
			else
				if (v > 2000 && v <= 5000)
				{
				    ctax = (v-2000) * 0.15 + 1500 * 0.1+ 500 * 0.05;

				    return ctax;
				}
				else
					if (v > 5000 && v <= 20000)
					{
					    ctax = (v-5000) * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;

					    return ctax;
					}
					else
						if (v > 20000 && v <= 40000)
						{
						    ctax = (v-20000) * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;

						    return ctax;
						}
						else
							if (v > 40000 && v <= 60000)
							{
							    ctax = (v-40000) * 0.3+ 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;

							    return ctax;
							}
							else
								if (v > 60000 && v <= 80000)
								{
								   ctax = (v-60000) * 0.35+ 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;

								   return ctax;
								}
								else
									if (v > 80000 && v <= 100000)
									{
									   ctax = (v-80000) * 0.4 + 20000 * 0.35 + 20000 * 0.3+ 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;

									   return ctax;
									}
									else
										if (v > 100000)
										{
											ctax = (v-100000) * 0.45 + 20000 * 0.4 + 20000 * 0.35 + 20000 * 0.3 + 20000 * 0.25 + 15000 * 0.2 + 3000 * 0.15 + 1500 * 0.1 + 500 * 0.05;

											return ctax;
										}
	}
	else
		return 0;
}

/*************************************************
 Function: write();
 Description: ������������zggzȫ��д���ļ�"gx.dat"����,�˺�������C���Ը�ʽ�����ļ���д��
 Calls: ��
 Called By:��
 Table Accessed: ��
 Table Updated: ��
 Input: ����������һ������'j'��¼ȫ�ֱ���'n'��ֵ,���ý����ļ���д��
 Output: ��
 Return: �޷���ֵ
*************************************************/ 
void write()
{
    printf("Ŀǰ����Ϊ%d\n",n);

    int j = n;

    if (j > 0 && j < 50)
    {
         FILE *fp2;

         if ((fp2 = fopen ("gx.dat","wb+")) == NULL)
         {
              printf("���ļ�ʧ��\n");

              getch();

              exit(-1);
          }
    else
	     printf("�򿪳ɹ��������ڱ���  ");

         for (int i=0;i<n;i++)
         {
              fprintf(fp2,"%s %s %.2f %.2f %.2f %.2f %.2f %.2lf %.2lf",zggz[i].num,zggz[i].name,zggz[i].jobz,zggz[i].agesz,zggz[i].dutyz,zggz[i].perz,zggz[i].shouldz,zggz[i].tax,zggz[i].realz);//������д���ļ�

              fprintf(fp2,"\n");

          }

          printf("������ɣ�\n");                   //  ����ȫ��¼���ļ�

          fclose(fp2);                              //�ر��ļ�
	}          
	else
		if (j == 0)
		{
			FILE *fp2;
			
			if ((fp2 = fopen ("gd.dat","rb+")) == NULL)
			{
				printf("���ļ�ʧ��\n");
				
				getch();
				
				exit(-1);
			}
			else
			{
				printf("�򿪳ɹ��������ڱ���\n");
				
				fprintf(fp2,"%s %s %s %s %s %s %s %s %s"," "," "," "," "," "," "," "," "," ");
				
				fprintf(fp2,"\n");
				
				printf("������ɣ�\n");
				
				fclose(fp2);//�ر��ļ�
			}
		}
		else
			printf("�޼�¼������\n");
}

/*************************************************
 Function: find();
 Description: ��ѯ����ʾĿ����Ա��Ϣ
 Calls: �� 
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����gonghao�ַ������¼Ŀ�깤��ֵ,��ͨ��ѭ������ҵ�Ŀ���������
 Output: ��
 Return: �޷���ֵ
*************************************************/ 
void find()
{
   char gonghao[10];

   int i=0,j=101;

   printf("�����빤�� \n");

   scanf("%s",gonghao);

   for (;i<n;i++)
	   if (strcmp(gonghao,zggz[i].num)==0)
		   j=i;
   if (j == 101)
   {
     printf("�޴�Ա��������ȷ�Ϲ����Ƿ���ȷ����\n");
   }
   else
   {   
	   printf("����:\n");
	   printf("%s\n",zggz[j].num);

	   printf("����:\n");
	   printf("%s\n",zggz[j].name);
	   
	   printf("��λ����:\n");
	   printf("%.2f\n",zggz[j].jobz);

	   printf("н������:\n");
	   printf("%.2f\n",zggz[j].agesz);
	   
	   printf("ְ�����:\n");
	   printf("%.2f\n",zggz[j].dutyz);
	   
	   printf("��Ч����:\n");
	   printf("%.2f\n",zggz[j].perz);
	  
	   printf("Ӧ������:\n");
	   printf("%.2f\n",zggz[j].shouldz);
	   
	   printf("��������˰:\n");
	   printf("%.2lf\n",zggz[j].tax);
	  
	   printf("ʵ������:\n");
	   printf("%.2lf\n",zggz[j].realz);
	  
	
   }
   
}
/*************************************************
 Function: modify();
 Description: ������ƥ�䵽���Ŷ�Ӧ�Ľṹ������޸Ĳ�ʵ�ֱ���
 Calls: ������write()���溯��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����'i','j'����ѭ���ļ�������¼Ŀ���λ��,����'s'ʵ���Ƿ�ȷ������Ĺ���
 Output: ��
 Return: ��
 Others: �ú���������ʾ�����޸ĵ���Ϣ
*************************************************/ 
void modify()
{
	char gonghao[10];

	int i=0,j=101;

	printf("=========������Ҫ�޸ĵĹ���=========== \n");

	scanf("%s",gonghao);

	for (;i < n; i++)
		if (strcmp(gonghao,zggz[i].num) == 0)
			j = i;
	if (j == 101)
	{
		printf("==========�޴�Ա��������ȷ�Ϲ����Ƿ���ȷ����==========\n");
	}
	                                   //���չ������β���
	else
	{
		printf("==========������¼�������Ϣ=========\n");

		printf("����:\n");
		scanf("%s",zggz[j].num);

		printf("����:\n");
		scanf("%s",zggz[j].name);

		printf("��λ����:\n");
		scanf("%f",&zggz[j].jobz);

		printf("н������:\n");
		scanf("%f",&zggz[j].agesz);

		printf("ְ�����:\n");
		scanf("%f",&zggz[j].dutyz);

		printf("��Ч����:\n");
		scanf("%f",&zggz[j].perz);

		zggz[j].shouldz = zggz[j].jobz+zggz[j].agesz+zggz[j].dutyz+zggz[j].perz;//����Ӧ������
		zggz[j].tax = grsds(zggz[j].shouldz);                                   //��������˰
		zggz[j].realz = zggz[j].shouldz-zggz[j].tax;                            //����ʵ������

		printf("�����������޸ĵ���Ϣ\n");

		printf("����: ");
		printf("%s\n",zggz[j].num);

		printf("����: ");
		printf("%s\n",zggz[j].name);

		printf("��λ����: ");
		printf("%.2f\n",zggz[j].jobz);

		printf("н������: ");
		printf("%.2f\n",zggz[j].agesz);

		printf("ְ�����: ");
		printf("%.2f\n",zggz[j].dutyz);

		printf("��Ч����: ");
		printf("%.2f\n",zggz[j].perz);
	}

	int s;

	printf("=======ȷ���Ƿ񱣴�? 1:��; 0:�� =======\n");

	scanf("%d",&s);

	if (s == 1)
	{
		write();
	}
}
/*************************************************
 Function: del();
 Description: ɾ����ӦĿ�����Ա
 Calls: write()���溯��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����gonghao�ַ������¼Ŀ�깤��ֵ,����'s'ʵ���Ƿ�ȷ������Ĺ���,����j,k��¼�±�ֵ
 Output: ��
 Return: �޷���ֵ
 Others: �ú���ʵ�ַ���Ϊ,ͨ��ѭ������ҵ���ӦĿ����Ա�±�j,����д�j��ʼ,ǰһ����ȡ��һ������,ѭ������Ϊ:j<n&&k<n;
*************************************************/ 
void del()
{
	
	char gonghao[10];

    int i=0,j=101;

    printf("=======������Ҫɾ���Ĺ���======== \n");

    scanf("%s",gonghao);

    for (;i<n;i++)
	  { if (strcmp(gonghao,zggz[i].num)==0)

		   j=i;
	  }
	
	   
    if (j == 101)
    {
         printf("�޴�Ա��������ȷ�Ϲ����Ƿ���ȷ����\n");
    }
              //���չ������β���
   else
   {
	  printf("==========�Ƿ�ȷ��ɾ��?  ����1ȷ�ϣ��˳������������ַ�===========\n");
	  
	  int c2;

	  scanf("%d",&c2);

	  if (c2 == 1)
	  {
	       if (j != (n-1))
		      {
			       for (int k = j + 1; j < n && k < n; j++, k++)
			          {
			                zggz[j]=zggz[k];    // ���κ�һ��¼�Ļ�ֵ
			          }

			           n--;    //   ��������һ��

		       }

		   else
		      n--;   //  ����ĩβɾ��
	  }
	  else
	  {
		  printf("�����˳�\n");
	  }
   }
   int s;

		printf("=========ȷ���Ƿ񱣴�? 1:��; 0:��===========\n");

		scanf("%d",&s);

		if(s==1)
		    {
				write();
		    }
}
/*************************************************
 Function: add()
 Description: ���Ӽ�¼��Ϣ�����ж��Ƿ��ظ����ż�¼
 Calls: write()���溯��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����'s'ʵ���Ƿ�ȷ������Ĺ��ܣ�
 Output: ��
 Return: �޷���ֵ
 Others: �ú�������ʾ���������Ϣ
*************************************************/ 
void add()
{
	int i=0,j=101;
	
	if ( n > 50)
	{
	  printf("��¼�ռ���������\n");
	}
	else
	{
		printf("���������ӳ�Ա��ȫ����Ϣ \n");

		printf("����:\n");

		scanf("%s",zggz[n].num);

		for (;i<n;i++)
		{
			if (strcmp(zggz[i].num,zggz[n].num)==0)
			{
				j=i;
			}
		}

		if (j != 101)
		{
			printf("==========�ظ����ţ����������룡������==========\n");
		}                                                                     //�ж��Ƿ��ظ�
		else
		{
			printf("����:\n");
			scanf("%s",zggz[n].name);
			
			printf("��λ����:\n");
			scanf("%f",&zggz[n].jobz);
			
			printf("н������:\n");
			scanf("%f",&zggz[n].agesz);
			
			printf("ְ�����:\n");
			scanf("%f",&zggz[n].dutyz);
			
			printf("��Ч����:\n");
			scanf("%f",&zggz[n].perz);
			
			zggz[n].shouldz = zggz[n].jobz + zggz[n].agesz + zggz[n].dutyz + zggz[n].perz;        //����Ӧ������
			
			zggz[n].tax = grsds(zggz[n].shouldz);                                                 //��������˰
			
			zggz[n].realz = zggz[n].shouldz - zggz[n].tax;                                        //����ʵ������
			
			printf("����Ϊ�����������Ϣ \n");
			
			printf("����: ");
			printf("%s\n",zggz[n].num);
			
			printf("����: ");
			printf("%s\n",zggz[n].name);
			
			printf("��λ����: ");
			printf("%.2f\n",zggz[n].jobz);
			
			printf("н������: ");
			printf("%.2f\n",zggz[n].agesz);
			
			printf("ְ�����: ");
			printf("%.2f\n",zggz[n].dutyz);
			
			printf("��Ч����: ");
			printf("%.2f\n",zggz[n].perz);                     // ����������Ϣ
			
			n++;                                // ÿ����������1
			
			int s;
			
			printf("========ȷ���Ƿ񱣴�? 1:��; 0:�� ==========\n");
			
			scanf("%d",&s);
			
			if (s == 1)
			{
				write();
			}
		}
	}
}
/*************************************************
 Function: list();
 Description: ��ʾȫ����Ϣ
 Calls: �� 
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ��
 Output: ��
 Return: �޷���ֵ
*************************************************/ 

void list()
{
    printf("����Ϊȫ��ְ������Ϣ\n");

    for(int i=0;i<n;i++)
      {
		  printf("--------------------------------------------------------------\n");
		  printf("����     ����    ��λ����   н������   ְ�����  \n");
		  printf("%s     %s    %.2f   %.2f    %.2f\n",zggz[i].num,zggz[i].name,zggz[i].jobz,zggz[i].agesz,zggz[i].dutyz);
		  printf("��Ч����   Ӧ������   ��������˰   ʵ������  \n");
		  printf("%.2f      %.2f        %.2f   %.2f\n",zggz[i].perz,zggz[i].shouldz,zggz[i].tax,zggz[i].realz);    
		  printf("--------------------------------------------------------------\n");
      }
  
}
/*************************************************
 Function: menu();
 Description: ��ʾ������Ϣ����,��ͨ��switchѡ��ִ�ж�Ӧ���
 Calls: list(),add(),del(),modify(),find(),write()
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����c1��ȡ�û������ֵ,ͨ��switchִ�ж�Ӧ����
 Output: ��
 Return: �޷���ֵ
*************************************************/
void menu()
{    
	printf("        ��������µ���ʾ�������������Ĺ���:         \n");
	printf("                       ===================================================\n");
	printf("                       |          1.��ѯְ�����ʼ�¼                      |\n");
	printf("                       |          2.�޸�ְ�����ʼ�¼                      |\n");
	printf("                       |          3.���ְ�����ʼ�¼                      |\n");
	printf("                       |          4.ɾ��ְ�����ʼ�¼                      |\n");
	printf("                       |          5.�������ݵ��ļ�                        |\n");
	printf("                       |          6.���ְ����¼                          |\n");
	printf("                       |          7.�˳��˵�,�����ϼ��˵�                 |\n");
	printf("                       ===================================================\n");
	printf("\n");

    int c1;

    scanf("%d",&c1);
    switch(c1)
	{
       case 1:
	      find();
	      break;

       case 2:
	      modify();
	      break;

       case 3:
	      add();
	      break;

       case 4:
	      del();
	      break;

       case 5:
	      write();
	      break;

       case 6:
	      list();
	      break;

       case 7:
	      break;
  }

}
/*************************************************
 Function: read();
 Description: ��ʾ������Ϣ����,��ͨ��switchѡ��ִ�ж�Ӧ���
 Calls: menu()
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����c��ȡ�û������ֵ,ͨ��switchִ�ж�Ӧ����
 Output: ��
 Return: �޷���ֵ
*************************************************/
void read()
{
    FILE *fp;
	
	if ((fp = fopen ("gx.dat","rb+")) == NULL)
	{
	   printf("���ļ�ʧ�ܣ�\n");

	   getch();

	   exit(-1);
	}
    else
	    printf("\n");

	while (!feof(fp))
	{
	   fscanf(fp,"%s %s %f %f %f %f %f %lf %lf\n",zggz[n].num,zggz[n].name,&zggz[n].jobz,&zggz[n].agesz,&zggz[n].dutyz,&zggz[n].perz,&zggz[n].shouldz,&zggz[n].tax,&zggz[n].realz);//�����ݴ������� 

	   n++;//��¼����
	}

	fclose(fp);//�ر��ļ�

	printf("                  ###   ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ   ###\n",n);
	printf("\n");

	while (1)
	{
	   printf("                       ===================================================\n");
	   printf("                       #             ����1����˵�                       #\n");
	   printf("                       #             ����0�˳�                           #\n");
	   printf("                       ===================================================\n");
	   int c;

	   scanf("%d",&c);

		switch (c)
		{

		    case 1:
			    menu();
				break;

		    case 0:
			    exit(-1);
			    break;
		}
	}
	
}
int main()
{
  read();

  return 0;
}