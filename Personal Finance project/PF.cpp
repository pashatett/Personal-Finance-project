#include "PF.h"
void MyBank::RegistrMenu() {
    system("cls");
    cout << "Welcome to DWEAVP Bank!" << endl;
    cout << "What do you want to purchase?" << endl
        <<"1:DEBIT, 2:CREDIT, 3:EXIT" << endl;
    cin >> temp;
    switch (temp){
    case '1':
        Registrate();
        break;
    case '2':
        Registrate();
        break;
    case '3':
        cout << "bye";
        exit(0);
        break;
    default:
        while (true)
            cout << "!!!!daun:)!!!!" << endl;
    }
    Card(N);
}
void MyBank::Registrate() {
    system("cls");
    cout << "Write the full name:" << endl; cin >> FullName;
    cout << "Write the phone number:" << endl; cin >> PhoneNumber;
    do {
        cout << "Date of birth(dd.mm.yyyy):" << endl; cin >> BirthDay;
    } while (BirthDay.length() != 10);
    cout << "Serial and passport number:" << endl; cin >> SerialAndNumber;
    //do{
    cout << "Which payment system do you want? VISA,MasterCard,Mir" << endl; cin >> Payment;
    //} while (Payment.length() != 4 || Payment.length() != 10 || Payment.length() != 3);
    do {
        cout << "Come up with a pin code:" << endl; cin >> PinCode;
    } while (PinCode.length() != 4);

    //для отслеживания всех карт
    Name.push_back(FullName);
    Number.push_back(PhoneNumber);
    BDay.push_back(BirthDay);
    SandN.push_back(SerialAndNumber);
    Paym.push_back(Payment);
    PCode.push_back(PinCode);
    BALANCE.push_back(0);
}
void MyBank::Card(int N) {
    system("cls");
    cout << "Log in:1" << endl;
    cout << "Change pin:2" << endl;
    cout << "Output:3" << endl;
    cin >> temp;
    switch (temp){
    case '1':
        cout << "Write the pin code:" << endl;cin >> PinCode;
        if (PinCode == PCode[N]) {
            break;
        }
        else {
            while (PinCode != PCode[N]) {
                cout << "Nepravilniy PinCode" << endl
                    << "Write the pin code:" << endl; cin >> PinCode;
            }
        }
    case'2':
        cin >> PinCode;
        cout << "Come up with a pin code:" << endl;
        if(PinCode != PCode[N]) {
            while (PinCode != PCode[N]) {
                cout << "Nepravilniy PinCode" << endl
                    << "Write the pin code:" << endl; cin >> PinCode;
            }
        }
        cout << "Write new pin -> "; cin >> PinCode;
        PCode[N] = PinCode;
        cout << "yspewno" << endl;
        break;
    case '3':
        Exit();
        break;
    default:
        while (true)
            cout << "!!!!daun:)!!!!" << endl;
    }
    MainMenu(N);
}
void MyBank::MainMenu(int N) {
    cout << "~~~CATEGORY~~~" << endl
        << "1:Popolnit" << endl
        << "2:Potratit" << endl
        << "3:Top trat" << endl
        << "4:Balance Carti" << endl
        << "5:Show ALL card" << endl
        << "6:Registrate new card" << endl
        << "7:k drugoy karte" << endl
        << "8:Exit" << endl;
    cin >> temp;
    switch (temp){
    case '1':
        system("cls");
        cout << "Na skolko popolnit?" << endl;
        cin >> tempBalance;
        if (BALANCE.empty()==true)
            BALANCE.push_back(tempBalance);
        else
            BALANCE[N] += tempBalance;
        cout << "With commissia:" << tempBalance << ".Rub";
        break;
    case'2':
        Trata(N);
        break;
    case '3':
        TopTrat();
        TopCategory();
        break;
    case '4':
        system("cls");
        cout << "Balance:" << BALANCE[N] << ".Rub" << endl;
        break;
    case '5':
        Show();
        break;
    case '6':
        N++;
        RegistrMenu();
        break;
    case '7':
        cout << "write number card" << endl;
        cin >> n;
        MainMenu(n-1);
        break;
    case '8':
        Exit();
        break;
    default:
        while (true)
            cout << "!!!!LOSHOK!!!!" << endl;
    }
    while (temp != '8')MainMenu(N);
}
void MyBank::Trata(int N) {
    system("cls");
    cout << "Skolko u potratili?" << endl; cin >> tempBalance;
    if (tempBalance > maxDay)maxDay = tempBalance;
    if (tempBalance > BALANCE[N]) {
        cout << endl << "nedostato4no sredstv!!" << endl;
    }
    else {
        BALANCE[N] -= tempBalance;
        char* temp = new char;//для ввода новой категории
        int cat;//для выбора к какой категории отнести
        if (Category.empty() == true) {
            system("cls");
            cout << "K kakoy category u otnesete this traty?(write what you to add)" << endl;
            cin >> temp;
            Category.push_back(temp);
            nCategory++;
            KolBuyCat.push_back(1);
        }
        else {
            system("cls");
            cout << "K kakoy category u otnesete this traty?" << endl;
            for (int i = 0; i < nCategory; i++)
                cout << i + 1 << '.' << Category[i] << " " << KolBuyCat[i] << endl;
            cout << nCategory << "Add new category" << endl; cin >> cat;
            if (cat == nCategory) {
                cout << "write new category" << endl; cin >> temp;
                Category.push_back(temp);
                KolBuyCat.push_back(1);
            }
        }
        temp = nullptr;
    }
}
void MyBank::TopTrat() {
    system("cls");
    cout << "~~~TOP~TRAT~~~" << endl;
    cout << "MAX buy on day -> " << maxDay << endl;
    cout << "MAX buy on week -> " << maxWeek << endl;
    cout << "MAX buy on month -> " << maxMonth << endl;
    MaxBuy.push_back(maxDay);
}
void MyBank::TopCategory() {
    cout << "~~~TOP~CATEGORY~~~" << endl;
    int max=0;
    //почему то не работает((
    //int maxBuyCateg = *max_element(KolBuyCat.begin(), KolBuyCat.end());
    for (int i = 0; i < nCategory; i++)
        if (KolBuyCat[i] > max)max = KolBuyCat[i];

    vector<int>::iterator itr = find(KolBuyCat.begin(), KolBuyCat.end(), max);
    topCategory = Category[distance(KolBuyCat.begin(), itr)];
    cout << topCategory << endl << endl;
    CateTop.push_back(topCategory);
}
void MyBank::Show() {
    system("cls");
    for (int i = 0; i <= N; i++) {
        cout << "Card number " << i + 1 << endl;
        cout << "Name -> " << Name[i] << endl;
        cout << "Number phone -> " << Number[i] << endl;
        cout << "Day of birth -> " << BDay[i] << endl;
        cout << "Serial and number -> " << SandN[i] << endl;
        cout << "Payment -> " << Paym[i] << endl;
        cout << "Pin code -> " << PCode[i] << endl;
        cout << "Balance -> " << BALANCE[i] << endl << endl;
    }
}
void MyBank::SaveToFile() {
    ofstream out;          // поток для записи
    out.open("E:\\Test\\test.txt"); // окрываем файл для записи
    if (out.is_open()) {
        for (int i = 0; i <= N; i++) {
            if(CateTop[i].empty())
            out << "Name -> " << Name[i] << endl;
            out << "Number Phone -> " << Number[i] << endl;
            out << "Birth Day -> " << BDay[i] << endl;
            out << "Serial and Number -> " << SandN[i] << endl;
            out << "Type payment -> " << Paym[i] << endl;
            out << "Last Balance -> " << BALANCE[i] << endl;
            if (CateTop[i].empty())cout << "net categorii" << endl;
            else out << "Top category -> " << CateTop[i] << endl;
            if (MaxBuy.empty())MaxBuy[i] = 0;
            else out << "Top buy -> " << MaxBuy[i] << endl << endl;;
        }
    }
    out.close();
}
void MyBank::Exit() {
    SaveToFile();
    system("cls");
    cout << "Good-bye!" << endl;
    exit(0);
    system("pause");
}
MyBank::~MyBank() {

}