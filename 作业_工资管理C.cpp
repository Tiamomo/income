/*************************************************
Copyright (C语言), 2018, Mango Tech. Co., Ltd.
 文件名: 工资管理.c
 Author:蒙世满(117583010128) Version:C语言 Date:26,6,2018 
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
*************************************************/
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct emploees
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

} zggz[50];


int n=0;   // 全局变量,记录人员数

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
 Function: write();
 Description: 本函数将数组zggz全部写进文件"gx.dat"里面,此函数采用C语言格式进行文件的写入
 Calls: 无
 Called By:无
 Table Accessed: 无
 Table Updated: 无
 Input: 本函数定义一个整型'j'记录全局变量'n'的值,采用进行文件的写入
 Output: 无
 Return: 无返回值
*************************************************/ 
void write()
{
    printf("目前人数为%d\n",n);

	int j = n;

    if (j > 0 && j < 50)
	{
		 FILE *fp2;
	
	     if ((fp2 = fopen ("gx.dat","wb+")) == NULL)
	      {
	           printf("打开文件失败\n");

	           getch();

	           exit(-1);
	      }
    else
	     printf("打开成功！！正在保存  ");
		 
		 for (int i=0;i<n;i++)
		 {
		       fprintf(fp2,"%s %s %.2f %.2f %.2f %.2f %.2f %.2lf %.2lf",zggz[i].num,zggz[i].name,zggz[i].jobz,zggz[i].agesz,zggz[i].dutyz,zggz[i].perz,zggz[i].shouldz,zggz[i].tax,zggz[i].realz);//将数组写入文件 
	           fprintf(fp2,"\n");
		  }
		  printf("保存完成！\n");

		  fclose(fp2);//关闭文件

      }          //  重新全部录入文件

  else
	  if(j==0)
	  {
		    FILE *fp2;
	
	        if ((fp2 = fopen ("gd.dat","rb+")) == NULL)
	          {
	              printf("打开文件失败\n");

	              getch();

			      exit(-1);
			  }
	  
           else
	           {
				   printf("打开成功！！正在保存\n");

				   fprintf(fp2,"%s %s %s %s %s %s %s %s %s"," "," "," "," "," "," "," "," "," "); 

	               fprintf(fp2,"\n");

				    printf("保存完成！\n");

				   fclose(fp2);//关闭文件
			   }
      }

	  else
               printf("无记录！！！\n");
	  
}

//查询函数1
void find()
{
   char gonghao[10];

   int i=0,j=101;

   printf("请输入工号 \n");

   scanf("%s",gonghao);

   for (;i<n;i++)
	   if (strcmp(gonghao,zggz[i].num)==0)
		   j=i;
   if (j == 101)
   {
     printf("无此员工！！请确认工号是否正确！！\n");
   }
   else
   {   
	   printf("工号:\n");
	   printf("%s\n",zggz[j].num);

	   printf("姓名:\n");
	   printf("%s\n",zggz[j].name);
	   
	   printf("岗位工资:\n");
	   printf("%.2f\n",zggz[j].jobz);

	   printf("薪级工资:\n");
	   printf("%.2f\n",zggz[j].agesz);
	   
	   printf("职务津贴:\n");
	   printf("%.2f\n",zggz[j].dutyz);
	   
	   printf("绩效工资:\n");
	   printf("%.2f\n",zggz[j].perz);
	  
	   printf("应发工资:\n");
	   printf("%.2f\n",zggz[j].shouldz);
	   
	   printf("个人所得税:\n");
	   printf("%.2lf\n",zggz[j].tax);
	  
	   printf("实发工资:\n");
	   printf("%.2lf\n",zggz[j].realz);
	  
	
   }
   
}
/*************************************************
 Function: modify();
 Description: 检索并匹配到工号对应的结构体进行修改并实现保存
 Calls: 调用了write()保存函数
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义'i','j'进行循环的检索并记录目标的位置,定义's'实现是否确定保存的功能
 Output: 无
 Return: 无
 Others: 该函数将会提示您所修改的信息
*************************************************/ 
void modify()
{
	//cout<<n<<endl;
	char gonghao[10];

    int i = 0,j = 101;

   cout<<"请输入要修改的工号"<<endl;

   cin >> gonghao;

   for (;i < n; i++)
   {
	   if(strcmp(gonghao,zggz[i].num) == 0)
	   {
		   j = i;
	   }
   }
              //按照工号依次查找
   if (j == 101)
   {
      cout<<"查无此人，请再次确认工号是否正确"<<endl;
   }
   else
   {
	   cout<<"请重新录入基本信息 "<<endl;
	   cout<<"工号 "<<endl;
	   cin>>zggz[j].num;
	   cout<<"姓名 "<<endl;
	   cin>>zggz[j].name;
	   cout<<"岗位工资 "<<endl;
	   cin>>zggz[j].jobz;
	   cout<<"薪级工资 "<<endl;
	   cin>>zggz[j].agesz;
	   cout<<"职务津贴 "<<endl;
	   cin>>zggz[j].dutyz;
	   cout<<"绩效工资 "<<endl;
	   cin>>zggz[j].perz;
	
	   zggz[j].shouldz = zggz[j].jobz+zggz[j].agesz+zggz[j].dutyz+zggz[j].perz;//计算应发工资

	   zggz[j].tax = grsds(zggz[j].shouldz);                                   //计算所得税
	
	   zggz[j].realz = zggz[j].shouldz-zggz[j].tax;                            //计算实发工资

 

       cout<<"以下是您所修改的信息 "<<endl;
       cout<<"工号 "<<endl;
	   cout<<zggz[j].num;
	   cout<<"姓名 "<<endl;
	   cout<<zggz[j].name;
	   cout<<"岗位工资 "<<endl;
	   cout<<zggz[j].jobz;
	   cout<<"薪级工资 "<<endl;
	   cout<<zggz[j].agesz;
	   cout<<"职务津贴 "<<endl;
	   cout<<zggz[j].dutyz;
	   cout<<"绩效工资 "<<endl;
	   cout<<zggz[j].perz;
   }

   int s;

		cout<<"确认是否保存? 1:是; 0:否 "<<endl;

		cin>>s;

		if(s==1)
		    {
				write();
		    }
	
		
   
}

/*################删除函数##########################*/
void del()
{
	//cout<<n<<endl;
	char gonghao[10], c2;              // c2为删除标志

    int i=0,j=101;

    cout<<"请输入要删除的工号"<<endl;

    cin>>gonghao;

    for (;i < n; i++)
	   {
		   if (strcmp(gonghao,zggz[i].num) == 0)
		   {
		       j = i;
		   }
	   }

    cout<<"目前的数组下标为 "<<j<<endl;

   if(j == 101)
   {
      cout<<"查无此人，请再次确认工号是否正确"<<endl;
   }
   else
   {
      cout<<"是否确定删除?=====输入1确认，退出请输入其他字符======"<<endl;

	  cin>>c2;

	  if (c2 == '1')
	  {
	     if (j != (n-1))
		 {
			 for (int k = j + 1; j < n && k < n; j++, k++)
			 {
			         zggz[j]=zggz[k];    // 依次后一记录的获值
			 }

			 n--;    //   人数减少一个

		 }
		 else
		     n--;   //  数组末尾删除，记得保存
	  }
	  else
	  {
		  cout<<"即将退出"<<endl;
	  }
   }
   int s;

		cout<<"确认是否保存? 1:是; 0:否 "<<endl;

		cin>>s;

		if(s==1)
		    {
				write();
		    }
}
/*************************************************
 Function: add()
 Description: 增加记录信息
 Calls: write()保存函数
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义's'实现是否确定保存的功能
 Output: 无
 Return: 无返回值
 Others: 该函数将显示您所填的信息
*************************************************/ 
void add()
{
	
	if ( n > 50)
	{
	  cout<<"记录空间已满！！"<<endl;
	}
	else
	{
	    //cout<<n<<endl;
	    cout<<"请输入全部信息 "<<endl;
	    cout<<"工号 "<<endl;
	    cin>>zggz[n].num;
	    cout<<"姓名 "<<endl;
	    cin>>zggz[n].name;
	    cout<<"岗位工资 "<<endl;
	    cin>>zggz[n].jobz;
	    cout<<"薪级工资 "<<endl;
	    cin>>zggz[n].agesz;
	    cout<<"职务津贴 "<<endl;
	    cin>>zggz[n].dutyz;
	    cout<<"绩效工资 "<<endl;
	    cin>>zggz[n].perz;

	    zggz[n].shouldz = zggz[n].jobz + zggz[n].agesz + zggz[n].dutyz + zggz[n].perz;        //计算应发工资
	
	    zggz[n].tax = grsds(zggz[n].shouldz);                                                 //计算所得税
	
	    zggz[n].realz = zggz[n].shouldz - zggz[n].tax;                                        //计算实发工资

	    cout<<"以下为您所输入的信息 "<<endl;
	    cout<<"工号 "<<zggz[n].num<<endl;
	    cout<<"姓名 "<<zggz[n].name<<endl;
	    cout<<"岗位工资 "<<zggz[n].jobz<<endl;
	    cout<<"薪级工资 "<<zggz[n].agesz<<endl;
	    cout<<"职务津贴 "<<zggz[n].dutyz<<endl;
	    cout<<"绩效工资 "<<zggz[n].perz<<endl;
	    cout<<"应发工资 "<<zggz[n].shouldz<<endl;
	    cout<<"个人所得税 "<<zggz[n].tax<<endl;
	    cout<<"实发工资 "<<zggz[n].realz<<endl;
	}    // 输出输入的信息

	    n++;   // 每次增加人数1

		int s;

		cout<<"确认是否保存? 1:是; 0:否 "<<endl;

		cin>>s;

		if(s==1)
		    {
				write();
		    }
	
}
/*###############浏览函数###########################*/
void list()
{
	//cout<<n<<endl;
    cout<<"下面为全体职工的信息"<<endl;

    for(int i=0;i<n;i++)
      {
           cout<<"工号 "<<zggz[i].num<<endl;
	       cout<<"姓名 "<<zggz[i].name<<endl;
	       cout<<"岗位工资 "<<zggz[i].jobz<<endl;
	       cout<<"薪级工资 "<<zggz[i].agesz<<endl;
	       cout<<"职务津贴 "<<zggz[i].dutyz<<endl;
	       cout<<"绩效工资 "<<zggz[i].perz<<endl;
	       cout<<"应发工资 "<<zggz[i].shouldz<<endl;
	       cout<<"个人所得税 "<<zggz[i].tax<<endl;
	       cout<<"实发工资 "<<zggz[i].realz<<endl;
      }
  
}
/*###############菜单###############################*/
void menu()
{
	cout<<"《--------请根据以下的提示序号输入您所需的功能---------》》"<<endl;
    cout<<"《--------1为查询，2为修改，3为添加，4为删除-----------》》"<<endl;
    cout<<"《--------5为保存，6为浏览，7为退出并返回上级-----------》》"<<endl;
    cout<<endl;
    int c1;
    cin>>c1;
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
void read()
{
    FILE *fp;
	
	if ((fp = fopen ("gx.dat","rb+")) == NULL)
	{
	   cout<<"打开文件失败！"<<endl;

	   getch();

	   exit(-1);
	}
    else
	    cout<<"成功！！ "<<endl;

	while (!feof(fp))
	{
	   fscanf(fp,"%s %s %f %f %f %f %f %lf %lf\n",zggz[n].num,zggz[n].name,&zggz[n].jobz,&zggz[n].agesz,&zggz[n].dutyz,&zggz[n].perz,&zggz[n].shouldz,&zggz[n].tax,&zggz[n].realz);//将数据存入数组 

	   n++;//记录人数
	}

	fclose(fp);//关闭文件

    cout<<"<<-----------目前人数为 "<<n<<"------>>"<<endl;
	cout<<endl;
	cout<<endl;

	while (1)
	{
       cout<<"<<---------输入1进入菜单----------->>"<<endl;
	   cout<<"<<---------输入0退出--------------->>"<<endl;

	   int c;

	   cin>>c;

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