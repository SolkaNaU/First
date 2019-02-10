#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{ 
    char str; 
    int count = 0; // кол-вo символов
    char stroka[100]; // массив, в который будут записаны символы 
    
    ifstream fin("input.txt"); // открываем файл
    // посимвольно считываем 
    while((fin.get(str)) && (!fin.eof()))
    {
        stroka[count] = str;
        count++;
    }
 
    int countZero = 0; // счётчик 
    int zero[50]; // массив, каждый элемент которого будет равен количеству нулей от одной ближайшей единицы до другой
 
    int j = 0;
    // проходим по массиву stroka, создавая при этом массив zero, о содержимом которого было сказано выше
    for(int i = 0; i < count; i++)
    {
        if (stroka[i] == '0')
            countZero++;
        else
        {
            zero[j] = countZero;
            countZero = 0;
            j++;
        }
    }
 
    // в массиве zero находим максимум(это и будет ответ)  и записываем его в output.txt
    int max = zero[0];
    for(int i = 0; i < j; i++)
    {
        if (zero[i] > max)
            max = zero[i];
    }
 
    ofstream fout("output.txt");
    fout << max;
 
    fin.close();
    fout.close();
    return 0;
}
