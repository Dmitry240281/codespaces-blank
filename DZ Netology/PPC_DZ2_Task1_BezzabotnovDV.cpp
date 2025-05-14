// Задача 1. Умный массив

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
	void add_element(int elem) {
		if(j>=size)
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
		if(i>=size)
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
		smart_array arr(6);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(2) << std::endl;
		arr.add_element(999);
		std::cout << arr.get_element(5) << std::endl;
		arr.add_element(88);
		std::cout << arr.get_element(4) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

