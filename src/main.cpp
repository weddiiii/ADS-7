// Copyright 2022 NNTU-CS
#include <fstream>
#include <random>
#include "train.h"

int main() {
    std::ofstream out("data.csv");

    out << "n,off,on,random\n";

    std::mt19937 gen(42);
    std::uniform_int_distribution<> dist(0, 1);

    for (int n = 2; n <= 200; ++n) {
        // Все выключены
        Train t1;
        for (int i = 0; i < n; ++i)
            t1.addCar(false);
        t1.getLength();

        // Все включены
        Train t2;
        for (int i = 0; i < n; ++i)
            t2.addCar(true);
        t2.getLength();

        // Случайное распределение
        Train t3;
        for (int i = 0; i < n; ++i)
            t3.addCar(dist(gen));
        t3.getLength();

        out << n << ","
            << t1.getOpCount() << ","
            << t2.getOpCount() << ","
            << t3.getOpCount() << "\n";
    }

    return 0;
}
