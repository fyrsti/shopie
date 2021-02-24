#pragma once
class Product;

/* 
Отображает товары итерируясь по векторам productCatalog и inventory. 
Имеет параметр hide (по умолчанию false) отвечающий за вывод элементов вектора inventory
*/
void show_information(bool hide = false);


/*
Возвращает true если число pn соблюдает условие 1 <= pn <= max
*/
bool _validate_number_in_range(int pn, int max);

/*
Выполняет подготовку для составления примеров. 
Генерирует 3 случайных уникальных значения в векторе t, случайное значение "c" от 0 до 2 и случайное значение "d" от 0 до 19
*/
void _preprocess_numbers(vector<int>& t, int& c, int& d);

/*
Возвращает значение от 1 до 3
*/
int _get_answer();

/*
Выводит на экран три примера
*/
void visualize_math_problems(int delta, int omega, vector<int> base);

/*
Возвращает номер товара (индекс элемента) в векторе
*/
int _get_product_number(vector<Product*> catlg);

/*
Проверяет значение переменной money для совершения "покупки"
*/
bool _check_account(int pcode);

/*
Перебирает элементы вектора productCatalog, возвращает самую большую цену товара
*/
int _get_max_price();

/*
Подсчитывает шанс на кражу привязываясь к цене вещи которую пользователь пытается украсть
*/
int _calculate_chance(int ch);

/*
Перемещает объект класса Product из вектора from в вектор to
*/
string _transfer_items(int pcode, vector<Product*>& from, vector<Product*>& to);

/*
Итерируется по вектору v, проверяет target на уникальность
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