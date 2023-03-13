#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class MyBank {
    int N = 0;//���������� ����
    int nCategory=1;//���������� ���������

    int n;//����������� �� ������
    float tempBalance = 0;//���������� ��� ���� � ����������

    int maxDay = 0, maxWeek = 0, maxMonth = 0;//������������ �����
    
    char temp;//��� ������ �������� ������
    string topCategory;//��������������� ���������

    string FullName, PhoneNumber, BirthDay, SerialAndNumber, Payment, PinCode;//��� ���������� � �����
    vector<string>Name;//��� �����
    vector<string>Number;//��� ������
    vector<string>BDay;//��� ��� ��������
    vector<string>SandN;//��� ����� � ������
    vector<string>Paym;//��� �����
    vector<string>PCode;//��� ��� ����
    vector<string>CateTop;//��� ��������� � ������ �����
    vector<int>MaxBuy;//������������ ����� �� �����

    vector<char*>Category;//���������(��� ����)
    vector<int>BALANCE;//������� ����
    vector<int>KolBuyCat;//���������� ������� � ���������

    void Registrate();//����� �����������
    void Card(int);//rabota s cartoy
    void MainMenu(int);//glavnoe menu
    void Trata(int);//�� ��� ���������
    void TopCategory();//��� ��������� �� ������
    void TopTrat();//top trat
    void Show();//����� ���� ���� � ������ �� ���
    void SaveToFile();//���������� ����������� � ����
    void Exit();//�����
public:
    void RegistrMenu();//��������������� ���� 
    ~MyBank();
};