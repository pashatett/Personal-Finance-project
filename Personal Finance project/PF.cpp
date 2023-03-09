#include "PF.h"
void MyBank::Registrate() {
    system("cls");
    cout << "Write the full name:" << endl; cin >> FullName;
    cout << "Write the phone number:" << endl; cin >> PhoneNumber;
    cout << "Date of birth:" << endl; cin >> BirthDay;
    cout << "Serial and passport number:" << endl; cin >> SerialAndNumber;
    cout << "Which payment system do you want? VISA,MasterCard,Mir" << endl; cin >> Payment;
    cout << "Come up with a pin code:" << endl; cin >> PinCode; Pin = PinCode;
}
void MyBank::RegistrMenu() {
    cout << "Welcome to DWEAVP Bank!" << endl;
    cout << "What do you want to purchase? 1:debit, 2:credit" << endl;
    cin >> temp;
    switch (temp){
    case '1':
        Registrate();
        break;
    case '2':
        Registrate();
        break;
    default:
        while (true)
            cout << "!!!!LOSHOK!!!!" << endl;
    }
    Card();
}
void MyBank::Card() {
    int ttg = 0;
    system("cls");
    cout << "Log in:1" << endl;
    cout << "Change pin:2" << endl;
    cout << "Output:3" << endl;
    cin >> temp;
    switch (temp){
    case '1':
        cout << "Write the pin code:" << endl;cin >> PinCode;
        if (Pin == PinCode) {
            break;
        }
        else {
            while (PinCode != Pin) {
                cout << "Nepravilniy PinCode" << endl
                    << "Write the pin code:" << endl; cin >> PinCode;
            }
        }
    case'2':
        cin >> PinCode;
        cout << "Come up with a pin code:" << endl;
        if (Pin == PinCode)
            ttg = 1;
        break;
    case '3':
        system("cls");
        cout << "Good-bye!" << endl;
        exit(0);
        system("pause");
        break;
    default:
        while (true)
            cout << "!!!!LOSHOK!!!!" << endl;
    }
    MainMenu();
}
void MyBank::MainMenu() {
    cout << "~~~CATEGORY~~~" << endl
        << "1:Popolnit" << endl
        << "2:Potratit" << endl
        << "3:Top trat" << endl
        << "4:Balance Carti" << endl
        << "5:Exit" << endl;
    cin >> temp;
    switch (temp){
    case '1':
        system("cls");
        cout << "Na skolko popolnit?" << endl;
        cin >> tempBalance;
        BalanceCard += tempBalance;
        cout << "With commissia:" << tempBalance << ".Rub";
        break;
    case'2':
        system("cls");
        Trata();
        break;
    case '3':

        TopTrat();
        TopCategory();
        break;
    case '4':
        system("cls");
        cout << "Balance:" << BalanceCard << ".Rub" << endl;
        break;
    case '5':
        system("cls");
        cout << "Good-bye!" << endl;
        exit(0);
        system("pause");
    default:
        while (true)
            cout << "!!!!LOSHOK!!!!" << endl;
    }
}
void MyBank::Trata() {
    cout << "Skolko u potratili?" << endl; cin >> tempBalance;
    if (tempBalance > maxDay)maxDay = tempBalance;
    BalanceCard -= tempBalance;
    char* temp = new char;//для ввода новой категории
    int cat;//для выбора к какой категории отнести
    if (Category.empty() == true) {
        system("cls");
        cout << "K kakoy category u otnesete this traty?(write what you to add)" << endl;
        cin >> temp;
        Category.push_back(temp);
        nCategory++;
    }
    else {
        system("cls");
        cout << "K kakoy category u otnesete this traty?";
        for (int i = 0; i < nCategory; i++)
            cout << i + 1 << '.' << Category[i] << endl;
        cout <<nCategory<< "Add new category" << endl; cin >> cat;
        if (cat == nCategory) {
            cout << "write new category" << endl; cin >> temp;
            Category.push_back(temp);
        }
    }
    temp = nullptr;
}
void MyBank::TopCategory() {
    cout << "~~~TOP~CATEGORY~~~" << endl;
    cout << topCategory << endl;;
}
void MyBank::TopTrat() {
    system("cls");
    cout << "~~~TOP~TRAT~~~" << endl;
    cout << "MAX buy on day -> " << maxDay << endl;
    cout << "MAX buy on week -> " << maxWeek << endl;
    cout << "MAX buy on month -> " << maxMonth << endl;
}
MyBank::~MyBank() {
    
}
void SaveToFile() {
    int size;
    fstream f("E:\\Test\\test.txt", ios::out | ios::binary | ios::app);
    if (!f)cout << "error open\n";

    f.write((char*)&, sizeof(int));
    size = strlen(name);
    f.write((char*)&size, sizeof(int));
    f.write((char*)name, size * sizeof(char));

    size = strlen(surname);
    f.write((char*)&size, sizeof(int));
    f.write((char*)surname, size * sizeof(char));

    f.close();
}