﻿/*. Ремонт. Разработать программу, которая по введенным параметрам
рассчитывает стоимость оклейки обой в комнате. Программа
должна содержать следующее меню:
1. Ввод длины и ширины комнаты (м).
2. Ввод количества окон.
3. Ввод количества дверных проемов.
4. Ввод стоимости обойной трубки ($).
5. Расчет площади оклейки (кв. м).
6. Расчет необходимого количества обойных трубок.
7. Расчет стоимости поклейки (с учетом клея).
8. Выход из программы.
Справочные сведения. Окна имеют стандартные размеры
2,15×1,50 м, дверные проемы – 0,90×2,05 м, высоту потолков
принять – 2,60 м. Ширина обойной трубки составляет 50 см.
Стоимость 1 пакета обойного клея равна $2,5, его хватает на 5
трубок. */

#include <stdio.h>
#include <math.h>
#include <locale.h>


float area = 0;       //площадь
int quantity = 0;     //количество


void Area(float dl, float sh, float win, float door)       //считает площадь оклейки и выводит ее значение на экран
{
    area = (5.2 * (dl + sh)) - (3.225 * win) - (1.845 * door);
    printf("Площадь оклейки: %.2f м^2", area);
}

void Pipes()         //высчитывает необходимое количество обойных трубок и выводит на экран
{
    quantity = area / 5;
    float kolvo1 = area / 5;
    if ((kolvo1 - quantity) != 0) quantity ++;
    printf("Необхожимое количество трубок: %d ", quantity);
}

void Cost(float cost)          //высчитывает стоимость поклейки с учетом клея и выводит значение на экран
{
    float stoimost;
    stoimost = (area / 5 * cost) + (area / 10);
    printf("Стоимость поклейки (с учетом клея): %.2f$", stoimost);
}



void main(void)
{
    setlocale(LC_ALL, "Rus");
    float dl = 0, sh = 0,cost = 0;
    float win = 0, door = 0;
    int chooce, a = 1;
    printf("1. Ввод длины и ширины комнаты (м)\n2. Ввод количества окон \n3. Ввод количества дверных проемов.\n4. Ввод стоимости обойной трубки($).\n5. Расчет площади оклейки(кв.м).\n6. Расчет необходимого количества обойных трубок.\n7. Расчет стоимости поклейки(с учетом клея).\n8. Выход из программы.\n");
    do
    {
        do 
        {
            printf("\n");
            rewind(stdin);
        } while (!(scanf_s("%d", &chooce)));
        switch (chooce)
        {
        case 1: {do { printf("Длина(м): "); rewind(stdin); } while (!(scanf_s("%f", &dl)) || dl <= 0); do { printf("Ширина(м): "); rewind(stdin); } while (!(scanf_s("%f", &sh)) || sh <= 0);  } break;
        case 2: {do { printf("Количество окон: "); rewind(stdin); } while (!(scanf_s("%f", &win)) || win <= 0); } break;
        case 3: {do { printf("Количество дверных проемов: "); rewind(stdin); }while(!(scanf_s("%f", &door)) || door <= 0); } break;
        case 4: {do { printf("Стоимость обойной трубки($): "); rewind(stdin); } while (!(scanf_s("%f", &cost)) || cost <= 0); } break;
        case 5: {if (dl == 0 || sh == 0 || win == 0 || door == 0) {printf("Вы ввели недостаточно данных"); break;}Area(dl, sh, win, door);} break;
        case 6: {if (area == 0) { printf("Недостаточно данных для этого вычесления. Рассчитайте сначала площадь оклейки"); break; }Pipes(); } break;
        case 7: {if (quantity == 0 || cost == 0) { printf("Недостаточно данных для этого вычесления. Рассчитайте сначала необходимиое количество обойных трубок"); break;} Cost(cost); } break;
        case 8: a = 0; break;
        default: printf("Введите число от 1 до 8\n");  
        }
    } while (a);
}
