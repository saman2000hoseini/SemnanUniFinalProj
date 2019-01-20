#include<iostream>
#include<fstream>

using namespace std;

struct Student{
    string fName;
    string IName;
    string sID;
};
struct Teacher{
    string fName;
    string IName;
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



void Get_Courses(int n,Course courses[])
{
    
    ifstream in("courses.txt");
    for(int i=0;i<n;i++){
         in>>courses[i].cName>>courses[i].cID;
        //cout<<courses[i].cName<<endl;
    }
    in.close();
}   

void Print_Courses(int n,struct Course courses[])
{
    for(int i=0;i<n;i++)
         cout<<"Course Name: "<<courses[i].cName<<endl<<"Course ID: "<<courses[i].cID<<endl;
}

void Get_Teachers(int n,struct Teacher teachers[])
{
    ifstream in("teachers.txt");
    for(int i=0 i<n;i++)
        in>>teachers[i].fName>>teachers[i].lName>>teachers[i].tID;
    in.close;
}

void Print_Teachers(int n,struct Teacher teachers[])
{
    for(int i=0;i<n;i++)
        cout<<"First Name: "<<teachers[i].fName<<endl<<"Last Name: 0"<<teachers[i].lName<<endl<<"ID: "<<teachers[i].tID<<endl;
}

int main()
{
    int a; 
    string file_address="courses.txt";
    int Courses_count=count_lines(file_address);
    int Teachers_count=count_lines("teachers.txt");
    struct Course courses[Courses_count];
    struct Teacher teachers[Teachers_count];

    Get_Courses(Courses_count,courses);
    Get_Teachers(Teachers_count,teachers);

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
    if (a==2){
        Print_Teachers(Teachers_count,teachers);
    }
    if (a==3){
        //code
    }
    if (a==4){
        //code
    }
    else{
        cout<<"error";
    }

    return 0;
}
