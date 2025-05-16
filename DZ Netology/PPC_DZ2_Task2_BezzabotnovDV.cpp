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
	smart_array& operator=(smart_array& other) {
		this->del_smart_array();
		this->Copy(other);
		std::cout << "New array: ";
		for (int ni = 0; ni < other.size; ni++) {
			std::cout << array[ni] << ", ";
		}
		std::cout << std::endl;
		
		return *this;
	}

	smart_array& Copy(smart_array& arr) {
		
		size = arr.size;
		//smart_array new_arr(size);
		for (int ni = 0; ni < size; ni++) {
			array[ni] = arr.array[ni];
		}
		std::cout << std::endl;
		//*this = new_arr;
		//arr.del_smart_array();
		return *this;
		
	}

	void add_element(int elem) {
		if (j >= size)
			throw std::out_of_range("Array out of ranges");
		else {
			array[j] = elem;
			j++;
		}
	}
	int get_element(int i) {
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
	
	void del_smart_array() {
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

		arr = new_arr;

		std::cout << arr.get_element(1) << std::endl;
		//arr.del_smart_array();
		new_arr.del_smart_array();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	system("pause");

	return EXIT_SUCCESS;
}