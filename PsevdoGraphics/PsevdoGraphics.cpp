#include <iostream>
#include <cmath>
using namespace std;

float func(int i, float dx, float a){
    float x = a + i * dx;
    return x * x;
}
void drawSymbolPlot(func, bottomEdge, topEdge, stringCount) {

}

void printGraphic(int maxPoints) {
    float a = 0.0;
    float b = 10.0;
    float maxSpaces = 60;
    float dx = (b - a) / maxPoints;
    float maxY = -FLT_MAX;
    for (int i = 0; i < maxPoints; i++) {
        float y = func(i, dx, a);
        if (y > maxY) {
            maxY = y;
        }
    }
    for (int i = 0; i < maxPoints; i++) {
        float y = func(i, dx, a);
        float spaces = y * maxSpaces / maxY;
        for (int j = 0; j < spaces - 1; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }

}

int main(int argc, char const *argv[])
{
    printGraphic(10);
    return 0;
}

