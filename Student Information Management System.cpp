#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
int number=10;
class student
{
private:
    string studentName,studentDepartment,studentID;
    float cgpa;
public:
    student(){studentName='0';studentID='0';studentDepartment='0';cgpa=0;}
    void creat_student_information()
    {
        cin.ignore();
        cout<<endl<<"\t\t\tEnter The Name of student : ";
        getline(cin, studentName);
        cout<<endl<<"\t\t\tEnter Student ID : ";cin>>studentID;fflush(stdin);
        cout<<endl<<"\t\t\tEnter Student Department : ";cin>>studentDepartment;fflush(stdin);
        cout<<endl<<"\t\t\tEnter Student CGPA : ";cin>>cgpa;
        cout<<endl<<"\t\t\tStudent Record Has Been Created"<<endl;
    }
    string search_id(){return studentID;}
    string search_name(){return studentName;}
    string search_department(){return studentDepartment;}
    void show_information()
    {
        cout<<endl<<"\t\t\t\tStudent Name : "<<studentName<<endl;
        cout<<endl<<"\t\t\t\tStudent ID : "<<studentID<<endl;
        cout<<endl<<"\t\t\t\tStudent Department : "<<studentDepartment<<endl;
        cout<<endl<<"\t\t\t\tStudent CGPA : "<<cgpa<<endl;
    }
};
void menu(student st[])
{
    char choice;
    string id,name,department;
    int i;
    cout<<endl<<endl<<"\t\t\t\t\t\tStudent Information"<<endl<<endl<<endl;
    cout<<"\t\t\t\t1: Create Student Information"<<endl<<endl<<"\t\t\t\t2: Show Student Information"<<endl<<endl<<"\t\t\t\t3: Exit"<<endl<<endl;
    cout<<endl<<"\t\t\t\tSelect Your Option : ";cin>>choice;
    switch(choice)
    {
    case '1' :
        cout<<endl<<"\t\t\tNumber Of Student (in-digit) : ";cin>>number;
        for( i=0;i<number;i++)
        {
            st[i].creat_student_information();
        }
        menu(st);
        break;
    case '2' :
        char ch;
        cout<<endl<<endl<<"\t\t\t  (IF YOU ENTER WRONG INFO YOU HAVE TO RETURN TO MAIN MENU)"<<endl<<endl;
        cout<<endl<<"\t\t\t1: Search By ID"<<endl<<endl<<"\t\t\t2: Search By Name"<<endl<<endl<<"\t\t\t3: Search By Department"<<endl;
        cout<<endl<<"\t\t\t4: Menu"<<endl;
        cout<<endl<<"\t\t\tHow You Want To Search Information : ";cin>>ch;
        switch(ch)
        {
        case '1' :

            cout<<endl<<"\t\t\tEnter Student ID : ";cin>>id;
            fflush(stdin);
            for( i=0;i<number;i++)
            {
                if(st[i].search_id().find(id)>=0 && st[i].search_id().find(id)<st[i].search_id().length())
                {
                    st[i].show_information();
                }
            }
            char M;
            cout<<endl<<"\t\t\tEnter M/m To Go To Menu : ";cin>>M;
            switch(M)
            {
                case 'M' : menu(st);break;
                case 'm' : menu(st);break;
                default : cout<<"\t\t\tWrong Input"<<endl;
            }
            break;
        case '2' :
            cout<<endl<<"\t\t\tEnter Student Name : ";cin>>name;
            fflush(stdin);
            for( i=0;i<number;i++)
            {
                if(st[i].search_name().find(name)>=0 && st[i].search_name().find(name)<st[i].search_name().length())
                {
                    st[i].show_information();
                }
            }
            cout<<endl<<"\t\t\tEnter M/m To Go To Menu : ";cin>>M;
            switch(M)
            {
                case 'M' : menu(st);break;
                case 'm' : menu(st);break;
                default : cout<<"Wrong Input"<<endl;
            }
            break;
        case '3' :
            cout<<endl<<"\t\t\tEnter Student Department : ";cin>>department;
            fflush(stdin);
            for( i=0;i<number;i++)
            {
                if(st[i].search_department().find(department)>=0 && st[i].search_department().find(department)<st[i].search_department().length())
                {
                    st[i].show_information();
                }


            }
            cout<<endl<<"\t\t\tEnter M/m To Go To Menu : ";cin>>M;
            switch(M)
            {
                case 'M' : menu(st);break;
                case 'm' : menu(st);break;
                default : cout<<"Wrong Input"<<endl;
            }
            break;
        case '4' :
            menu(st);
            break;
        default :
            cout<<endl<<"\t\t\tWrong Input"<<endl;
            menu(st);
        }
    case '3' :cout<<endl<<"\t\t\t\tProgram Exited"<<endl;exit(1);
    default : menu(st);
    }
}
int main()
{
    system("Color 0B");
    student st[number];
    time_t T;
    time(&T);
    //cout<<"\n\t\t\t\t\t      "<<ctime (&T);
    cout<<"\n\t\t\t\tCurrent Date & Time is : "<<ctime(&T);
    menu(st);
    return 0;
}
