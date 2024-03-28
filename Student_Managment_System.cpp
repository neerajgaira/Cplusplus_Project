// Student Managment System : 
#include<bits/stdc++.h>
using namespace std;
#define clrscr() system("cls")
class Student{
    private:
        int rollno, age;
        string name;
    public:
        Student(int stdrollno, string stdname , int stdage){
            rollno = stdrollno;
            // age = stdage;
            name = stdname;
            age = stdage;
        }
        void setrollno(int stdrollno){
            rollno = stdrollno;
        }
        int getrollno(){
            return rollno;
        }
        void setname(string stdname){
            name = stdname;
        }
        string getname(){
            return name;
        }
        void setage(int stdage){
            age = stdage;
        }
        int getage(){
            return age;
        }
        void displaystudent(){
            cout<<"Roll No : "<<rollno<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<endl;
        }
};

// Function to add a new student : 
void addnewstudent(vector<Student> &student){
    int rollno, age;
    string name;
    cout<<"Enter Roll No : ";
    cin>>rollno;
    // Check if Student already exist : 
    for(int i=0;i<student.size();i++){
        if(student[i].getrollno()==rollno){
            cout<<"\tStudent Already Exist"<<endl;
            return;
        }
    }
    cout<<"Enter Name : ";
    cin>>name;
    cout<<"Enter Age : ";
    cin>>age;
    Student newStudent(rollno,name,age);
    student.push_back(newStudent);

    cout<<"Student Added Successfully.........."<<endl;
}


// Function to display all student : 
void DisplayAllStudent(vector<Student>&student){
    if(student.empty()){
        cout<<"No Student Found"<<endl;
        return;
    }
    for(int i=0;i<student.size();i++){
        student[i].displaystudent();
        cout<<endl;
    }
}

// Funtion to Search a Student : 
void SearchStudent(vector<Student>student){
    int rollno;
    cout<<"Enter Roll No. : ";
    cin>>rollno;

    for(int i=0;i<student.size();i++){
        if(student[i].getrollno()==rollno){
            cout<<"Stuedent Found"<<endl;
            student[i].displaystudent();
            return;
        }
    }
}

// Function for Updating a Student : 
void updateStudent(vector<Student>&student){
    string sname;
    bool found = false;
    int choice;
    cout<<"\t\tEnter Name to Update Record :";
    cin.ignore();
    getline(cin,sname);
    for(int i = 0; i<student.size();i++){
        if(student[i].getname()==sname){
            found = true;
            cout<<"\t\t---Student Found -----"<<endl;
            cout<<"\t\t 1. Update Rollno "<<endl;
            cout<<"\t\t 2. Update Name "<<endl;
            cout<<"\t\t 3. Update Age "<<endl;
            cout<<"\t\tEnter Your Choice :";
            cin>>choice;
            switch(choice){
                case 1:{

					int rno;
					cout<<"\t\tEnter New Rollno :";
                    cin>>rno;
                    student[i].setrollno(rno);
                    break;
				}
                case 2:{
                    string name;
                    cout<<"\t\tEnter New Name :";
                    cin.ignore();
                    getline(cin,name);
                    student[i].setname(name);
                    break;
				}

				case 3:{
                    int age;
                    cout<<"\t\tEnter New Age :";
                    cin>>age;
                    student[i].setage(age);
                    break;
				}
				default:cout<<"\t\tInvalid Number"<<endl;	

			}

		}	
        if(!found){
            cout<<"\t\tRecord Not Found"<<endl;
            return;
        }
    }
}

// Function for Deleting a Student : 
void DeleteAStudent(vector<Student> &student){
    string name;
    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin , name);
    for(int i=0;i<student.size();i++){
        if(student[i].getname() == name){
            student.erase((student.begin()+i));
            cout<<"\t\tStudent Removed Successfully"<<endl;
        }
    }
}
int main(){
    // cout<<"Hello World"<<endl;
    vector<Student> student;
    student.push_back(Student(1 , "Anju",20));

    cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\tSTUDENT MANAGMENT SYSTEM"<<endl;
    cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t1 : Add New Student"<<endl;
    cout<<"\t\t\t\t\t2 : Display All Student"<<endl;
    cout<<"\t\t\t\t\t3 : Search Student"<<endl;
    cout<<"\t\t\t\t\t4 : Update Student"<<endl;
    cout<<"\t\t\t\t\t5 : Delete Student"<<endl;
    cout<<"\t\t\t\t\t6 : Exit"<<endl;
    char option;
    do{
        int choice;
        cout<<"Enter your choice : "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                addnewstudent(student);
                break;
            case 2:
                DisplayAllStudent(student);
                break;
            case 3:
                SearchStudent(student);
                break;
            case 4:
                updateStudent(student);
            case 5:
                DeleteAStudent(student);
            case 6:
                exit(1);
            default:
                cout<<"\t\tInvalid Choice------"<<endl;
        }
        cout<<"\t\t\t\tDo You Want to Continue [Yes / No] ? "<<endl;
        cout<<"\t\t\t\t\t\t1Yes: Y/y\n \t\t\t\t\t\tNo : N/n"<<endl;
        cin>>choice;
    }while(option=='Y' || option=='y');

    return 0;
}