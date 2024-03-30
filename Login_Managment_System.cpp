// Login Managment System : 
// 1 : Register the User
// 2 : Login User
// 3 : Show User List
// 4 : Search User
// 5 : Delete User
// 6 : Exit

#include<bits/stdc++.h>
#define clrscr() system("cls")
using namespace std;

class User{
    private:
        string username , password;
    public:
        User(string name , string pass){
            username = name;
            password = pass;
        }
    string getUsername(){
        return username;
    }
    string getPassword(){
        return password;
    }
};

class UserManager{
    private:
        vector<User>users; //Object of vector
    public:
        // Function for registering the user : 
        void registeruser(){
            string username , password;
            cout<<"Enter User Name : ";
            cin>>username;
            cout<<endl;
            cout<<"Enter Password : ";
            cin>>password;

            User newuser(username , password);
            users.push_back(newuser);

            cout<<"User Registered Successfully!"<<endl;
        }

        // Function for Login : 
        bool LoginUser(string name , string pass){
            for(int i=0;i<users.size();i++){
                if((users[i].getUsername() == name) && (users[i].getPassword() == pass)){
                    cout<<"Login Sucessfull!"<<endl;
                    return true;
                }
            }
            cout<<"Invalid UserName or Password"<<endl;
            return false;
        }

        // Function for showing user : 
        void showuser(){
            cout<<"User's List"<<endl;
            for(int i=0;i<users.size();i++){
                cout<<users[i].getUsername()<<endl;
            }
        }

        // Function for searching user : 
        void searchuser(string username){
            int flag=0;
            for(int i=0;i<users.size();i++){
                if(users[i].getUsername()==username){
                    // cout<<"User Found ....";
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"User Found....."<<endl;
            }
            else{
                cout<<"User Not Found...."<<endl;
            }
        }

        // Function for deleting user : 
        void deleteuser(string username){
            for(int i=0;i<users.size();i++){
                if(users[i].getUsername()==username){
                    users.erase(users.begin()+i);
                    cout<<"User Removed Sucessfully...."<<endl;
                    break;
                }
            }
        }
};

int main(){
    system("cls");
    cout<<"\t\t\t\t----------------------------------------------------------------------------\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\tLOGIN MANAGMENT SYSTEM"<<endl;
    cout<<"\t\t\t\t----------------------------------------------------------------------------\t\t\t\t"<<endl;
    UserManager usermanager;
    cout<<"\t\t\t\t\t\t\t\t1 : Register User \t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t2 : Login \t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t3 : Show User List \t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t4 : Search User \t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t5 : Delete User \t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t6 : Exit \t"<<endl;
    char ch;
    do{
        int option;
    // cout<<endl<<endl;
        cout<<"Enter Your Choice : ";
        cin>>option;
        switch(option){
            case 1:{
                usermanager.registeruser();
                break;
            }
            case 2:{
                string username , password;
                cout<<"Enter Username : ";
                cin>>username;
                cout<<"Enter Password : ";
                cin>>password;
                usermanager.LoginUser(username , password);
                break;
            }
            case 3:{
                usermanager.showuser();
                break;
            }
            case 4:{
                string username;
                cout<<"Enter Username : ";
                cin>>username;
                usermanager.searchuser(username);
                break;
            }
            case 5:{
                string username;
                cout<<"Enter User Name : ";
                cin>>username;
                usermanager.deleteuser(username);
                break;
            }
            case 6:{
                exit(1);
            }
            default:cout<<"Enter valid number"<<endl;
        }
        cout<<"Do You want to continue ?"<<endl;
        cout<<"Press Y||y to continue or Press N\n to exit"<<endl;
        cin>>ch;
    }while(ch=='Y' || ch=='y');

    return 0;
}
