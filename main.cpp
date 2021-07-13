#include <iostream>
#include <windows.h>
#include "Console.h"
#include <random>
#define MAX 40
using namespace std;
class Obstacle;
// Class
class Object {
protected:
    int x = 0, y = 0;
public:
    Object() {};
    ~Object() {};
    void SetXY(int a, int b) { x = a; y = b; }
    void PrintObject() {
        GotoXY(x, y);
        cout << "";  //사람모양 유니코드
    }
    friend bool HitBox(Object* T, Obstacle S);
};
class Obstacle {
protected:
    int x = 0, y = 0;
public:
    Obstacle() {};
    ~Obstacle() {};
    void x_SetXY(int a, int b) { x = a; y = b; }
    void PrintObstacle() {
        GotoXY(x, y);
        cout << "☆";
    }
    friend bool HitBox(Object* T, Obstacle S);
};

//function
bool HitBox(Object* T, Obstacle S);
void Menupage(void);
void Playgame(void);
int Menu_(int y);
void Print_Bar(int time);
void Scorepage(int score);
//function
int main()
{
    SetConsoleSize(80, 30);//콘솔창 사이즈 조절
    bool B_Cursor = false;//커서 깜빡이는거 없애주기
    SetCursor(B_Cursor);
    Menupage();

    return 0;
}
void Menupage(void)
{

    int y = 1;
    while (1) {
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            y--;
            if (y < 1)y = 1;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            y++;
            if (y > 2)y = 2;
        }

        int mode;
        mode = Menu_(y);
        if (mode == 1 && (GetAsyncKeyState(VK_RETURN) & 0x8000)) { Playgame(); }
        if (mode == 2 && (GetAsyncKeyState(VK_RETURN) & 0x8000)) { Clear(); break; }
        Sleep(10);
        Clear();
    }
}
int Menu_(int y) {
    GotoXY(34, 10);
    cout << "< Menu >";
    GotoXY(32, 12);
    cout << "1. Play Game";
    GotoXY(32, 14);
    cout << "2. Exit Game";
    if (y == 1) {
        GotoXY(29, 12);
        cout << ">>";
        return 1;
    }
    if (y == 2) {
        GotoXY(29, 14);
        cout << ">>";
        return 2;
    }
}
void Print_Bar(int time)
{
    GotoXY(67, 0);
    cout << "score : " << time;
    GotoXY(0, 1);
    cout << "--------------------------------------------------------------------------------";
    GotoXY(1, 0);
    cout << "Stop game : press the \"ESC\" key";
    GotoXY(0, 29);
    cout << "--------------------------------------------------------------------------------";
}
bool HitBox(Object* T, Obstacle S)
{
    if (T->x == S.x && T->y == S.y)return true;
    else return false;
}
void Scorepage(int score)
{
    while (1) {
        Clear();
        GotoXY(30, 12);
        cout << "score : " << score;
        GotoXY(30, 14);
        cout << "Press \"ESC\"key return to Memu";
        if (GetAsyncKeyState(VK_ESCAPE))break;
        Sleep(20);
    }
}
void Playgame(void)
{
    Object* T = new Object();
    int x = 37, y = 14;
    double i = 0;//score point

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 78);

    int Rx[MAX] = { 0 };
    int Oy[MAX] = { 2, };
    bool obs[MAX] = { false };

    Obstacle* O = new Obstacle[MAX]; //가로범위 0~78 세로범위 2~29
    bool break_loop = false;
    while (1) {
        Clear();
        for (int j = 0; j < MAX; j++) {
            if (!obs[j]) {
                Rx[j] = dis(gen);
                Oy[j] = 2;
                obs[j] = true;
                break;
            }
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            y--;
            if (y < 2)y = 2;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            y++;
            if (y > 28)y = 28;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            x--;
            if (x < 0)x = 0;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            x++;
            if (x > 78)x = 78;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { delete T; delete[] O; break; }

        i += 0.05;
        int k = (int)i;//score point

        Print_Bar(k);
        T->SetXY(x, y);
        T->PrintObject();

        for (int j = 0; j < MAX; j++) {
            if (obs[j]) {
                O[j].x_SetXY(Rx[j], Oy[j]);
                O[j].PrintObstacle();
                Oy[j]++;
                if (Oy[j] > 29) obs[j] = false;
            }
        }

        bool C[MAX] = { false };
        for (int j = 0; j < MAX; j++) {
            C[j] = HitBox(T, O[j]);
            if (C[j] == true) { delete T; delete[] O; Scorepage(k); break_loop = true; break; }
        }
        if (break_loop == true)break;
        Sleep(10);
    }
}
