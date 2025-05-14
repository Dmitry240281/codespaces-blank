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
		//int new_size;
		this->size = other.size;
		//smart_array New_array(new_size);
		std::cout << "New size = " << size << std::endl;
		std::cout << "New array: ";
		for (int ni = 0; ni < size; ni++) {
			array[ni] = other.array[ni];
			std::cout << array[ni] << ", ";
		}
		std::cout << std::endl;
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
		std::cout << arr.get_element(2) << std::endl;
		
		smart_array new_arr(2);
		new_arr.add_element(44);
		new_arr.add_element(34);
		std::cout << new_arr.get_element(1) << std::endl;

		arr = new_arr;

		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}