#include <iostream>
#include<iomanip>

#define E 2.71828182846


double f(double x, double y)
{
    return -2 * x * y;
}

double wynikAnalityczny(double x)
{
    return pow(E, -pow(x, 2));
}

void metodaEulera(double x, double y, double h)
{
    std::cout << "wartosc x    y obliczone    y analityczne" << std::endl;

    for (int i = 1; i <= 21; i++)
    {
        std::cout << x << "\t\t" << y << "\t\t" << wynikAnalityczny(x) << std::setprecision(4) << std::endl;
        
        y = y + (f(x, y) * h);
        x += h;
    }
}

double metodaRungegoKutty(double x, double y, double h)
{

    double k1, k2, k3, k4;
    std::cout << "wartosc x    y obliczone    y analityczne" << std::endl;
    for (int i = 1; i <= 21; i++)
    {
        std::cout << x << "\t\t" << y << "\t\t" << wynikAnalityczny(x) << std::setprecision(4) << std::endl;
        k1 = h * f(x, y);
        k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x + 1.0 * h, y + 1.0 * k3);
        y = y + (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4);


        x += h; 
    }
    return 0;
}

int main()
{
    double y0 = 1;
    double x0 = 0;
    double h = 0.1;
    std::cout << "Metoda Eulera" << std::endl;
    metodaEulera(x0, y0, h);
    std::cout << "Metoda Rungego-Kutty" << std::endl;
    metodaRungegoKutty(x0, y0, h);

}


