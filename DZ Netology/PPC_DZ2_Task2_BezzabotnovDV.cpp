#define _CRT_SECURE_NO_WARNINGS
// Задача 2. Копирование умных массивов

#include <iostream>

class smart_array {
	int* array;
	int size;
	int j = 0;
public:
	smart_array(int size) {
		this->size = size;
		array = new int[size];
		for (int a = 0; a < size; a++)
			array[a] = 0;
	}
	// smart_array(const smart_array &a) = delete; - Запрет конструктора копирования
	// Конструктор копирования
	smart_array(const smart_array& other) : size(other.size) {
		array = new int[size]; // Выделение новой памяти
		for (int i = 0; i < size; ++i) {
			array[i] = other.array[i]; 
		}
	}

	// Оператор присваивания
	smart_array& operator=(const smart_array& other) {
		if (this != &other) { // Проверка на самоприсвоение
			delete[] array; // Освобождение предыдущего массива
			size = other.size;
			array = new int[size]; // Выделение новой памяти
			for (int i = 0; i < size; ++i) {
				array[i] = other.array[i]; // Копирование элементов
			}
		}
		return *this;
	}
	
	/*
	smart_array& operator=(smart_array& other) {
		//delete[] array; // Освобождение предыдущего массива
		this->Copy(other);
		std::cout << "New array: ";
		for (int ni = 0; ni < other.size; ni++) {
			std::cout << array[ni] << ", ";
		}
		std::cout << std::endl;
		//other.~smart_array();
		return *this;
	}

	smart_array& Copy(smart_array &arr) {
		this->~smart_array(); // Освобождение предыдущего массива
		size = arr.size;
		array = new int[size]; // Выделение новой памяти
		for (int ni = 0; ni < size; ni++) {
			array[ni] = arr.array[ni];
		}
		std::cout << std::endl;
		//*this = new_arr;
		//arr.del_smart_array();
		return *this;
	}
	*/
	// Добавление элемента в массив
	void add_element(const int elem) {
		if (j >= size)
			throw std::out_of_range("Array out of ranges");
		else {
			array[j] = elem;
			j++;
		}
	}
	// Печать заданного элемента
	int get_element(const int i) {
		std::cout << "Array: ";
		for (int j = 0; j < size; j++) {
			std::cout << array[j] << ", ";
		}
		std::cout << std::endl;
		if (i >= size)
			throw std::out_of_range("Element out of ranges");
		else {
			return array[i];
		}
	}
	
	// Деструктор
	~smart_array() {
		delete[] array;
	}
};



int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(88);
		arr.add_element(21);
		std::cout << arr.get_element(2) << std::endl;
		
		smart_array new_arr(6);
		new_arr.add_element(44);
		new_arr.add_element(34);
		new_arr.add_element(15);
		new_arr.add_element(66);
		new_arr.add_element(71);
		new_arr.add_element(4);
		std::cout << new_arr.get_element(1) << std::endl;
		//arr.~smart_array();
		arr = new_arr;

		std::cout << arr.get_element(1) << std::endl;
		//arr.del_smart_array();
		//new_arr.del_smart_array();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	system("pause");

	return EXIT_SUCCESS;
}