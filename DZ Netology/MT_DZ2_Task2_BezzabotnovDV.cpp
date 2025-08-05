// Задание 2 Прогресс бар

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <iomanip>
#include <atomic>
#include <sstream>
#include <windows.h>
using namespace std;

// Глобальный мьютекс
mutex global_mutex;

// Функция установки курсора
void set_cursor_position(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Класс для управления прогресс-баром потока
class ProgressBar {
private:
    const int thread_num;      // Номер потока
    const thread::id tid; // Идентификатор потока
    const int length;          // Длина прогресс-бара
    int progress = 0;          // Текущий прогресс
    chrono::time_point<chrono::high_resolution_clock> start;
    int line_position;         // Позиция строки этого потока

public:
    ProgressBar(int num, thread::id id, int len, int pos)
        : thread_num(num), tid(id), length(len), line_position(pos) {
        start = chrono::high_resolution_clock::now();
        print_initial();
    }

    // Вывод начальной информации о потоке
    void print_initial() {
        lock_guard<mutex> lock(global_mutex);
        set_cursor_position(0, line_position);
        cout << "Поток: " << "\t" << thread_num
            << " (ID: " << tid << " ): [";
        for (int i = 0; i < length; i++) cout << " ";
        cout << "]";
        cout.flush();
    }

    void update() {
        if (progress >= length) return;

        progress++;
        lock_guard<mutex> lock(global_mutex);
        set_cursor_position(24 + progress, line_position);
        cout << "#";
        set_cursor_position(24 + length, line_position);
        cout << "\t" << (100 * progress / length) << " %";
        cout.flush();
    }

    // Итоговая информации
    void print_final() {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        lock_guard<mutex> lock(global_mutex);
        set_cursor_position(35 + length, line_position);
        cout << " Время: " << elapsed_seconds.count() << " с";
        cout.flush();
    }

    bool is_complete() const {
        return progress >= length;
    }
};

// Функция, выполняемая потоке
void calculation_task(int thread_num, int progress_length, int line_pos) {
    ProgressBar pb(thread_num, this_thread::get_id(), progress_length, line_pos);

    while (!pb.is_complete()) {
        this_thread::sleep_for(30ms);
        pb.update();
    }
    pb.print_final();
}

int main() {
    setlocale(LC_ALL, "rus");

    size_t num_threads = 4;      // Количество потоков
    int progress_length = 30; // Длина прогресс-бара

    // Очищаем консоль и устанавливаем курсор в начало
    system("cls");
    cout << "Многопоточный расчет с прогресс-барами:" << endl;

    // Создаем вектор потоков
    std::vector<thread> threads;
    threads.reserve(num_threads);

    // Создаем и запускаем потоки
    for (int i = 1; i <= num_threads; ++i) {
        threads.push_back(thread(calculation_task, i, progress_length, 2 + i));
    }

    // Ожидаем завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    // Перемещаем курсор в конец
    set_cursor_position(0, 3 + num_threads);
    cout << endl;
    cout << "Все потоки завершили работу." << endl;

    return 0;
}