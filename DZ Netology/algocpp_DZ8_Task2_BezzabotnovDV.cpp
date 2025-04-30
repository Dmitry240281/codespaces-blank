// Задача 2. Топологическая сортировка орграфа

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;	// Количество вершин
    list<int>* adj; //  Указатель на массив, содержащий список смежности
public:
    Graph(int V);
    void addEdge(int** arr_two);
    void DFSUtil(int v, bool visited[], stack<int>& Stack);
    void DFS();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
// Функция для добавления ребра в граф
void Graph::addEdge(int** arr_two) {
    int v = 0;
    int w = 0;
    for (int i = 0; i < V; i++) {
        v = i;
        for (int j = 0; j < V; j++) {
            if (arr_two[i][j] == 1) {
                w = j;
                adj[v].push_back(w);
            }
        }
    }
}
// Рекурсивная функция, используемая topologicalSort
void Graph::DFSUtil(int v, bool visited[], stack<int>& Stack) {
    visited[v] = true; // Помечаем текущий узел как посещенный
    list<int>::iterator i; // Рекурсивно вызываем функцию для всех смежных вершин
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, Stack);
    Stack.push(v); // Добавляем текущую вершину в стек с результатом
}
// Функция для поиска топологической сортировки. 
// Рекурсивно использует topologicalSortUtil()
void Graph::DFS() {
    stack<int> Stack;
    bool* visited = new bool[V]; // Помечаем все вершины как непосещенные
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Вызываем рекурсивную вспомогательную функцию 
    // для поиска топологической сортировки для каждой вершины
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited, Stack);
    // Выводим содержимое стека
    while (Stack.empty() == false)     {
        cout << Stack.top()+1 << " ";
        Stack.pop();
    }
}

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

    Graph G(vertex);
    G.addEdge(arr_two);
    cout << "Топологический порядок вершин: ";
    G.DFS();

    delete_array(arr_two, vertex);
    fin.close();

    return EXIT_SUCCESS;
}
