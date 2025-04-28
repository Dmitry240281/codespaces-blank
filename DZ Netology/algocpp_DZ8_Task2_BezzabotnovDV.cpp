// Задача 2. Топологическая сортировка орграфа

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class Graph {
    int vertices;
    int** adjLists;
    bool* visited;
    //int* queue;
    int* adjList;
    int* order;
    int ord = 0;
public:
    // Инициализация графа
    Graph(int** arr, int vertices) {
        this->vertices = vertices;
        adjLists = arr;
        visited = new bool[vertices];
        for (int b = 0; b < vertices; b++)
            visited[b] = false;
        adjList = new int[vertices];
        order = new int[vertices];
        for (int o = 0; o < vertices; o++)
            order[o] = -1;
        //queue = new int[vertices];
        for (int q = 0; q < vertices; q++) {
            
            if (visited[q] == false) {
                DFS(q);
            }
        }
    }
    // Функция бхода в глубину
    void DFS(int vertex) {
        
        visited[vertex] = true;
        //cout << vertex + 1 << endl;
        adjList = adjLists[vertex];
        int n = 0;
                for (int m = 0; m < vertices; m++)
                    n = n + adjList[m];
                if (n > 0) {
                    for (int i = 0; i < vertices; i++) {
                        bool k = false;
                        for (int j = 0; j < vertices; j++) { // Проверка есть ли в массиве order[j] эта вершина
                            if (order[j] == i) k = true;
                        }

                        if (k == false && adjList[i] == 1 && visited[i] == false) {

                            DFS(i);
                        }
                        else {

                        }

                    }
                    for (int f = vertices; f >= 0; f--)
                        order[f] = order[f - 1];
                    order[0] = vertex;
                }
                else {
                    for (int f = vertices; f >= 0; f--)
                        order[f] = order[f - 1];
                    order[0] = vertex;
                }
    }

    void print_order() {
        for (int o = 0; o < vertices; o++)
            cout << order[o]+1 << ' ';
        cout << endl;
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
    
    Graph G(arr_two, vertex);
    cout << "Топологический порядок вершин: ";
    G.print_order();

    delete_array(arr_two, vertex);
    fin.close();

    return EXIT_SUCCESS;
}
