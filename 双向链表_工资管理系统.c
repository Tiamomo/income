/*************************************************
Copyright (C语言), 2018, Mango Tech. Co., Ltd.
 文件名: 工资管理.c
 Author:蒙世满(117583010128) Version:C语言&双向链表 Date:29,6,2018 
 Description: 
 I. 主要功能:()
 对职员的工资进行增删改减查询的操作,并保存到指定文件(gx.dat);
 II.函数对应的代码：
 1：查询find()；
 2：修改modify()；
 3：添加add()；
 4：删除del();
 5：保存write();
 6：浏览list();
 7：退出；
 III.结构体的数据：
   1.工号	字符数组	由1~10位数字（0~9）组成的字符串
   2.姓名	字符数组	由1~10个字母或1~5个汉字组成的字符串
   3.岗位工资	单精度实型	由不同工作岗位、如教师、实验室等确定的工资
   4.薪级工资	单精度实型	由工龄确定的工资
   5.职务津贴	单精度实型	由职务或职称确定的工资
   6.绩效工资	单精度实型	由业绩确定的工资
   7应发工资	单精度实型	前4项工资之和
   8.个人所得税	双精度实型	按照一定的比例计算
   9.实发工资	双精度实型	应发工资－个人所得税
   10.truct emp *prev          左结点
   11.struct emp *next         右结点
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
typedef struct emp
{
    char num[10];    // 工号

	char name[10];   // 姓名

	float jobz;      // 岗位工资

	float agesz;     // 薪级工资

	float dutyz;     // 职务津贴

	float perz;      // 绩效工资

	float shouldz;   // 应发工资

	double tax;      // 个人所得税

	double realz;    // 实发工资
    
	struct emp *prev; //左结点

	struct emp *next; //右结点

}node;

node zggz[50];

unsigned int len = sizeof(node);//记录结构体的长度

int k=0;//全局变量，进行文件读取时个数的记录

/*************************************************
 Function: grsds();
 Description: 计算个人所得税并返回到调用处
 Calls: 无
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 此函数从调用处获取值 "zggz[i].shouldz" 并赋值给形参 (float类型) ' v ',并定义参数 (double类型) ' ctax '保存最后计算的个人所得税 
 Output: 无输出
 Return: 返回值类型为double类型的"ctax".
 Others: 本函数对于负数的值,将直接返回0值;
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
 Description: 接受由主函数传过来的参数，根据需求创建一个双向链表，并返回该链表的头部；
 Calls: 无
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 根据提示依次输入对应结点的数据
 Output: 无
 Return: 返回值类型为node类型的指针.
*************************************************/ 
node* create(int n)
{
	node *head,*cur,*prev;
   
    if ((head = (node *)malloc(len)) == NULL)
	{
		printf("获取空间失败！！请重试！\n");

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
    head->next=NULL;//对创建的表头部进行初始化

    prev = head;

   for(n;n>=1;n--)
   {
        if ((cur = (node *)malloc(len)) == NULL)
		{
             printf("获取空间失败！！请重试！\n");

	         return NULL;
		}

		 prev->next=cur;

		 printf("请输入员工信息 \n");
	
	     printf("工号:\n");
	     scanf("%s",cur->num);

	     printf("姓名:\n");
	     scanf("%s",cur->name);
	   
	     printf("岗位工资:\n");
	     scanf("%f",&cur->jobz);

	     printf("薪级工资:\n");
	     scanf("%f",&cur->agesz);
	   
	     printf("职务津贴:\n");
	     scanf("%f",&cur->dutyz);
	   
	     printf("绩效工资:\n");
	     scanf("%f",&cur->perz);

	     cur->shouldz = cur->jobz + cur->agesz + cur->dutyz + cur->perz;        //计算应发工资
	
	     cur->tax = grsds(cur->shouldz);                                                 //计算所得税
	
	     cur->realz = cur->shouldz - cur->tax;                                        //计算实发工资

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
 Description: 通过创建新的双向链表，进行文件中数据的读取，并返回该链表的头部。在读取文件通过stat函数进行文件字节数的读取，以便后面建立链表时候进行结构体个数的计算
 Calls: fopen()、fclose();
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 无输入
 Output: 无
 Return: 返回链表的头部（结构体node类型）
*************************************************/
node *read()
{
    FILE *fp;
    int i;
	node *head,*cur,*prev;
	
	if ((fp = fopen ("gx.dat","rb+")) == NULL)
	{
	   printf("打开文件失败！\n");

	   getch();

	   exit(-1);
	}
    else
	    printf("成功！！ \n");

	while (!feof(fp))
	{
	   fscanf(fp,"%s %s %f %f %f %f %f %lf %lf\n",zggz[k].num,zggz[k].name,&zggz[k].jobz,&zggz[k].agesz,&zggz[k].dutyz,&zggz[k].perz,&zggz[k].shouldz,&zggz[k].tax,&zggz[k].realz);//将数据存入数组 

	   k++;//记录人数
	}

	if ((head = (node *)malloc(len))==NULL)
	{
        printf("获取空间失败！！请重试！\n");
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
   head->next=NULL;//对创建的表头部进行初始化

   prev = head;

  for(i = 0;i < k; i++)
  {
       if ((cur = (node *)malloc(len))==NULL)
	   {
           printf("获取空间失败！！请重试！\n");

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
	   
	  // printf("工号 %s",cur->num);
  }

    prev->next=head;

    head->prev=cur;

    printf("目前人数为%d\n",k);

	fclose(fp);//关闭文件

	return head;
 

}
/*************************************************
 Function: write();
 Description: 本函数将传过来的链表全部写进文件"gx.dat"里面,此函数采用C语言格式进行文件的写入
 Calls: fpoen()、fclose();
 Called By:无
 Table Accessed: 无
 Table Updated: 无
 Input: 无输入
 Output: 无
 Return: 无返回值
*************************************************/ 
void write(node *head)
{
	FILE *fp;

	node *cur5;

    cur5=head->next;
	
	if ((fp = fopen ("gx.dat","wb+")) == NULL)
	{
	   printf("打开文件失败！\n");

	   getch();

	   exit(-1);
	}
    else
	    printf("打开成功！！ \n");

	while(cur5!=head)
		 {
		       fprintf(fp,"%s %s %.2f %.2f %.2f %.2f %.2f %.2lf %.2lf",cur5->num,cur5->name,cur5->jobz,cur5->agesz,cur5->dutyz,cur5->perz,cur5->shouldz,cur5->tax,cur5->realz);//讲双向链表写入文件

	           fprintf(fp,"\n");

			   cur5=cur5->next;

		  }
   printf("保存成功  ！！！\n");

   fclose(fp);        //文件关闭
}
/*************************************************
 Function: add()
 Description: 首先接受由主函数传过来的链表头部，在链表尾部进行增加,后通过改变前中后的prev/next实现增加
 Calls: write()，grsds();
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 根据提示依次输入信息数据，定义's'实现是否确定保存的功能
 Output: 无
 Return: 无返回值
 Others: 该函数将显示您所填的信息
*************************************************/
void add(node *head)
{
   
   node *add;
   int s;

   if ((add = (node *)malloc(len))==NULL)
		{
             printf("获取空间失败！！请重试！\n");
	         exit(-1);
		}

         printf("请输入全部信息 \n");

	     printf("工号:\n");
	     scanf("%s",add->num);

	     printf("姓名:\n");
	     scanf("%s",add->name);
	   
	     printf("岗位工资:\n");
	     scanf("%f",&add->jobz);

	     printf("薪级工资:\n");
	     scanf("%f",&add->agesz);
	   
	     printf("职务津贴:\n");
	     scanf("%f",&add->dutyz);
	   
	     printf("绩效工资:\n");
	     scanf("%f",&add->perz);

	     add->shouldz = add->jobz + add->agesz + add->dutyz + add->perz;        //计算应发工资
	
	     add->tax = grsds(add->shouldz);                                                 //计算所得税
	
	     add->realz = add->shouldz - add->tax;                                        //计算实发工资

	     printf("以下为您所输入的信息 \n");

	     printf("工号: ");
	     printf("%s\n",add->num);

	     printf("姓名: ");
	     printf("%s\n",add->name);
	   
	     printf("岗位工资: ");
	     printf("%.2f\n",add->jobz);

	     printf("薪级工资: ");
	     printf("%.2f\n",add->agesz);
	   
	     printf("职务津贴: ");
	     printf("%.2f\n",add->dutyz);
	   
	     printf("绩效工资: ");
	     printf("%.2f\n",add->perz);

		 head->prev->next=add;
		 add->prev=head->prev;//实现与尾部结点的连接

		 head->prev=add;
		 add->next=head;//实现与head头部的连接 

		 printf("是否保存？1是，0否\n");

	     scanf("%d",&s);

	     if (s==1)
		 {
	         write(head);
		 }

}
/*************************************************
 Function: del();
 Description: 首先接受由主函数传过来的链表头部，然后进行查找到后进行删除对应目标的人员
 Calls: write()
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义gonghao字符数组记录目标工号值,定义'c4'实现是否确定删除的功能，“s”实现是否确定保存的功能,定义j记录当前结点数,并判断是否存在该成员
 Output: 无
 Return: 无返回值
 Others: 该函数实现方法为,通过循坏语句找到相应目标人员，后通过改变前中后的prev/next实现删除，并在最后释放空间
*************************************************/ 
void del(node *head,int n)
{
    node *cur4;

    int i,j=101;

    char gonghao[10];

    cur4=head->next;

    printf("===请输入所要删除的工号 \n");

    scanf("%s",gonghao);

    for(i=0;i<n;i++)
	{
	   int c4,s;

       if (strcmp(gonghao,cur4->num) == 0)
	   {         
          j=i;

          printf("是否确认删除？1是0否\n");

		  scanf("%d",&c4);

		  if(c4==1)
		  {
		      cur4->prev->next=cur4->next;

			  cur4->next->prev=cur4->prev;//cur3,cur4,cur5例子

			  free(cur4);
		  }
		 
	   }
	   else
		   cur4=cur4->next;
       
	  
	   printf("是否保存？1是，0否\n");

	   scanf("%d",&s);

	   if(s==1)
	   {
	       write(head);
	   }


  }
  if(j==101)
	   {
	       printf("无此工号，请确认是否正确！！！");
	   
	   }

}
/*************************************************
 Function: modify();
 Description: 首先接受由主函数传过来的链表头部，检索并匹配到工号对应的结构体进行修改并实现保存
 Calls: 调用了write()保存函数
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义'i','j'进行循环的检索并记录目标的位置,定义's'实现是否确定保存的功能
 Output: 无
 Return: 无
 Others: 该函数将会提示您所修改的信息
*************************************************/ 
void modify(node *head,int n)
{
    node *cur3;

    int i,j = 101, s;

    char gonghao[10];

    cur3=head->next;

    printf("===请输入所要修改的工号=== \n");

    scanf("%s",gonghao);

    for (i=0;i<n;i++)
	{
       if (strcmp(gonghao,cur3->num) == 0)
	   {         
          j=i;
		  
		  printf("请重新输入该员工的基本信息！！\n");

		  printf("工号:\n");
	      scanf("%s",cur3->num);

	      printf("姓名:\n");
	      scanf("%s",cur3->name);
	   
	      printf("岗位工资:\n");
	      scanf("%f",&cur3->jobz);

	      printf("薪级工资:\n");
	      scanf("%f",&cur3->agesz);
	   
	      printf("职务津贴:\n");
	      scanf("%f",&cur3->dutyz);
	   
	      printf("绩效工资:\n");
	      scanf("%f",&cur3->perz);
	 	
	      cur3->shouldz = cur3->jobz+cur3->agesz+cur3->dutyz+cur3->perz;//计算应发工资

	      cur3->tax = grsds(cur3->shouldz);                                   //计算所得税
	
	      cur3->realz = cur3->shouldz - cur3->tax;                            //计算实发工资

          printf("以下是您所修改的信息\n");

          printf("工号: ");
	      printf("%s\n",cur3->num);

	      printf("姓名: ");
	      printf("%s\n",cur3->name);
	   
	      printf("岗位工资: ");
	      printf("%.2f\n",cur3->jobz);

	      printf("薪级工资: ");
	      printf("%.2f\n",cur3->agesz);
	   
	      printf("职务津贴: ");
	      printf("%.2f\n",cur3->dutyz);
	   
	      printf("绩效工资: ");
	      printf("%.2f\n",cur3->perz);
	   }

	   else
		   cur3=cur3->next;
  }

  if(j==101)
	   {
	       printf("无此工号，请确认是否正确！！！");
	   
	   }

       printf("是否保存？1是，0否\n");

	   scanf("%d",&s);

	   if(s==1)
	   {
	   
	      write(head);
	   }


}
/*************************************************
 Function: find();
 Description: 首先接受由主函数传过来的链表头部，查询并显示目标人员信息
 Calls: 无 
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义gonghao字符数组记录目标工号值,并通过循环语句找到目标后进行输出
 Output: 无
 Return: 无返回值
*************************************************/ 
void find(node *head,int n)
{
     node *cur2;
     int i,j=101;
     char gonghao[10];
     cur2=head->next;
     printf("===请输入所要查找的工号 \n");
     scanf("%s",gonghao);
     for(i=0;i<n;i++)
	 {
         if(strcmp(gonghao,cur2->num)==0)
		 {
		     printf("====一下是您所要查找成员的工号信息=====\n");
	         printf("工号:\n");
	         printf("%s\n",cur2->num);

	         printf("姓名:\n");
	         printf("%s\n",cur2->name);
	   
	         printf("岗位工资:\n");
	         printf("%.2f\n",cur2->jobz);

	         printf("薪级工资:\n");
	         printf("%.2f\n",cur2->agesz);
	   
	         printf("职务津贴:\n");
	         printf("%.2f\n",cur2->dutyz);
	   
	         printf("绩效工资:\n");
	         printf("%.2f\n",cur2->perz);
	  
	         printf("应发工资:\n");
	         printf("%.2f\n",cur2->shouldz);
	   
	         printf("个人所得税:\n");
	         printf("%.2lf\n",cur2->tax);
	  
	         printf("实发工资:\n");
	         printf("%.2lf\n",cur2->realz);
          
             j=i;
		 
	   }
	   else
		   cur2=cur2->next;	   
  
  }
  if(j==101)
	   {
	       printf("无此工号，请确认是否正确！！！");
	   
	   }

}
/*************************************************
 Function: list();
 Description: 首先接受由主函数传过来的链表头部，显示全部信息
 Calls: 无 
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 无
 Output: 无
 Return: 无返回值
*************************************************/
void list(node *head)
{
   node *cur1;

   cur1=head->next;//The first node

   while(cur1 != head)
   {
          printf("--------------------------------------------------------------\n");
          printf("工号     姓名    岗位工资   薪级工资   职务津贴  \n");
		  printf("%s     %s    %.2f   %.2f    %.2f\n",cur1->num,cur1->name,cur1->jobz,cur1->agesz,cur1->dutyz);

	      printf("绩效工资   应发工资   个人所得税   实发工资  \n");
	      printf("%.2f      %.2f        %.2f   %.2f\n",cur1->perz,cur1->shouldz,cur1->tax,cur1->realz);
	      
		  printf("--------------------------------------------------------------\n");

		  cur1=cur1->next;
   
   }
   
}



int main()
{
	int c,n,c1;
	node *head;

    printf("=====是否创建链表进行人员输入，若确定请输入1后输入想要的结点个数，否则为0进行文件的扫描读取链表====\n");

    scanf("%d",&c);
	

	if(c==1)
	{
		printf("请输入所需要的链表大小\n");
	
		scanf("%d",&n);

	    head=create(n);
		while(1)
		{
		   printf("        《--------请根据以下的提示序号输入您所需的功能---------》》        \n");
           printf("        《--------1为查询，2为修改，3为添加，4为删除-----------》》        \n");
           printf("        《--------5为保存，6为浏览，7为退出-----------》》       \n");
           printf("\n");

           scanf("%d",&c1);

           switch(c1)
		   {
               case 1:
	             find(head,k);//查询
	             break;

              case 2:
	             modify(head,k); //修改
	             break;

              case 3:
	             add(head);     //增加
	             break;

              case 4:
	             del(head,k);	   //删除
	             break;

              case 5:
	             write(head);	   //保存
	             break;

             case 6:
	            list(head);
	            break;

             case 7:
				 exit(-1);
	            break;		//浏览
		   }

		
		}
	}
	      
	else
	{
		head=read();//获取链表

		while(1)
		{
		   printf("        《--------请根据以下的提示序号输入您所需的功能---------》》        \n");
           printf("        《--------1为查询，2为修改，3为添加，4为删除-----------》》        \n");
           printf("        《--------5为保存，6为浏览，7为退出并返回上级-----------》》       \n");
           printf("\n");

           scanf("%d",&c1);

           switch(c1)
		   {
               case 1:
	             find(head,k);//查询
	             break;

              case 2:
	             modify(head,k); //修改
	             break;

              case 3:
	             add(head);     //增加
	             break;

              case 4:
	             del(head,k);	   //删除
	             break;

              case 5:
	             write(head);	   //保存
	             break;

             case 6:
	            list(head);
	            break;

             case 7:
				 exit(-1);
	            break;		//浏览
		   }

		
		}
	
	
	}
	   
		return 0;


}
