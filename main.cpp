#include"header.h"
using namespace std;
int main()
{

    string choice;
    bool right=0;
    string info;

    cout<<"Choose your cipher:"<<endl;
    cout<<"1->Cesar cipher"<<endl;
    cout<<"2->Morse Code"<<endl;
    cout<<"3->Atbash cipher"<<endl;
    cout<<"4->Cryptosystem RSA"<<endl;
    cout<<"5->My own cipher"<<endl;

    while(!right)
    {
        getline(cin,choice);
        if(choice=="1"||choice=="2"||choice=="3"||choice=="4"||choice=="5")
            right=1;
    }

    cout<<"**********************************************************************************************************************"<<endl;

    if (choice=="1")
    {
        cout<<"Type 1 if you want to get some info about it?"<<endl;
        getline(cin,info);
        if(info=="1")
        {
            Cesar_info();
        }
        cout<<"**********************************************************************************************************************"<<endl;
        Cesar();
    }
    if (choice=="2")
    {
        cout<<"Type 1 if you want to get some info about it?"<<endl;
        getline(cin,info);
        if(info=="1")
        {
            Morse_info();
        }
        cout<<"**********************************************************************************************************************"<<endl;
        Morse();
    }
    if (choice=="3")
    {
        cout<<"Type 1 if you want to get some info about it?"<<endl;
        getline(cin,info);
        if(info=="1")
            Atbash_info();
        Atbash();
    }
    if (choice=="4")
    {
        cout<<"Type 1 if you want to get some info about it?"<<endl;
        getline(cin,info);
        if(info=="1")
        {
            RSA_info();
        }
        cout<<"**********************************************************************************************************************"<<endl;
        RSA();
    }
    if (choice=="5")
    {
        cout<<"Type 1 if you want to get some info about it?"<<endl;
        getline(cin,info);
        if(info=="1")
        {
            My_own_cipher_info();
        }
        cout<<"**********************************************************************************************************************"<<endl;
        My_own_cipher();
    }

    return 0;
}

