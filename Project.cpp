#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<string>

using namespace std;

struct Student{
    string fName;
    string IName;
    string sID;
};
struct Teacher{
    string fName;
    string lName;
    string tID;
};
struct Course{
    string cName;
    string cID;
};
struct PresentedCourse{
    int pCID;
    struct Teacher teacher;
    struct Course course;
};
struct Register{
    struct Student student;
    struct PresentedCourse registeredCourses[5];
};


int count_lines(string file_address)
{
        int count =  0;

    string line;

    ifstream file(file_address);

    while (getline(file, line))
        count++;
    file.close();
    return count;
}



void Get_Courses(int n,struct Course courses[])
{

    ifstream in("courses.txt");
    for(int i=0;i<n;i++)
         in>>courses[i].cName>>courses[i].cID;
    in.close();
}

void Print_Courses(int n,struct Course courses[])
{
    for(int i=0;i<n;i++)
         cout<<"Course Name: "<<courses[i].cName<<"\t"<<"Course ID: "<<courses[i].cID<<endl;
}

void Get_Teachers(int n,struct Teacher teachers[])
{
    ifstream in("teachers.txt");
    for(int i=0;i<n;i++)
        in>>teachers[i].fName>>teachers[i].lName>>teachers[i].tID;
    in.close();
}

void Print_Teachers(int n,struct Teacher teachers[])
{
    for(int i=0;i<n;i++)
        cout<<"First Name: "<<teachers[i].fName<<"\t"<<"Last Name: "<<teachers[i].lName<<"\t"<<"ID: "<<teachers[i].tID<<endl;
}

void Get_PresentedCourses(int n,int Courses_count,int Teachers_count,struct PresentedCourse presentedCourses[],struct Course courses[],struct Teacher teachers[])
{
    ifstream in("presentedCourse.txt");
    for(int i=0;i<n;i++){
        string tID,cID;
        in>>presentedCourses[i].pCID>>tID>>cID;
        for(int j=0;j<Courses_count;j++){
            if(courses[j].cID.compare(cID)==0)
                presentedCourses[i].course=courses[j];
        }
        for(int j=0;j<Teachers_count;j++){
            if(teachers[j].tID.compare(tID)==0)
                presentedCourses[i].teacher=teachers[j];
        }
    }
    in.close();
}

void Print_PresentedCourses(int n,struct PresentedCourse presentedCourses[])
{
    for(int i=0;i<n;i++)
        cout<<"pCID: "<<presentedCourses[i].pCID<<"\t"<<"First Name: "<<presentedCourses[i].teacher.fName<<"\t"<<"Last Name: "<<presentedCourses[i].teacher.lName<<"\t"<<"tID: "<<presentedCourses[i].teacher.tID<<"\t"<<"Course Name: "<<presentedCourses[i].course.cName<<"\t"<<"Course ID: "<<presentedCourses[i].course.cID<<endl;
}

int main()
{
    int a;
    string file_address="courses.txt";
    int Courses_count=count_lines(file_address);
    int Teachers_count=count_lines("teachers.txt");
    int presentedCourses_count=count_lines("presentedCourse.txt");
    struct Course courses[Courses_count];
    struct Teacher teachers[Teachers_count];
    struct PresentedCourse presentedCourses[presentedCourses_count];

    Get_Courses(Courses_count,courses);
    Get_Teachers(Teachers_count,teachers);
    Get_PresentedCourses(presentedCourses_count,Courses_count,Teachers_count,presentedCourses,courses,teachers);
     //khoshamad gooee
    cout<<"welcome"<<endl;
    //menu
    cout<<"1.moshahede etelaat tamami doroos"<<endl;
    cout<<"2.moshahede etelaat tamami ostadan"<<endl;
    cout<<"3.moshahede doroos eraee shode"<<endl;
    cout<<"4.entekhab vahed"<<endl;
    cin>>a;
    if (a==1){
        Print_Courses(Courses_count,courses);
    }
    else if (a==2){
        Print_Teachers(Teachers_count,teachers);
    }
    else if (a==3){
        Print_PresentedCourses(presentedCourses_count,presentedCourses);
    }
    else if (a==4){
        //code
    }
    else{
        cout<<"error";
    }

    return 0;
}
