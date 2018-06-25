/*************************************************
Copyright (C++), 2018, Mango Tech. Co., Ltd.
 文件名: 工资管理.cpp
 Author:蒙世满(117583010128) Version:C++ Date:22,6,2018 
 Description: 

 I. 主要功能:
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

#include<iostream>
#include<string>
#include<fstream>
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
 Description: 本函数将数组zggz全部写进文件"gx.dat"里面,此函数采用C++格式进行文件的写入
 Calls: 无
 Called By:无
 Table Accessed: 无
 Table Updated: 无
 Input: 本函数定义一个整型'j'记录全局变量'n'的值,定义一个ofstream "outf"进行文件的写入
 Output: 无
 Return: 无返回值
*************************************************/ 
void write()
{
	cout<<"目前人数为 "<<n<<endl;
	int j = n;

    if (j > 0 && j < 50)
	{
		 ofstream outf ("gx.dat", ios::out);

		 if(!outf)
		 {
			 cout<<"无法打开文件"<<endl;
		 }
		 
		 for (int i=0;i<n;i++)
		 {
		       outf << zggz[i].num<<" ";
		       outf << zggz[i].name<<" ";
		       outf << zggz[i].jobz<<" ";
		       outf << zggz[i].agesz<<" ";
		       outf << zggz[i].dutyz<<" ";
		       outf << zggz[i].perz<<" ";
		       outf << zggz[i].shouldz<<" ";
		       outf << zggz[i].tax<<" ";
		       outf << zggz[i].realz<<endl;
		  }

		  outf.close();

      }          //  重新全部录入文件

  else
	  if(j==0)
	  {
		      ofstream outf ("gx.dat", ios::out);

		      if ( !outf )
		      {
			       cout<<"无法打开文件"<<endl;
		      }

	           outf << " ";
		       outf << " ";
		       outf << " ";
		       outf << " ";
		       outf << " ";
		       outf << " ";
		       outf << " ";
		       outf << " ";
		       outf << endl;

	  }
	  else
               cout<<"无记录,将退出"<<endl;
	  

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
	   if (strcmp(gonghao,zggz[i].num) == 0)
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

/*************************************************
 Function: del();
 Description: 删除对应目标的人员
 Calls: write()保存函数
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义gonghao字符数组记录目标工号值,定义's'实现是否确定保存的功能,定义j,k记录下标值
 Output: 无
 Return: 无返回值
 Others: 该函数实现方法为,通过循坏语句找到相应目标人员下标j,后进行从j开始,前一个获取后一个数据,循环条件为:j<n&&k<n;
*************************************************/ 
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
 Function: find();
 Description: 查询并显示目标人员信息
 Calls: 无 
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义gonghao字符数组记录目标工号值,并通过循环语句找到目标后进行输出
 Output: 无
 Return: 无返回值
*************************************************/ 
void find()
{ 
	//cout<<n<<endl;
    char gonghao[10];

    int i = 0, j = 101;

    cout<<"请输入要查询的工号"<<endl;

    cin>>gonghao;

	for (;i < n; i++)
	{
	   if (strcmp(gonghao,zggz[i].num) == 0)
	   {
		   j=i;             // 记录目的下标;
	   }
	}

    if (j == 101)
       {
          cout<<"查无此人，请再次确认工号是否正确"<<endl;
       }
    else
       {
	       cout<<"工号 "<<zggz[j].num<<endl;
	       cout<<"姓名 "<<zggz[j].name<<endl;
	       cout<<"岗位工资 "<<zggz[j].jobz<<endl;
	       cout<<"薪级工资 "<<zggz[j].agesz<<endl;
	       cout<<"职务津贴 "<<zggz[j].dutyz<<endl;
	       cout<<"绩效工资 "<<zggz[j].perz<<endl;
	       cout<<"应发工资 "<<zggz[j].shouldz<<endl;
	       cout<<"个人所得税 "<<zggz[j].tax<<endl;
	       cout<<"实发工资 "<<zggz[j].realz<<endl;
	
       }
   
	
}

/*************************************************
 Function: list();
 Description: 显示全部信息
 Calls: 无 
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 无
 Output: 无
 Return: 无返回值
*************************************************/ 
void list()
{
	//cout<<n<<endl;
    cout<<"下面为全体职工的信息"<<endl;

    for(int i=0;i<n;i++)
      {
		   cout<<"-----------------------------------------------------------------"<<endl;

           cout<<" 工号 "<<" 姓名 "<<" 岗位工资 "<<" 薪级工资 "<<" 职务津贴 "<<endl;

		   cout<<" "<<zggz[i].num<<" "<<" "<<zggz[i].name<<" "<<" "<<zggz[i].jobz<<" "<<"        "<<zggz[i].agesz<<" "<<"   "<<zggz[i].dutyz<<" "<<endl;

	       cout<<endl;

	       cout<<" 绩效工资 "<<" 应发工资 "<<" 个人所得税 "<<" 实发工资 "<<endl;

		   cout<<" "<<zggz[i].perz<<"         "<<" "<<zggz[i].shouldz<<" "<<"   "<<zggz[i].tax<<" "<<"         "<<zggz[i].realz<<" "<<" "<<endl;
			
		   cout<<"-----------------------------------------------------------------"<<endl;
      }
  
}

/*************************************************
 Function: menu();
 Description: 显示功能信息代码,并通过switch选择执行对应语句
 Calls: 无 
 Called By: 无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义c1获取用户输入的值,通过switch执行对应函数
 Output: 无
 Return: 无返回值
*************************************************/ 
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
/*************************************************
 Function: read();
 Description: 本函数将文件"gx.dat"里面数据全部写进数组zggz,此函数采用C++格式进行文件的读取
 Calls: 无
 Called By:无
 Table Accessed: 无
 Table Updated: 无
 Input: 定义一个ifstream "inf"进行文件的读取
 Output: 无
 Return: 无返回值
*************************************************/ 
void read()
{
	ifstream inf("gx.dat",ios::in|ios::binary);

	if( !inf )
	{
	   cout<<"无法打开！！！gx.dat文件！！"<<endl;

	   exit(1);
	}

	//cout<<n<<endl;

	while(inf)
	{
		inf >> zggz[n].num;
		inf >> zggz[n].name;
		inf >> zggz[n].jobz;
		inf >> zggz[n].agesz;
		inf >> zggz[n].dutyz;
		inf >> zggz[n].perz;
		inf >> zggz[n].shouldz;
		inf >> zggz[n].tax;
		inf >> zggz[n].realz;

	    n++;                    //  最后值为人数多1
	
	}                           //   读取文件赋值给结构体数组

	inf.close();//关闭文件

	n--;

	cout<<endl;
	cout<<"#########目前人数为 "<<n<<"###########"<<endl;

	cout<<endl;
	cout<<endl;

	while(1)
	{
	            
		cout<<"<<=====输入1进入菜单=====>>"<<endl;
		cout<<"<<=====输入0退出=========>>"<<endl;

		int c;

		cin>>c;

		switch(c)
		{
		    case 1:
			    menu();
				break;

		    case 0:
			    exit(1);
			    break;

		}
	}
	
}

/*###############主函数#############################*/
int main()
{
	read();

	system("pause");

return 0;
}