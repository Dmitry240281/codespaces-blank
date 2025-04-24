// Задача 1. Обход в глубину

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class Graph {
    int vertices;
    int** adjLists;
    bool* visited;

public:
// Инициализация графа
Graph(int** arr, int vertices) {
    this->vertices = vertices;
    adjLists = arr;
    visited = new bool[vertices];
    for (int b = 0; b < vertices; b++)
        visited[b] = false;
}
// Функция бхода в глубину
void DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex+1 << ' ';
    int* adjList = new int[vertices];
    adjList = adjLists[vertex];
    for (int i = 0; i < vertices; i++) {
        if (adjList[i] == 1 && visited[i] == false) DFS(i);
    }
}
// Вывод массива для теста
void print_array(int** arr) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}
};
// Создание пустого двумерного массива
int** create_array(int v) {
    int** arr = new int* [v];
    for (int i = 0; i < v; i++) {
        arr[i] = new int[v];
    }
    return arr;
}
// Удаление двумерного массива
void delete_array(int** arr, int v) {
    for (int i = 0; i < v; i++) {
        delete[] arr[i]; // удаляем в обратном порядке, сначала ячеки (col) массива arr
    }
    delete[] arr; // потом удаляем строки row
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream fin("in.txt");
    int vertex;
    std::string buff, s;
    if (!fin.is_open()) {
        std::cout << "Файл не нейден. Проверьте наличие и название файла" << std::endl;
        return 0;
    }
    fin >> buff;
    vertex = std::stoi(buff);
    
    
    std::cout << "Количество вершин графа: " << vertex << std::endl;
    std::cout << "Матрица смежности: " << std::endl;
    int** arr_two = create_array(vertex);
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            fin >> s;
            arr_two[i][j] = std::stoi(s);
            cout << arr_two[i][j] << ' ';
        }
        cout << endl;
    }

    Graph G(arr_two, vertex);
    cout << "Порядок обхода вершин: ";
    G.DFS(0);

    delete_array(arr_two, vertex);
    fin.close();

    return EXIT_SUCCESS;
}
