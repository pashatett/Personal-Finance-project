#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<Windows.h>
#include<mmsystem.h>
#include <vector>
#include "locale.h"
using namespace std;

class MyBank {
private:
    int nCategory=1;//количество категорий
    int Pin;//пин код
    float BalanceCard = 0;//баланс карты
    float tempBalance = 0;//переменная для трат и пополнения
    int maxDay = 0, maxWeek = 0, maxMonth = 0;//максимальные траты
    string topCategory;//частовыбираемая категория
    char temp;//для выбора варианта ответа
    string FullName, PhoneNumber, BirthDay, SerialAndNumber, Payment;//для регистрации в банке
    int PinCode;//для регистации в банке
    vector<char*>Category;//категории(для трат)
    void Registrate();//вывод регистрации
    void Card();//rabota s cartoy
    void TopTrat();//top trat
    void MainMenu();//glavnoe menu
    void Trata();//то что потрачено
    void TopCategory();//топ категорий по тратам
public:
    void RegistrMenu();//регистрационное меню 
    ~MyBank();
};