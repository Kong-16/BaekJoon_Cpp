#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define MAX_LENGTH 5000
using namespace std;

class Business
{
private:
    char* comp_name;
public:
    Business(char* name = NULL) : comp_name(name){}
    Business(const Business& copy) : comp_name(copy.comp_name) {
        comp_name = new char[strlen(copy.comp_name) + 1];
        strcpy(comp_name, copy.comp_name);
    }
    void show_comp_name();
    ~Business()
    {
        delete[]comp_name;
    }

};

void Business::show_comp_name()
{
    cout << "��ü��: " << comp_name << "\n";
}

int main()
{
    char busi_name1[MAX_LENGTH];
    char* busi_name2 = NULL;
    string s;
    cout << "��ü���� �Է��Ͻÿ� : " << "\n";
    cin >> busi_name1;
    cout << "��ü���� �Է��Ͻÿ� : " << "\n";
    cin >> busi_name2;

    Business copy1;
    Business copy2;

    cout << "��ü�� ����: " << "\n";

    copy1.show_comp_name();
    copy2.show_comp_name();
}