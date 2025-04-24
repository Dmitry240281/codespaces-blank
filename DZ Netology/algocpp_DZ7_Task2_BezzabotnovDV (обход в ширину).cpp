//Задача 2 Обход в ширину

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class Graph {
    int vertices;
    int** adjLists;
    bool* visited;
    int* queue;
public:
    // Инициализация графа
    Graph(int** arr, int vertices) {
        this->vertices = vertices;
        adjLists = arr;
        visited = new bool[vertices];
        for (int b = 0; b < vertices; b++)
            visited[b] = false;
        queue = new int[vertices];
        for (int q = 0; q < vertices; q++)
            queue[q] = 0;
    }
    // Функция бхода в ширину
    void DFS(int vertex) {
        int* adjList = new int[vertices];
        adjList = adjLists[vertex];
        int i = 0;
        queue[i] = vertex;
        i++;
            for (int v = 0; v < vertices; v++) {
                if (adjList[v] == 1 && visited[v] == false) {
                    queue[i] = v;
                    i++;
                }
                if (i > 0) {
                    int q = 0;
                    while (q < vertices) {
                        adjList = adjLists[queue[q]];
                        visited[queue[q]] = true;
                        for (int v = 0; v < vertices; v++) {
                            bool k = false;
                            for (int j = 0; j < vertices; j++) {
                                if (queue[j] == v) k = true;
                            }
                            if (k == false && adjList[v] == 1 && visited[v] == false) {
                                queue[i] = v;
                                i++;
                            }
                        }
                        q++;
                    }
                }
            }
            for (int m = 0; m < vertices; m++)
                cout << queue[m]+1 << ' ';
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
        delete[] arr[i]; 
    }
    delete[] arr; 
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream fin("in.txt");
    int vertex;
    int ent = -1;
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
    while (ent != 0) {
        cout << "Введите номер вершины, с которой начнётся обход (0 - выход): ";
        cin >> ent;
        
        if (ent > vertex || ent < 1) {
            cout << "Ошибка! Ведите другое число" << endl;

        }
        else break;
    }
    ent--;
        Graph G(arr_two, vertex);
        cout << "Порядок обхода вершин: ";
        G.DFS(ent);
    
    delete_array(arr_two, vertex);
    fin.close();

    return EXIT_SUCCESS;
}