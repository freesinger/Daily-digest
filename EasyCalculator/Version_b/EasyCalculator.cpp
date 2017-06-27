#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define N 4

struct subject
{
    int  studentNo;
    char name[20];
    int  sex;
    int  math;
    int  phy;
    int  english;
    int  computer;
    float aver;

};

void  menu(void);
void  inputStudent(subject *stu);
void  outputStudent(subject *stu);
void  outputOneStudentNo(subject *stu);
void  outputOneStudentName(subject *stu);
void  outputStudentFail(subject *stu);
void  outputStudentAver(subject *stu);
void  sortStudentAver(subject *stu);
void  sortStudentNo(subject *stu);

struct subject student[N];

int main(void)
{
    int op;

    while(1)
    {  
      menu();
	  printf("\n 请输入菜单选择（1-8）: \n"); 
      scanf("%d",&op); 
	  
	  switch (op)
	  {
         case 1:
		     inputStudent(student);
			 break;
         case 2:
			 sortStudentNo(student);
			 outputStudent(student);
			 system("pause");
			 break;
         case 3:
			 sortStudentAver(student);
             outputStudent(student);
			 system("pause");
			 break;
	     case 4:
             outputStudentAver(student);
			 system("pause");
			 break;
         case 5:
			 outputOneStudentNo(student);
			 system("pause");
			 break;
         case 6:
			 outputOneStudentName(student);
			 system("pause");
			 break;
         case 7:
			 outputStudentFail(student);
			 system("pause");
			 break;
         case 8:
			 system("cls");
			 menu();
			 break;
	     case 9:
			  return 0; 
         default:
	  	      break;
  
	  }
    }

    return 0;
}

void menu(void)
{   
	system("cls");
	printf("\n\n");
	printf("     ***************************************\n");
	printf("     *  1. 学生资料录入                    *\n");
    printf("     *  2. 按学号顺序显示成绩单            *\n");
    printf("     *  3. 从高分到低分的顺序显示成绩单    *\n");
    printf("     *  4. 计算并显示全班平均成绩          *\n");
    printf("     *  5. 按学号检索学生个人成绩单        *\n");
    printf("     *  6. 按学号检索学生个人成绩单        *\n");
    printf("     *  7. 显示不及格学生的成绩单          *\n");
	printf("     *  8. 清理屏幕显示                    *\n");
    printf("     *  9. 退出系统                        *\n");
    printf("     ***************************************\n");
}


void inputStudent(subject *stu)
{   
    int i;
    	
    for(i=0;i<N;i++)
    { 
		
        system("cls");
        menu();
        
        printf("学生资料录入:");
		printf("\n\n");
	    printf("学生 %d 信息:\n",i+1);
		
		printf("学号         :%d \n", 201000+i+1);
        stu[i].studentNo = 201000+i+1;
		printf("\n");

        printf("姓名         :");
        scanf("%s",stu[i].name);
        printf("\n");

        printf("性别(0-1)    :");
        scanf("%d",&stu[i].sex); 
        printf("\n");
        
		printf("数学(0-100)  :");
        scanf("%d",&stu[i].math);
		printf("\n");

		printf("物理(0-100)  :");
        scanf("%d",&stu[i].phy);
        printf("\n");

        printf("英语(0-100)  :"); 
        scanf("%d",&stu[i].english);
        printf("\n"); 
        
		printf("计算机(0-100):");
        scanf("%d",&stu[i].computer);
		printf("\n");

	    stu[i].aver=(float)(stu[i].math+stu[i].phy+stu[i].english+stu[i].computer)/4;
    }

}

void outputStudent(subject *stu)
{
    int i;

   	printf("------------------------------------------------------------------------\n");
	printf("学号\t姓名\t\t性别\t数学\t物理\t英语\t计算机\t平均成绩\n");
	printf("------------------------------------------------------------------------\n");
    for(i=0;i<N;i++)
    {    

	   printf("%d",stu[i].studentNo);
       printf("\t%s",stu[i].name);
       printf("\t\t%d  ",stu[i].sex); 
       printf("\t%d" ,stu[i].math);
       printf("\t%d" ,stu[i].phy);
       printf("\t%d" ,stu[i].english);
       printf("\t%d" ,stu[i].computer);
       printf("\t%2.2f",stu[i].aver);
	   printf("\n");	
	   printf("------------------------------------------------------------------------\n");
    }

   
}

void outputOneStudentNo(subject *stu)
{
    int i, studentNo;
    int flag=0;    
	studentNo=0;


	printf("输入学生学号： ");
	scanf("%d", &studentNo);

	for(i=0;i<N;i++)
    {
		if(stu[i].studentNo == studentNo)
        {
			printf("------------------------------------------------------------------------\n");
	        printf("学号\t姓名\t\t性别\t数学\t物理\t英语\t计算机\t平均成绩\n");
	        printf("------------------------------------------------------------------------\n");
   	        printf("%d",stu[i].studentNo);
            printf("\t%s",stu[i].name);
            printf("\t\t%d  ",stu[i].sex); 
            printf("\t%d" ,stu[i].math);
            printf("\t%d" ,stu[i].phy);
            printf("\t%d" ,stu[i].english);
            printf("\t%d" ,stu[i].computer);
            printf("\t%2.2f",stu[i].aver);
	        printf("\n");	
	        printf("------------------------------------------------------------------------\n");

			flag=1;
			break;
		}

	}

	if(flag==0)
    {
			printf("\n");	
	        printf("------------------------------------------------------------------------\n");
			printf("没有该学生的资料！\n");
	        printf("------------------------------------------------------------------------\n");
			printf("\n");
	}
}

void outputOneStudentName(subject *stu)
{
    int i;
    int flag=0;    
	char studentName[20];


	printf("输入学生姓名： ");
	scanf("%s", studentName);

	for(i=0;i<N;i++)
    {
		if(strcmp(stu[i].name, studentName)==0)
        {
			printf("------------------------------------------------------------------------\n");
	        printf("学号\t姓名\t\t性别\t数学\t物理\t英语\t计算机\t平均成绩\n");
	        printf("------------------------------------------------------------------------\n");
   	        printf("%d",stu[i].studentNo);
            printf("\t%s",stu[i].name);
            printf("\t\t%d  ",stu[i].sex); 
            printf("\t%d" ,stu[i].math);
            printf("\t%d" ,stu[i].phy);
            printf("\t%d" ,stu[i].english);
            printf("\t%d" ,stu[i].computer);
            printf("\t%2.2f",stu[i].aver);
	        printf("\n");	
	        printf("------------------------------------------------------------------------\n");

			flag=1;
			break;
		}
	}

	if(flag==0)
    {
		printf("\n");	
	    printf("------------------------------------------------------------------------\n");
		printf("没有该学生的资料！\n");
	    printf("------------------------------------------------------------------------\n");
		printf("\n");
	}


}

void outputStudentAver(subject *stu)
{   
    int i;
    float subjAver=0.0;
	float mathAver=0.0;
	float phyAver=0.0;
	float englishAver=0.0;
	float computerAver=0.0;
   
	for(i=0;i<N;i++)
    { 
        subjAver+=stu[i].aver;
		mathAver+=stu[i].math;
		phyAver+=stu[i].phy;
		englishAver+=stu[i].english;
		computerAver+=stu[i].computer;
	}
    
	subjAver=subjAver/N;
	mathAver=mathAver/4;
	phyAver=phyAver/4;
	englishAver=englishAver/4;
	computerAver=computerAver/4;

	outputStudent(stu);
	printf("平均成绩：\t\t\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f", mathAver,phyAver,englishAver,computerAver,subjAver);
    printf("\n");	
	printf("------------------------------------------------------------------------\n");
 
}

void sortStudentAver(subject *stu)
{
    int i,j;
    subject item;
	
    for(i=0;i<N;i++)
       for(j=i+1;j<N;j++)
       {
           if(stu[i].aver<stu[j].aver) 
           {
               item=stu[i];
               stu[i]=stu[j];
               stu[j]=item;               
            }
        }

}

void sortStudentNo(subject *stu)
{
    int i,j;
    subject item;
	
    for(i=0;i<N;i++)
       for(j=i+1;j<N;j++)
       {
           if(stu[i].studentNo>stu[j].studentNo) 
           {
               item=stu[i];
               stu[i]=stu[j];
               stu[j]=item;               
            }
        }
}

void outputStudentFail(subject *stu)
{
    int i;

   	printf("------------------------------------------------------------------------\n");
	printf("学号\t姓名\t\t性别\t数学\t物理\t英语\t计算机\t平均成绩\n");
	printf("------------------------------------------------------------------------\n");
    for(i=0;i<N;i++)
    {    
      if(stu[i].math<60||stu[i].phy<60||stu[i].english<60||stu[i].computer<60 ) 
	  {
	      printf("%d",stu[i].studentNo);
          printf("\t%s",stu[i].name);
          printf("\t\t%d  ",stu[i].sex); 
          printf("\t%d" ,stu[i].math);
          printf("\t%d" ,stu[i].phy);
          printf("\t%d" ,stu[i].english);
          printf("\t%d" ,stu[i].computer);
          printf("\t%2.2f",stu[i].aver);
	      printf("\n");	
	      printf("------------------------------------------------------------------------\n");
      }
    }

   
}
