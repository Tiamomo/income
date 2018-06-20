#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct emploees{
	char num[10];//工号
	char name[10];//姓名
	float jobz;//岗位工资
	float agesz;//薪级工资
	float dutyz;//职务津贴
	float perz;//绩效工资
	float shouldz;//应发工资
	double tax;//个人所得税
	double realz;//实发工资
}zggz[50];
int n=0;//全局变量
double grsds(float v)
{   double c;
    v-=3500;//减去免征税
	if(v<=500&&v>=0)
	{c=v*0.05;return c;}
	else
		if(v>500&&v<=2000)
		{c=v*0.1;return c;}
		else
			if(v>2000&&v<=5000)
			{c=v*0.15;return c;}
			else
				if(v>5000&&v<=20000)
				{c=v*0.2;return c;}
				else
					if(v>20000&&v<=40000)
					{c=v*0.25;return c;}
					else
						if(v>40000&&v<=60000)
						{c=v*0.3;return c;}
						else
							if(v>60000&&v<=80000)
							{c=v*0.35;return c;}
							else 
								if(v>80000&&v<=100000)
								{c=v*0.4;return c;}
								else
									if(v>100000)
									{c=v*0.45;return c;}
									else
										if(v<=0)
	                                      return 0;
	return 0;
}//计算个人所得税
void write()
{
  int j=n;
  if(j>0)
     {
		 ofstream outf("gx.dat");
		 if(!outf)
		 {
			 cout<<"无法打开文件"<<endl;
		 }
		 for(int i=0;i<n;i++)
			 outf.write((char*)&zggz[i],sizeof(zggz[i]));
		     outf.close();
      }//重新全部录入文件
  else
	  cout<<"无记录,将退出"<<endl;

}//保存
void modify()
{
	char gonghao[10];
   int i=0,j=101;
   cout<<"请输入要修改的工号"<<endl;
   cin>>gonghao;
   for(;i<n;i++)
	   if(strcmp(gonghao,zggz[i].num)==0)
		   j=i;
   if(j==101)
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
	

	zggz[j].shouldz=zggz[j].jobz+zggz[j].agesz+zggz[j].dutyz+zggz[j].perz;

	zggz[j].tax=grsds(zggz[j].shouldz);//计算所得税
	
	zggz[j].realz=zggz[j].shouldz-zggz[j].tax;//计算应发工资

   }
   write();//保存
}//修改
void add()
{
	n++;
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

	zggz[n].shouldz=zggz[n].jobz+zggz[n].agesz+zggz[n].dutyz+zggz[n].perz;//计算应发工资
	
	zggz[n].tax=grsds(zggz[n].shouldz);//计算所得税
	
	zggz[n].realz=zggz[n].shouldz-zggz[n].tax;//计算实发工资
	write();//保存
}//增加
void del()
{
	char gonghao[10],c2;
   int i=0,j=101;
   cout<<"请输入要删除的工号"<<endl;
   cin>>gonghao;
   for(;i<n;i++)
	   if(strcmp(gonghao,zggz[i].num)==0)
		   j=i;
   if(j==101)
   {
      cout<<"查无此人，请再次确认工号是否正确"<<endl;
   }
   else
   {
      cout<<"是否确定删除?输入1确认，退出请输入其他字符"<<endl;
	  cin>>c2;
	  if(c2=='1')
	  {
	     int k=j+1;
		 for(;j<n-1;j++,k++)
			 zggz[j]=zggz[k];//依次后一记录的获值	
		 //zggz[n]={'0','0',0,0,0,0,0,0,0};//数组末尾清零
	  }
   }
   write();
}//删除
void find()
{
   char gonghao[10];
   int i=0,j=101;
   cout<<"请输入要查询的工号"<<endl;
   cin>>gonghao;
   for(;i<n;i++)
	   if(strcmp(gonghao,zggz[i].num)==0)
		   j=i;
   if(j==101)
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
   getchar();
	//cout<<"成功调用find "<<endl;
}//查询
void list()
{
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
  getchar();
}
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
	ifstream inf("gx.dat");
	if(!inf)
	{
	   cout<<"无法打开！！！gx.dat文件！！"<<endl;
	   exit(1);
	}
	while(inf)
	{
		inf>>zggz[n].num;
		inf>>zggz[n].name;
		inf>>zggz[n].jobz;
		inf>>zggz[n].agesz;
		inf>>zggz[n].dutyz;
		inf>>zggz[n].perz;
		inf>>zggz[n].shouldz;
		inf>>zggz[n].tax;
		inf>>zggz[n].realz;
	  n++;//比实际人数多1
	
	}//读取文件赋值给结构体数组
	inf.close();//关闭文件
	
	while(1)
	{
	//	system("cls");//清屏
		cout<<"<<=====输入1进入菜单=====>>"<<endl;
		cout<<"<<=====输入0退出=========>>"<<endl;
		int c;
		cin>>c;
		switch(c)
		{

		case 1:
			menu();break;
		case 0:
			exit(1);
			break;
		}
	}
	
}
int main()
{
	read();
	system("pause");
return 0;
}