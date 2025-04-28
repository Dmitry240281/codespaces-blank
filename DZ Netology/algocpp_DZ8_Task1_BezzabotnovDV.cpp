// Задача 1. Вывод орграфа на консоль

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class Graph {
    int vertices;
    int** adjLists;
    //bool* visited;
    //int* queue;
    int* adjList;
public:
    // Инициализация графа
    Graph(int** arr, int vertices) {
        this->vertices = vertices;
        adjLists = arr;
        adjList = new int[vertices];
    }
    // Функция бхода в ширину
    void DFS(int vertex) {
        
        for (int v = 0; v < vertices; v++) {
            adjList = adjLists[v];
            cout << v+1 << ": ";
            int k = 0;
            for (int i = 0; i < vertices; i++) {
                k = k + adjList[i];
                if (adjList[i] == 1) {
                    cout << i+1 << ' ';
                }
            }
            if (k == 0) cout << "нет" << endl;
            else cout << endl;
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
        delete[] arr[i];
    }
    delete[] arr;
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
    cout << endl;
    Graph G(arr_two, vertex);
    cout << "Текстовый вид орграфа: " << endl;
    G.DFS(0);

    delete_array(arr_two, vertex);
    fin.close();

    return EXIT_SUCCESS;
}