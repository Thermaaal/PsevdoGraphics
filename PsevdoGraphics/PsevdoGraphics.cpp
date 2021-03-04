#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

double linear(double x) {
    return x;
}
double parabola(double x) {
    return x * x;
}
double cube(double x) {
    return x * x * x;
}
/// <summary>
/// Функция преобразования чисел в string и подсчет кол-ва символов
/// </summary>
/// <param name="i">переменная</param>
/// <returns>Кол-во символов</returns>
int Size(float i) { 
    ostringstream ostr;
    ostr << i;
    string str = ostr.str();
    int iSize = str.size();
    return iSize;
}

/// <summary>
/// Функция отрисовки графика заданной функции
/// </summary>
/// <param name="func">- функция графика</param>
/// <param name="bottomEdge">- нижнее значение отрезка функции</param>
/// <param name="topEdge">- верхнеезначение отрезка функции</param>
/// <param name="stringCount">- кол-во точек на графике</param>
void drawSymbolPlot(double (&func)(double),double bottomEdge, double topEdge, int stringCount) {
    int maxiSize = 5;
    double dx = (topEdge - bottomEdge) / stringCount;
    double firstCoordinate = 0, minY = DBL_MAX, maxY = DBL_MIN;
    for (int i = bottomEdge; i <= topEdge; i += dx) {
        i = round(i * 100) / 100;
        double y = trunc(func(i));
        if (y < firstCoordinate) { // минимальное значение графика (по умолчанию нуль)
            firstCoordinate = y;
        } if (y < minY) { // минимальное значение функции
            minY = y;
        } if (y > maxY) { // максимальное значение функции
            maxY = y;
        }
    }

    // отрисовка верхней грани рамки
    for (int i = 0; i <= maxiSize +1; i++) {
        cout << " ";
    }
    for (int i = 0; i <= maxY - minY+5; i++) {
        cout << "_";
    }
    cout << endl;

    // отрисовка пробела между графиком и рамкой 
    for (int i = 0; i <= maxiSize; i++) {
        cout << " ";
    }
    cout << "| ";
    if (topEdge < 0 or bottomEdge > 0) { // если ось y не проходит через график, то ось отрисовывается над графиком
        for (int i = 0; i <= maxY - minY; i++) {
            cout << "-";
        }
    cout << "> y |";    
    } else {
        for (int i = 0; i <= maxY - minY; i++) {
            cout << " ";
        }
        cout << "    |";
    }
    cout << endl;

    // цикл подсчета значение и отрисовки графика
    for (float i = bottomEdge; i <= topEdge; i = i + dx) {
        i = round(i * 100) / 100; // округление значения i до сотых
        double y = fabs(firstCoordinate) + trunc(func(i));
        for (int j = 0; j <= maxiSize - Size(i); j++) { // все значения i выводятся с одинаковым кол-вом пробелов
            cout << " ";                                // учитывая кол-во символов числа i
        }
        cout << i << "| "; // вывод значений по оси х и отделение от графика линией 

        // начало цикла отрисовки 
        for (int j = 0; j <= maxY - minY; j++) { 
            if (j == y){ // отрисовка точки на графике (если минимум/максимум то рисуется #)
                if ((j == 0 and (i == topEdge or i == bottomEdge)) or 
                        (j == fabs(minY) and i == 0) or j == maxY - minY) {
                    cout << "#";
                } else {
                    cout << "*";
                } 
            } 
            else if (j != fabs(firstCoordinate)) { // проверка не является ли осью х
                if (i == 0) { // отрисовка оси у
                    cout << "-"; 
                } 
                else { // просто пробелы 
                    cout << " ";
                }
            } 
            else { // отрисовка оси х
                cout << ":";
            }
        } 
        if (i == 0) { // добавление в конце оси у направляющей стрелки и название оси
            cout << "> y |";
        } 
        else {
            cout << "    |";
        }
        cout << endl;
    }
    // отрисовка последней линии 
    for (int i = 0; i <= maxiSize; i ++) { 
        cout << " ";                                               
    }
    cout << "| ";
    for (int i = 0; i < fabs(firstCoordinate); i++) {
        cout << " ";
    }
    cout << "V x"; // добавление направляющей стрелки оси х и название
    for (int i = 0; i <= maxY +1; i++) {
        cout << " ";
    }
    cout << "|" << endl;

    // отрисовка нижней грани рамки
    for (int i = 0; i <= maxiSize; i++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i <= maxY - minY+5; i++) {
        cout << "_";
    }
    cout << "|" << endl << endl; // конец графика
}

int main(){
    drawSymbolPlot(linear, -5, 5, 10);
    drawSymbolPlot(parabola, -5, 5, 20);
    drawSymbolPlot(cube, -3.5, 3.5, 20);
    return 0;
}
