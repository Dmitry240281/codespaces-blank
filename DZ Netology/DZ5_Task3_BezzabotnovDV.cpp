/* Задача 3. Двумерный массив
Напишите программу, которая создаёт и инициализирует двумерный 
массив целых чисел размером 3х6, выводит на экран все элементы 
массива в виде таблицы, находит индексы минимального и максимального 
элементов массива и выводит их на экран.
Числа для заполнения массива придумайте сами.
Чтобы элементы массива выводились равномерно, разделяйте их символом 
табуляции \t вместо пробела внутри одной строки.
*/

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int max_num, min_num, max_i, max_j, min_i, min_j;    
    int arr2[3][6] = { {5,7,12,98,17,-5},{51,12,108,17,88,21},{14,88,-2,16,45,91} };
    std::cout << "Массив: " << std::endl;
    max_num = arr2[0][0];
    min_num = arr2[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << arr2[i][j] << '\t';
            if (max_num < arr2[i][j])
            {
                max_num = arr2[i][j];
                max_i = i;
                max_j = j;
            }
            if (min_num > arr2[i][j])
            {
                min_num = arr2[i][j];
                min_i = i;
                min_j = j;
            }   
        }
        std::cout << std::endl;
    }
    std::cout << "Индекс минимального элемента: " << min_i << ' ' << min_j << std::endl;
    std::cout << "Индекс максимального элемента: " << max_i << ' ' << max_j << std::endl;
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
    
}
