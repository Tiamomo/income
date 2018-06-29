/*************************************************
Copyright (C����), 2018, Mango Tech. Co., Ltd.
 �ļ���: ���ʹ���.c
 Author:������(117583010128) Version:C����&˫������ Date:29,6,2018 
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
   10.truct emp *prev          ����
   11.struct emp *next         �ҽ��
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
typedef struct emp
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
    
	struct emp *prev; //����

	struct emp *next; //�ҽ��

}node;

node zggz[50];

unsigned int len = sizeof(node);//��¼�ṹ��ĳ���

int k=0;//ȫ�ֱ����������ļ���ȡʱ�����ļ�¼

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
 Function: create();
 Description: �������������������Ĳ������������󴴽�һ��˫�����������ظ������ͷ����
 Calls: ��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ������ʾ���������Ӧ��������
 Output: ��
 Return: ����ֵ����Ϊnode���͵�ָ��.
*************************************************/ 
node* create(int n)
{
	node *head,*cur,*prev;
   
    if ((head = (node *)malloc(len)) == NULL)
	{
		printf("��ȡ�ռ�ʧ�ܣ��������ԣ�\n");

	    return NULL;
    }
   
    head->num[0]='k';
    head->name[0]='j';
    head->jobz=0;
    head->agesz=0;
    head->dutyz=0;
    head->perz=0;
    head->shouldz=0;
    head->tax=0;
    head->realz=0;
    head->prev=NULL;
    head->next=NULL;//�Դ����ı�ͷ�����г�ʼ��

    prev = head;

   for(n;n>=1;n--)
   {
        if ((cur = (node *)malloc(len)) == NULL)
		{
             printf("��ȡ�ռ�ʧ�ܣ��������ԣ�\n");

	         return NULL;
		}

		 prev->next=cur;

		 printf("������Ա����Ϣ \n");
	
	     printf("����:\n");
	     scanf("%s",cur->num);

	     printf("����:\n");
	     scanf("%s",cur->name);
	   
	     printf("��λ����:\n");
	     scanf("%f",&cur->jobz);

	     printf("н������:\n");
	     scanf("%f",&cur->agesz);
	   
	     printf("ְ�����:\n");
	     scanf("%f",&cur->dutyz);
	   
	     printf("��Ч����:\n");
	     scanf("%f",&cur->perz);

	     cur->shouldz = cur->jobz + cur->agesz + cur->dutyz + cur->perz;        //����Ӧ������
	
	     cur->tax = grsds(cur->shouldz);                                                 //��������˰
	
	     cur->realz = cur->shouldz - cur->tax;                                        //����ʵ������

		 cur->prev=prev;

		 cur->next=NULL;

		 prev=cur;
   
   }

   prev->next=head;

   head->prev=cur;

   return head;
   
}
/*************************************************
 Function: read();
 Description: ͨ�������µ�˫�����������ļ������ݵĶ�ȡ�������ظ������ͷ�����ڶ�ȡ�ļ�ͨ��stat���������ļ��ֽ����Ķ�ȡ���Ա���潨������ʱ����нṹ������ļ���
 Calls: fopen()��fclose();
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ������
 Output: ��
 Return: ���������ͷ�����ṹ��node���ͣ�
*************************************************/
node *read()
{
    FILE *fp;
    int i;
	node *head,*cur,*prev;
	
	if ((fp = fopen ("gx.dat","rb+")) == NULL)
	{
	   printf("���ļ�ʧ�ܣ�\n");

	   getch();

	   exit(-1);
	}
    else
	    printf("�ɹ����� \n");

	while (!feof(fp))
	{
	   fscanf(fp,"%s %s %f %f %f %f %f %lf %lf\n",zggz[k].num,zggz[k].name,&zggz[k].jobz,&zggz[k].agesz,&zggz[k].dutyz,&zggz[k].perz,&zggz[k].shouldz,&zggz[k].tax,&zggz[k].realz);//�����ݴ������� 

	   k++;//��¼����
	}

	if ((head = (node *)malloc(len))==NULL)
	{
        printf("��ȡ�ռ�ʧ�ܣ��������ԣ�\n");
	    exit(-1);
    }
   
   head->num[0]='k';
   head->name[0]='j';
   head->jobz=0;
   head->agesz=0;
   head->dutyz=0;
   head->perz=0;
   head->shouldz=0;
   head->tax=0;
   head->realz=0;
   head->prev=NULL;
   head->next=NULL;//�Դ����ı�ͷ�����г�ʼ��

   prev = head;

  for(i = 0;i < k; i++)
  {
       if ((cur = (node *)malloc(len))==NULL)
	   {
           printf("��ȡ�ռ�ʧ�ܣ��������ԣ�\n");

	       exit(-1);
	   }

	   prev->next=cur;

	   strcpy(cur->num,zggz[i].num);
	   strcpy(cur->name,zggz[i].name);
	   cur->jobz=zggz[i].jobz;
	   cur->agesz=zggz[i].agesz;
	   cur->dutyz=zggz[i].dutyz;
	   cur->perz=zggz[i].perz;
	   cur->shouldz=zggz[i].shouldz;
	   cur->tax=zggz[i].shouldz;
	   cur->realz=zggz[i].realz;
       
       //cur=cur->next;
       
	   cur->prev=prev;

	   cur->next=NULL;

	   prev=cur;
	   
	  // printf("���� %s",cur->num);
  }

    prev->next=head;

    head->prev=cur;

    printf("Ŀǰ����Ϊ%d\n",k);

	fclose(fp);//�ر��ļ�

	return head;
 

}
/*************************************************
 Function: write();
 Description: ��������������������ȫ��д���ļ�"gx.dat"����,�˺�������C���Ը�ʽ�����ļ���д��
 Calls: fpoen()��fclose();
 Called By:��
 Table Accessed: ��
 Table Updated: ��
 Input: ������
 Output: ��
 Return: �޷���ֵ
*************************************************/ 
void write(node *head)
{
	FILE *fp;

	node *cur5;

    cur5=head->next;
	
	if ((fp = fopen ("gx.dat","wb+")) == NULL)
	{
	   printf("���ļ�ʧ�ܣ�\n");

	   getch();

	   exit(-1);
	}
    else
	    printf("�򿪳ɹ����� \n");

	while(cur5!=head)
		 {
		       fprintf(fp,"%s %s %.2f %.2f %.2f %.2f %.2f %.2lf %.2lf",cur5->num,cur5->name,cur5->jobz,cur5->agesz,cur5->dutyz,cur5->perz,cur5->shouldz,cur5->tax,cur5->realz);//��˫������д���ļ�

	           fprintf(fp,"\n");

			   cur5=cur5->next;

		  }
   printf("����ɹ�  ������\n");

   fclose(fp);        //�ļ��ر�
}
/*************************************************
 Function: add()
 Description: ���Ƚ�����������������������ͷ����������β����������,��ͨ���ı�ǰ�к��prev/nextʵ������
 Calls: write()��grsds();
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ������ʾ����������Ϣ���ݣ�����'s'ʵ���Ƿ�ȷ������Ĺ���
 Output: ��
 Return: �޷���ֵ
 Others: �ú�������ʾ���������Ϣ
*************************************************/
void add(node *head)
{
   
   node *add;
   int s;

   if ((add = (node *)malloc(len))==NULL)
		{
             printf("��ȡ�ռ�ʧ�ܣ��������ԣ�\n");
	         exit(-1);
		}

         printf("������ȫ����Ϣ \n");

	     printf("����:\n");
	     scanf("%s",add->num);

	     printf("����:\n");
	     scanf("%s",add->name);
	   
	     printf("��λ����:\n");
	     scanf("%f",&add->jobz);

	     printf("н������:\n");
	     scanf("%f",&add->agesz);
	   
	     printf("ְ�����:\n");
	     scanf("%f",&add->dutyz);
	   
	     printf("��Ч����:\n");
	     scanf("%f",&add->perz);

	     add->shouldz = add->jobz + add->agesz + add->dutyz + add->perz;        //����Ӧ������
	
	     add->tax = grsds(add->shouldz);                                                 //��������˰
	
	     add->realz = add->shouldz - add->tax;                                        //����ʵ������

	     printf("����Ϊ�����������Ϣ \n");

	     printf("����: ");
	     printf("%s\n",add->num);

	     printf("����: ");
	     printf("%s\n",add->name);
	   
	     printf("��λ����: ");
	     printf("%.2f\n",add->jobz);

	     printf("н������: ");
	     printf("%.2f\n",add->agesz);
	   
	     printf("ְ�����: ");
	     printf("%.2f\n",add->dutyz);
	   
	     printf("��Ч����: ");
	     printf("%.2f\n",add->perz);

		 head->prev->next=add;
		 add->prev=head->prev;//ʵ����β����������

		 head->prev=add;
		 add->next=head;//ʵ����headͷ�������� 

		 printf("�Ƿ񱣴棿1�ǣ�0��\n");

	     scanf("%d",&s);

	     if (s==1)
		 {
	         write(head);
		 }

}
/*************************************************
 Function: del();
 Description: ���Ƚ�����������������������ͷ����Ȼ����в��ҵ������ɾ����ӦĿ�����Ա
 Calls: write()
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����gonghao�ַ������¼Ŀ�깤��ֵ,����'c4'ʵ���Ƿ�ȷ��ɾ���Ĺ��ܣ���s��ʵ���Ƿ�ȷ������Ĺ���,����j��¼��ǰ�����,���ж��Ƿ���ڸó�Ա
 Output: ��
 Return: �޷���ֵ
 Others: �ú���ʵ�ַ���Ϊ,ͨ��ѭ������ҵ���ӦĿ����Ա����ͨ���ı�ǰ�к��prev/nextʵ��ɾ������������ͷſռ�
*************************************************/ 
void del(node *head,int n)
{
    node *cur4;

    int i,j=101;

    char gonghao[10];

    cur4=head->next;

    printf("===��������Ҫɾ���Ĺ��� \n");

    scanf("%s",gonghao);

    for(i=0;i<n;i++)
	{
	   int c4,s;

       if (strcmp(gonghao,cur4->num) == 0)
	   {         
          j=i;

          printf("�Ƿ�ȷ��ɾ����1��0��\n");

		  scanf("%d",&c4);

		  if(c4==1)
		  {
		      cur4->prev->next=cur4->next;

			  cur4->next->prev=cur4->prev;//cur3,cur4,cur5����

			  free(cur4);
		  }
		 
	   }
	   else
		   cur4=cur4->next;
       
	  
	   printf("�Ƿ񱣴棿1�ǣ�0��\n");

	   scanf("%d",&s);

	   if(s==1)
	   {
	       write(head);
	   }


  }
  if(j==101)
	   {
	       printf("�޴˹��ţ���ȷ���Ƿ���ȷ������");
	   
	   }

}
/*************************************************
 Function: modify();
 Description: ���Ƚ�����������������������ͷ����������ƥ�䵽���Ŷ�Ӧ�Ľṹ������޸Ĳ�ʵ�ֱ���
 Calls: ������write()���溯��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����'i','j'����ѭ���ļ�������¼Ŀ���λ��,����'s'ʵ���Ƿ�ȷ������Ĺ���
 Output: ��
 Return: ��
 Others: �ú���������ʾ�����޸ĵ���Ϣ
*************************************************/ 
void modify(node *head,int n)
{
    node *cur3;

    int i,j = 101, s;

    char gonghao[10];

    cur3=head->next;

    printf("===��������Ҫ�޸ĵĹ���=== \n");

    scanf("%s",gonghao);

    for (i=0;i<n;i++)
	{
       if (strcmp(gonghao,cur3->num) == 0)
	   {         
          j=i;
		  
		  printf("�����������Ա���Ļ�����Ϣ����\n");

		  printf("����:\n");
	      scanf("%s",cur3->num);

	      printf("����:\n");
	      scanf("%s",cur3->name);
	   
	      printf("��λ����:\n");
	      scanf("%f",&cur3->jobz);

	      printf("н������:\n");
	      scanf("%f",&cur3->agesz);
	   
	      printf("ְ�����:\n");
	      scanf("%f",&cur3->dutyz);
	   
	      printf("��Ч����:\n");
	      scanf("%f",&cur3->perz);
	 	
	      cur3->shouldz = cur3->jobz+cur3->agesz+cur3->dutyz+cur3->perz;//����Ӧ������

	      cur3->tax = grsds(cur3->shouldz);                                   //��������˰
	
	      cur3->realz = cur3->shouldz - cur3->tax;                            //����ʵ������

          printf("�����������޸ĵ���Ϣ\n");

          printf("����: ");
	      printf("%s\n",cur3->num);

	      printf("����: ");
	      printf("%s\n",cur3->name);
	   
	      printf("��λ����: ");
	      printf("%.2f\n",cur3->jobz);

	      printf("н������: ");
	      printf("%.2f\n",cur3->agesz);
	   
	      printf("ְ�����: ");
	      printf("%.2f\n",cur3->dutyz);
	   
	      printf("��Ч����: ");
	      printf("%.2f\n",cur3->perz);
	   }

	   else
		   cur3=cur3->next;
  }

  if(j==101)
	   {
	       printf("�޴˹��ţ���ȷ���Ƿ���ȷ������");
	   
	   }

       printf("�Ƿ񱣴棿1�ǣ�0��\n");

	   scanf("%d",&s);

	   if(s==1)
	   {
	   
	      write(head);
	   }


}
/*************************************************
 Function: find();
 Description: ���Ƚ�����������������������ͷ������ѯ����ʾĿ����Ա��Ϣ
 Calls: �� 
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����gonghao�ַ������¼Ŀ�깤��ֵ,��ͨ��ѭ������ҵ�Ŀ���������
 Output: ��
 Return: �޷���ֵ
*************************************************/ 
void find(node *head,int n)
{
     node *cur2;
     int i,j=101;
     char gonghao[10];
     cur2=head->next;
     printf("===��������Ҫ���ҵĹ��� \n");
     scanf("%s",gonghao);
     for(i=0;i<n;i++)
	 {
         if(strcmp(gonghao,cur2->num)==0)
		 {
		     printf("====һ��������Ҫ���ҳ�Ա�Ĺ�����Ϣ=====\n");
	         printf("����:\n");
	         printf("%s\n",cur2->num);

	         printf("����:\n");
	         printf("%s\n",cur2->name);
	   
	         printf("��λ����:\n");
	         printf("%.2f\n",cur2->jobz);

	         printf("н������:\n");
	         printf("%.2f\n",cur2->agesz);
	   
	         printf("ְ�����:\n");
	         printf("%.2f\n",cur2->dutyz);
	   
	         printf("��Ч����:\n");
	         printf("%.2f\n",cur2->perz);
	  
	         printf("Ӧ������:\n");
	         printf("%.2f\n",cur2->shouldz);
	   
	         printf("��������˰:\n");
	         printf("%.2lf\n",cur2->tax);
	  
	         printf("ʵ������:\n");
	         printf("%.2lf\n",cur2->realz);
          
             j=i;
		 
	   }
	   else
		   cur2=cur2->next;	   
  
  }
  if(j==101)
	   {
	       printf("�޴˹��ţ���ȷ���Ƿ���ȷ������");
	   
	   }

}
/*************************************************
 Function: list();
 Description: ���Ƚ�����������������������ͷ������ʾȫ����Ϣ
 Calls: �� 
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ��
 Output: ��
 Return: �޷���ֵ
*************************************************/
void list(node *head)
{
   node *cur1;

   cur1=head->next;//The first node

   while(cur1 != head)
   {
          printf("--------------------------------------------------------------\n");
          printf("����     ����    ��λ����   н������   ְ�����  \n");
		  printf("%s     %s    %.2f   %.2f    %.2f\n",cur1->num,cur1->name,cur1->jobz,cur1->agesz,cur1->dutyz);

	      printf("��Ч����   Ӧ������   ��������˰   ʵ������  \n");
	      printf("%.2f      %.2f        %.2f   %.2f\n",cur1->perz,cur1->shouldz,cur1->tax,cur1->realz);
	      
		  printf("--------------------------------------------------------------\n");

		  cur1=cur1->next;
   
   }
   
}



int main()
{
	int c,n,c1;
	node *head;

    printf("=====�Ƿ񴴽����������Ա���룬��ȷ��������1��������Ҫ�Ľ�����������Ϊ0�����ļ���ɨ���ȡ����====\n");

    scanf("%d",&c);
	

	if(c==1)
	{
		printf("����������Ҫ�������С\n");
	
		scanf("%d",&n);

	    head=create(n);
		while(1)
		{
		   printf("        ��--------��������µ���ʾ�������������Ĺ���---------����        \n");
           printf("        ��--------1Ϊ��ѯ��2Ϊ�޸ģ�3Ϊ��ӣ�4Ϊɾ��-----------����        \n");
           printf("        ��--------5Ϊ���棬6Ϊ�����7Ϊ�˳�-----------����       \n");
           printf("\n");

           scanf("%d",&c1);

           switch(c1)
		   {
               case 1:
	             find(head,k);//��ѯ
	             break;

              case 2:
	             modify(head,k); //�޸�
	             break;

              case 3:
	             add(head);     //����
	             break;

              case 4:
	             del(head,k);	   //ɾ��
	             break;

              case 5:
	             write(head);	   //����
	             break;

             case 6:
	            list(head);
	            break;

             case 7:
				 exit(-1);
	            break;		//���
		   }

		
		}
	}
	      
	else
	{
		head=read();//��ȡ����

		while(1)
		{
		   printf("        ��--------��������µ���ʾ�������������Ĺ���---------����        \n");
           printf("        ��--------1Ϊ��ѯ��2Ϊ�޸ģ�3Ϊ��ӣ�4Ϊɾ��-----------����        \n");
           printf("        ��--------5Ϊ���棬6Ϊ�����7Ϊ�˳��������ϼ�-----------����       \n");
           printf("\n");

           scanf("%d",&c1);

           switch(c1)
		   {
               case 1:
	             find(head,k);//��ѯ
	             break;

              case 2:
	             modify(head,k); //�޸�
	             break;

              case 3:
	             add(head);     //����
	             break;

              case 4:
	             del(head,k);	   //ɾ��
	             break;

              case 5:
	             write(head);	   //����
	             break;

             case 6:
	            list(head);
	            break;

             case 7:
				 exit(-1);
	            break;		//���
		   }

		
		}
	
	
	}
	   
		return 0;


}
