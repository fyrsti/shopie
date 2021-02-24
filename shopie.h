#pragma once
class Product;

/* 
���������� ������ ���������� �� �������� productCatalog � inventory. 
����� �������� hide (�� ��������� false) ���������� �� ����� ��������� ������� inventory
*/
void show_information(bool hide = false);


/*
���������� true ���� ����� pn ��������� ������� 1 <= pn <= max
*/
bool _validate_number_in_range(int pn, int max);

/*
��������� ���������� ��� ����������� ��������. 
���������� 3 ��������� ���������� �������� � ������� t, ��������� �������� "c" �� 0 �� 2 � ��������� �������� "d" �� 0 �� 19
*/
void _preprocess_numbers(vector<int>& t, int& c, int& d);

/*
���������� �������� �� 1 �� 3
*/
int _get_answer();

/*
������� �� ����� ��� �������
*/
void visualize_math_problems(int delta, int omega, vector<int> base);

/*
���������� ����� ������ (������ ��������) � �������
*/
int _get_product_number(vector<Product*> catlg);

/*
��������� �������� ���������� money ��� ���������� "�������"
*/
bool _check_account(int pcode);

/*
���������� �������� ������� productCatalog, ���������� ����� ������� ���� ������
*/
int _get_max_price();

/*
������������ ���� �� ����� ������������ � ���� ���� ������� ������������ �������� �������
*/
int _calculate_chance(int ch);

/*
���������� ������ ������ Product �� ������� from � ������ to
*/
string _transfer_items(int pcode, vector<Product*>& from, vector<Product*>& to);

/*
����������� �� ������� v, ��������� target �� ������������
*/
bool _antirepeat(vector<int> v, int target);


void buy_product();
void sell_product();
void earn_salary();
void try_to_steal();

void timer(int& st);

template <typename T>
void input(string text, T& destination);

enum ACTIONS;

int money{ 0 };
vector<Product*> productCatalog;
vector<Product*> inventory;