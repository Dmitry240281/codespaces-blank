// Задание 2
// Параллельные вычисления

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void SumTwoVectors(vector<int> sumvec, vector<int>& vec1, vector<int>& vec2, size_t start_index, size_t end_index) {
    
    for (int i = start_index; i < end_index; ++i)
    {
        sumvec.push_back(vec1[i] + vec2[i]);
    }

}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << "\n\n";
    cout << "\t\t1'000" << "\t\t10'000" << "\t\t100'000" << "\t\t1'000'000" << endl;
    
    vector<int> vector1;
    vector<int> vector2;
    
    vector<int> num_threads{ 1, 2, 4, 8, 16 }; // Заданное киличество потоков
    
    vector<int> size_vector{ 1'000, 10'000, 100'000, 1'000'000 }; // размер векторов

    for (auto& count_thr : num_threads)
    {
        cout << endl << count_thr << " ядер\t\t";

        for (auto& count_vec : size_vector)
        {
            vector1.resize(count_vec, 1);
            vector2.resize(count_vec, 1);
            vector<std::thread> threads;
            vector<int> sum_vectors(count_vec, 0);

            int part_size = count_vec / count_thr;

            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < count_thr; i++)
            {
                //vector<int> new_vector1;
                //vector<int> new_vector2;
                int right_border = 0;
                
                if (i != count_thr - 1)
                {
                    right_border = part_size * (i + 1);
                }
                else
                {
                    right_border = count_vec;
                }
                
                //right_border = count_vec;
                //for (int j = part_size * i; j < right_border; ++j)
                //{
                //    new_vector1.push_back(vector1.at(j));
                //    new_vector2.push_back(vector2.at(j));
                //}

                threads.push_back(thread(SumTwoVectors, ref(sum_vectors), ref(vector1), ref(vector2), (part_size * i), right_border));
            }
            for (auto& it : threads)
            {
                it.join();
            }

            auto end = std::chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << elapsed_seconds.count() << " мс\t";
        }
        cout << endl;
    }

    return 0;
}

