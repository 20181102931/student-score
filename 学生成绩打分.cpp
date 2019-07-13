#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define N 15
using namespace std;
struct student
{
    string number;
    string student_name;
    string telephone;
    string student_number;
    double stu_score[7];
    double sum;
    double max,min;
    double ave;
}stu[N];
struct judge
{
	string judge_name;
	string judge_college;
	double judge_score[N];
}jud[7];
bool cmp(student s1,student s2){
    return s1.ave>s2.ave;
}
int main()
{   ifstream in("/Users/lenovo/Desktop/information.txt");
    ifstream on("/Users/lenovo/Desktop/judge_score.txt");
    ofstream out("/Users/lenovo/Desktop/finally score.txt");
    for(int t=0;t<N;t++)
    {
    	in>>stu[t].number>>stu[t].student_name>>stu[t].student_number>>stu[t].telephone;
        stu[t].sum=stu[t].ave=0;
	}  
    for(int j=0;j<7;j++)
    {
    	getline(on,jud[j].judge_name,' ');
    	getline(on,jud[j].judge_college,' ');
    	  
    	for(int i=0;i<N;i++)
        {
            on>>jud[j].judge_score[i];
             
        } 
	}
	    for(int t=0;t<N;t++)
	    {
	    	for(int i=0;i<7;i++)
	    	{
	    		stu[t].stu_score[i]=jud[i].judge_score[t]; 
	    		stu[t].sum=stu[t].stu_score[i]+stu[t].sum;
			}
		}
          for(int t=0;t<N;t++)  
        {
        stu[t].max=stu[t].stu_score[0];
        stu[t].min=stu[t].stu_score[0];
        for(int j=0;j<7;j++)
        {
            if(stu[t].stu_score[j]>stu[t].max)
                stu[t].max = stu[t].stu_score[j];
            if(stu[t].stu_score[j]<stu[t].min)
                stu[t].min = stu[t].stu_score[j];
        }
        stu[t].sum = stu[t].sum- stu[t].max-stu[t].min;
       
        stu[t].ave = 1.0*stu[t].sum/5;
    }
    in.close();
    sort(stu,stu+N,cmp);
      out<<left<<setw(10)<<"rank"
	     <<left<<setw(20)<<"number"
	     <<left<<setw(15)<<"name"
	     <<left<<setw(15)<<"telephone"
	     <<left<<setw(15)<<"ave";
    out<<left<<setw(15)<<"judge_1"
   	    <<left<<setw(15)<<"judge_2"
		<<left<<setw(15)<<"judge_3"
	    <<left<<setw(15)<<"judge_4"
	    <<left<<setw(15)<<"judge_5"
	    <<left<<setw(15)<<"judge_6"
	    <<left<<setw(15)<<"judge_7"<<endl;
	for(int k=0;k<N;k++)
    {
      out<<left<<setw(10)<<k+1
	     <<left<<setw(20)<<stu[k].student_number
	     <<left<<setw(15)<<stu[k].student_name
         <<left<<setw(15)<<stu[k].telephone
		 <<left<<setw(15)<<stu[k].ave;
		   for(int i=0;i<7;i++)
		  {
		 	out<<left<<setw(19)<<stu[k].stu_score[i];
		  }
			 
		 out<<endl;
		 
		 
    }
    out.close();
    return 0;
}
