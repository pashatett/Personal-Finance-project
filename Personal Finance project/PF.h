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
    int nCategory=1;//���������� ���������
    int Pin;//��� ���
    float BalanceCard = 0;//������ �����
    float tempBalance = 0;//���������� ��� ���� � ����������
    int maxDay = 0, maxWeek = 0, maxMonth = 0;//������������ �����
    string topCategory;//��������������� ���������
    char temp;//��� ������ �������� ������
    string FullName, PhoneNumber, BirthDay, SerialAndNumber, Payment;//��� ����������� � �����
    int PinCode;//��� ���������� � �����
    vector<char*>Category;//���������(��� ����)
    void Registrate();//����� �����������
    void Card();//rabota s cartoy
    void TopTrat();//top trat
    void MainMenu();//glavnoe menu
    void Trata();//�� ��� ���������
    void TopCategory();//��� ��������� �� ������
public:
    void RegistrMenu();//��������������� ���� 
    ~MyBank();
};