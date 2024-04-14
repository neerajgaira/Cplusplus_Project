// Super Market Billing System : 
#include<bits/stdc++.h>
using namespace std;

class Bill{
    private:
    string itemname;
    int itemrate, quantity;
    public:
    Bill():itemname("") , itemrate(0) , quantity(0){};
    void SetItem(string item){
        itemname = item;
    }
    void setRate(int rate){
        itemrate = rate;
    }
    void setquantity(int quant){
        quantity = quant;
    }


    string GetItem(){
        return itemname;
    }
    int GetRate(){
        return itemrate;
    }
    int GetQuantity(){
        return quantity;
    }

};

// Adding an item : 
void addItem(Bill obj){
    bool flag1 = false;
    while(!flag1){
        int choice;
        cout<<"\t 1-Add an Item"<<endl;
        cout<<"\t 2-Close "<<endl<<endl;
        cout<<"Enter Choice : "<<endl;
        cin>>choice;
        if(choice==1){
            string item;
            int rate , quantity;
            cout<<"Enter item name : ";
            cin>>item;
            obj.SetItem(item);

            cout<<"Enter Rate of an item : ";
            cin>>rate;
            obj.setRate(rate);

            cout<<"Enter Quantity of an item : ";
            cin>>quantity;
            obj.setquantity(quantity);
            ofstream out("E:/Market_Bill.txt" , ios::app);  //Adding item in a file
            if(!out){
                cout<<"\tError : File Can't Open!"<<endl;
            }
            else{
                out<<"\t"<<obj.GetItem()<< " : "<<obj.GetRate()<<" : "<<obj.GetQuantity()<<endl<<endl;
                cout<<"Item Added Successfully!"<<endl;
            }
            out.close();
            _sleep(3000);
        }
        else if(choice==2){
            system("cls");
            flag1 = true;
            cout<<"\t Back to Main Menu"<<endl;
            _sleep(3000);
        }
    }
}

// Printing an Item : 
void printbill(){
    system("cls");
    int count = 0;
    bool flag1 = false;
    while(!flag1){
        system("cls");
        int choice;
        cout<<"\t 1 - Add Bill"<<endl;
        cout<<"\t 2 - Close Session"<<endl;
        cin>>choice;
        if(choice==1){
            string item;
            int quant;
            cout<<"Enter Item : ";
            cin>>item;
            cout<<"Enter Quantity : ";
            cin>>quant;

            ifstream in("E:/Market_Bill.txt");
            ofstream out("E:/Bill Temp.txt");
            string line;
            bool found = false;

            while(getline(in , line)){
                stringstream s;
                s<<line;
                string name;
                int rate , quantity;
                char delimeter;
                s>>name>>delimeter>>rate>>delimeter>>quantity;

                if(item == name){
                    found = true;
                    if(quant == quantity){
                        int amount = rate*quantity;
                        cout<<"\t Item | Rate | Quantity | Amount"<<endl;
                        cout<<"\t"<<name<<"\t"<<rate<<"\t"<<quantity<<"\t"<<amount<<endl;
                        int newquant = quantity - quant;
                        quantity = newquant;
                        count+=amount;

                        out<<"\t"<<name<<" : "<<rate<<" : "<<quantity<<endl<<endl;
                    }
                    else{
                        cout<<"\t Sorry"<<item<<" Ended! "<<endl;
                    }
                }            
                else{
                    out<<line;
                }
            }
            if(!found){
                cout<<"\t Item Not Available!"<<endl;
            }
            out.close();
            in.close();
            remove("E:/Market_Bill.txt");
            rename("E:/Bill Temp.txt" , "E:/Market_Bill.txt");
        }
        else if(choice==2){
            flag1 = true;
            cout<<"\t Counting Total Bill"<<endl;
        }
        _sleep(3000);
    }
    system("cls");
    cout<<endl<<endl;
    cout<<"\t Total Bill ----------------------- : "<<count<<endl<<endl;
    cout<<"\t Thank You!"<<endl;
    _sleep(5000);
}
int main(){
    system("cls");
    cout<<"\t\t\t\t\t\t---------------------------------------------------------------------\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tSuper Market Billing System"<<endl;
    cout<<"\t\t\t\t\t\t---------------------------------------------------------------------\t\t\t\t\t\t"<<endl;
    Bill obj;
    bool flag = false;
    cout<<"Welcome To Super Market Billing System : "<<endl;
    cout<<"---------------------------------------"<<endl;
    while(!flag){
        // system("cls");
        int value;
        cout<<"\t1 - Add an Item"<<endl;
        cout<<"\t2 - Print Bill"<<endl;
        cout<<"\t3 - Exit()"<<endl;
        cout<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>value;

        if(value==1){
            system("cls");
            addItem(obj);
            _sleep(3000);
        }
        else if(value==2){
            printbill();
        }
        else if(value==3){
            system("cls");
            flag=true;
            cout<<"Good Luck"<<endl;
            _sleep(3000);
        }
    }
    return 0;
}