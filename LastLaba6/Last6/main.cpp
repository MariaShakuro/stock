#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QtAlgorithms>
#include <QList>
#include<QDebug>

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const QList<int> &qList) {
    qDebug() << "Состояние списка:";
    for (const int &x : qList) {
        qDebug() << x;
    }
}
QList<int> stdListToQList(const std::list<int>& stdList) {
    QList<int> qList;
    for (const auto& x : stdList) {
        qList.append(x);
    }
    return qList;
}

/*std::list<int> qListToStdList(const QList<int>& qList) {
    std::list<int> stdList;
    for (const auto& x: qList) {
        stdList.push_back(x);
    }
    return stdList;
}*/
int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"RUS");
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
   QTextStream cin(stdin);


   /////////////////////////////////////
   QList<quint16> List;
   List << 0b11001100 << 0b10101010 << 0b11110000;
   for (const quint16 &value : List) {
       uint bitCount = qPopulationCount(value);
       qDebug() << "Value:" << value << "Bit Count:" << bitCount;
   }
   ///////////////////////////////////////
   std::list<int> stdList;//=qListToStdList(qList);
   QList<int> qList = stdListToQList(stdList);

    int choice;
    int x;


        qDebug() << "Меню:";
        qDebug() << "1. Просмотреть состояние списка";
        qDebug() << "2. Добавить элемент в начало списка";
        qDebug() << "3. Добавить несколько элементов из массива";
        qDebug() << "4. Удалить элемент по индексу";
        qDebug() << "5. Разделить элементы на две группы";
        qDebug() << "6. Увеличить все элементы на X,алгоритм(transform)";
        qDebug() << "7. Выход из программы";
        qDebug()<<"_____________________________";
        qDebug()<<"\n";

        do{
        std::cin >> choice;
        switch (choice) {
        case 1:
            printList(qList);
            break;
        case 2:
            qDebug() << "Введите элемент для добавления в начало списка:";
            std::cin >> x;
            qList.prepend(x);
            break;
        case 3:
            int arraySize;
            qDebug() << "Введите размер массива:";
            std::cin >> arraySize;
            qDebug() << "Введите элементы массива:";
            for (int i = 0; i < arraySize; ++i) {
                std::cin >> x;
                qList.append(x);
            }
            break;
        case 4:
            int x;
            qDebug() << "Введите  индекс элемента для удаления:";
            std::cin >> x;


             if (x >= 0 && x < qList.size()) {
                    qList.takeAt(x); // Удаление элемента по индексу
                 qDebug() << "Элемент удален";
            } else {
                qDebug() << "Неверный элемент";
            }
            break;
        case 5:

            // Сортировка списка с использованием std::sort
            std::sort(qList.begin(), qList.end(),std::greater<int>());
            qList.insert(qList.size()/2, 0);
            qDebug() << "Отсортированный список:";
            for (const int &x : qList) {
                     qDebug() << x;
            }
            break;

        case 6:
            qDebug() << "Введите число X для увеличения всех элементов:";
            std::cin >> x;
            std::transform(qList.begin(), qList.end(), qList.begin(), [x](int n) { return n + x; });
            break;  
        default:
            return 0;
        }
       } while (choice != 7);
        return 0;
    return a.exec();
}



