// Лабораторная работа №10 Вариант 8
//
// Оптимизируйте код лабораторной работы №9 
// с целью повышения читаемости и возможности создавать произвольное количество фигур.
// 
// Создайте N (0<N<100) кругов. 
// Перемещайте их из исходного положения вверх до конца экрана с разной скоростью. 
// При достижении конца экрана остановите фигуры.

#include <thread>
#include <chrono>
#include <Math.h>
#include <Circle.hpp>

using namespace std::chrono_literals;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 500

int main()
{
    const int N = 15; // Количество кругов

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), L"Первая программа");

    sm::Circle circles[N];
    for (int i = 0; i < N; i++) {
        float R = 15.0;
        float x = (WINDOW_WIDTH / N) * i + WINDOW_WIDTH / (2 * N) - R;
        float y = WINDOW_HEIGTH - R*2;
        circles[i].SetPosition(x, y);
        circles[i].SetRaduis(R);
        circles[i].SetMoveVelocity_Y(- N + i*0.5);
    }
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for (int i = 0; i < N; i++) {
            float y = circles[i].GetY(),
                vel = circles[i].GetVelocity_Y();
            if (vel != 0) {
                if (y <= abs(vel)) {
                    circles[i].SetMoveVelocity_Y(0);
                    circles[i].SetY(0);
                }
                circles[i].Move_Y();
            }
            window.draw(circles[i].GetShape());
        }

        std::this_thread::sleep_for(40ms);
        window.display();
    }

    return 0;
}