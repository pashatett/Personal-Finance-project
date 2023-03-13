#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class MyBank {
    int N = 0;//количество карт
    int nCategory=1;//количество категорий

    int n;//перемещение по картам
    float tempBalance = 0;//переменная для трат и пополнения

    int maxDay = 0, maxWeek = 0, maxMonth = 0;//максимальные траты
    
    char temp;//для выбора варианта ответа
    string topCategory;//частовыбираемая категория

    string FullName, PhoneNumber, BirthDay, SerialAndNumber, Payment, PinCode;//для регистации в банке
    vector<string>Name;//все имена
    vector<string>Number;//все номера
    vector<string>BDay;//все дни рождения
    vector<string>SandN;//все серии и номера
    vector<string>Paym;//все карты
    vector<string>PCode;//все пин коды
    vector<string>CateTop;//топ категории у каждой карты
    vector<int>MaxBuy;//максимальные траты по карте

    vector<char*>Category;//категории(для трат)
    vector<int>BALANCE;//балансы карт
    vector<int>KolBuyCat;//количество покупок в категории

    void Registrate();//вывод регистрации
    void Card(int);//rabota s cartoy
    void MainMenu(int);//glavnoe menu
    void Trata(int);//то что потрачено
    void TopCategory();//топ категорий по тратам
    void TopTrat();//top trat
    void Show();//показ всех карт и данных по ним
    void SaveToFile();//сохранение результатов в файл
    void Exit();//выход
public:
    void RegistrMenu();//регистрационное меню 
    ~MyBank();
};