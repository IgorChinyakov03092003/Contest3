#include <iostream>
#include <random>
using namespace std;
void Numbers(int** A, int M, int N) {
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % (100 - 1 + 1) + 1;
        }
    }
}
void Print(int** A, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << "\n";
    }
}
int Summa(int** A, int M, int N) {
    int sum = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                sum += A[i][j];
            }
        }
    }
    return sum;
}
int main()
{
    int M;
    int N;
    std::cin >> M;
    std::cin >> N;
    if ((M <= 0) || (N <= 0)) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int** A;
        A = new int* [M];
        for (int i = 0; i < M; i++) {
            A[i] = new int[N];
        }
        Numbers(A, M, N);
        Print(A, M, N);
        std::cout << "Sum on main diagonal is: " << Summa(A, M, N) << std::endl;
        for (int i = 0; i < M; i++) {
            delete[] A[i];
        }
        delete[] A;
    }
    return 0;
}
