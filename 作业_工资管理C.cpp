/*************************************************
Copyright (C����), 2018, Mango Tech. Co., Ltd.
 �ļ���: ���ʹ���.c
 Author:������(117583010128) Version:C���� Date:26,6,2018 
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
#include<iostream>
using namespace std;
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
		  printf("������ɣ�\n");

		  fclose(fp2);//�ر��ļ�

      }          //  ����ȫ��¼���ļ�

  else
	  if(j==0)
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

//��ѯ����1
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
	//cout<<n<<endl;
	char gonghao[10];

    int i = 0,j = 101;

   cout<<"������Ҫ�޸ĵĹ���"<<endl;

   cin >> gonghao;

   for (;i < n; i++)
   {
	   if(strcmp(gonghao,zggz[i].num) == 0)
	   {
		   j = i;
	   }
   }
              //���չ������β���
   if (j == 101)
   {
      cout<<"���޴��ˣ����ٴ�ȷ�Ϲ����Ƿ���ȷ"<<endl;
   }
   else
   {
	   cout<<"������¼�������Ϣ "<<endl;
	   cout<<"���� "<<endl;
	   cin>>zggz[j].num;
	   cout<<"���� "<<endl;
	   cin>>zggz[j].name;
	   cout<<"��λ���� "<<endl;
	   cin>>zggz[j].jobz;
	   cout<<"н������ "<<endl;
	   cin>>zggz[j].agesz;
	   cout<<"ְ����� "<<endl;
	   cin>>zggz[j].dutyz;
	   cout<<"��Ч���� "<<endl;
	   cin>>zggz[j].perz;
	
	   zggz[j].shouldz = zggz[j].jobz+zggz[j].agesz+zggz[j].dutyz+zggz[j].perz;//����Ӧ������

	   zggz[j].tax = grsds(zggz[j].shouldz);                                   //��������˰
	
	   zggz[j].realz = zggz[j].shouldz-zggz[j].tax;                            //����ʵ������

 

       cout<<"�����������޸ĵ���Ϣ "<<endl;
       cout<<"���� "<<endl;
	   cout<<zggz[j].num;
	   cout<<"���� "<<endl;
	   cout<<zggz[j].name;
	   cout<<"��λ���� "<<endl;
	   cout<<zggz[j].jobz;
	   cout<<"н������ "<<endl;
	   cout<<zggz[j].agesz;
	   cout<<"ְ����� "<<endl;
	   cout<<zggz[j].dutyz;
	   cout<<"��Ч���� "<<endl;
	   cout<<zggz[j].perz;
   }

   int s;

		cout<<"ȷ���Ƿ񱣴�? 1:��; 0:�� "<<endl;

		cin>>s;

		if(s==1)
		    {
				write();
		    }
	
		
   
}

/*################ɾ������##########################*/
void del()
{
	//cout<<n<<endl;
	char gonghao[10], c2;              // c2Ϊɾ����־

    int i=0,j=101;

    cout<<"������Ҫɾ���Ĺ���"<<endl;

    cin>>gonghao;

    for (;i < n; i++)
	   {
		   if (strcmp(gonghao,zggz[i].num) == 0)
		   {
		       j = i;
		   }
	   }

    cout<<"Ŀǰ�������±�Ϊ "<<j<<endl;

   if(j == 101)
   {
      cout<<"���޴��ˣ����ٴ�ȷ�Ϲ����Ƿ���ȷ"<<endl;
   }
   else
   {
      cout<<"�Ƿ�ȷ��ɾ��?=====����1ȷ�ϣ��˳������������ַ�======"<<endl;

	  cin>>c2;

	  if (c2 == '1')
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
		     n--;   //  ����ĩβɾ�����ǵñ���
	  }
	  else
	  {
		  cout<<"�����˳�"<<endl;
	  }
   }
   int s;

		cout<<"ȷ���Ƿ񱣴�? 1:��; 0:�� "<<endl;

		cin>>s;

		if(s==1)
		    {
				write();
		    }
}
/*************************************************
 Function: add()
 Description: ���Ӽ�¼��Ϣ
 Calls: write()���溯��
 Called By: ��
 Table Accessed: ��
 Table Updated: ��
 Input: ����'s'ʵ���Ƿ�ȷ������Ĺ���
 Output: ��
 Return: �޷���ֵ
 Others: �ú�������ʾ���������Ϣ
*************************************************/ 
void add()
{
	
	if ( n > 50)
	{
	  cout<<"��¼�ռ���������"<<endl;
	}
	else
	{
	    //cout<<n<<endl;
	    cout<<"������ȫ����Ϣ "<<endl;
	    cout<<"���� "<<endl;
	    cin>>zggz[n].num;
	    cout<<"���� "<<endl;
	    cin>>zggz[n].name;
	    cout<<"��λ���� "<<endl;
	    cin>>zggz[n].jobz;
	    cout<<"н������ "<<endl;
	    cin>>zggz[n].agesz;
	    cout<<"ְ����� "<<endl;
	    cin>>zggz[n].dutyz;
	    cout<<"��Ч���� "<<endl;
	    cin>>zggz[n].perz;

	    zggz[n].shouldz = zggz[n].jobz + zggz[n].agesz + zggz[n].dutyz + zggz[n].perz;        //����Ӧ������
	
	    zggz[n].tax = grsds(zggz[n].shouldz);                                                 //��������˰
	
	    zggz[n].realz = zggz[n].shouldz - zggz[n].tax;                                        //����ʵ������

	    cout<<"����Ϊ�����������Ϣ "<<endl;
	    cout<<"���� "<<zggz[n].num<<endl;
	    cout<<"���� "<<zggz[n].name<<endl;
	    cout<<"��λ���� "<<zggz[n].jobz<<endl;
	    cout<<"н������ "<<zggz[n].agesz<<endl;
	    cout<<"ְ����� "<<zggz[n].dutyz<<endl;
	    cout<<"��Ч���� "<<zggz[n].perz<<endl;
	    cout<<"Ӧ������ "<<zggz[n].shouldz<<endl;
	    cout<<"��������˰ "<<zggz[n].tax<<endl;
	    cout<<"ʵ������ "<<zggz[n].realz<<endl;
	}    // ����������Ϣ

	    n++;   // ÿ����������1

		int s;

		cout<<"ȷ���Ƿ񱣴�? 1:��; 0:�� "<<endl;

		cin>>s;

		if(s==1)
		    {
				write();
		    }
	
}
/*###############�������###########################*/
void list()
{
	//cout<<n<<endl;
    cout<<"����Ϊȫ��ְ������Ϣ"<<endl;

    for(int i=0;i<n;i++)
      {
           cout<<"���� "<<zggz[i].num<<endl;
	       cout<<"���� "<<zggz[i].name<<endl;
	       cout<<"��λ���� "<<zggz[i].jobz<<endl;
	       cout<<"н������ "<<zggz[i].agesz<<endl;
	       cout<<"ְ����� "<<zggz[i].dutyz<<endl;
	       cout<<"��Ч���� "<<zggz[i].perz<<endl;
	       cout<<"Ӧ������ "<<zggz[i].shouldz<<endl;
	       cout<<"��������˰ "<<zggz[i].tax<<endl;
	       cout<<"ʵ������ "<<zggz[i].realz<<endl;
      }
  
}
/*###############�˵�###############################*/
void menu()
{
	cout<<"��--------��������µ���ʾ�������������Ĺ���---------����"<<endl;
    cout<<"��--------1Ϊ��ѯ��2Ϊ�޸ģ�3Ϊ��ӣ�4Ϊɾ��-----------����"<<endl;
    cout<<"��--------5Ϊ���棬6Ϊ�����7Ϊ�˳��������ϼ�-----------����"<<endl;
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
	   cout<<"���ļ�ʧ�ܣ�"<<endl;

	   getch();

	   exit(-1);
	}
    else
	    cout<<"�ɹ����� "<<endl;

	while (!feof(fp))
	{
	   fscanf(fp,"%s %s %f %f %f %f %f %lf %lf\n",zggz[n].num,zggz[n].name,&zggz[n].jobz,&zggz[n].agesz,&zggz[n].dutyz,&zggz[n].perz,&zggz[n].shouldz,&zggz[n].tax,&zggz[n].realz);//�����ݴ������� 

	   n++;//��¼����
	}

	fclose(fp);//�ر��ļ�

    cout<<"<<-----------Ŀǰ����Ϊ "<<n<<"------>>"<<endl;
	cout<<endl;
	cout<<endl;

	while (1)
	{
       cout<<"<<---------����1����˵�----------->>"<<endl;
	   cout<<"<<---------����0�˳�--------------->>"<<endl;

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