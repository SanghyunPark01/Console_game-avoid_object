#include <iostream>
#include <windows.h>
#include "Console.h"
#include <random>
#define MAX 10000
using namespace std;
class Obstacle;
class Item_Life;
// Class
class Object {
protected:
    int x=0,y=0;
public:
    Object() {};
    ~Object() {};
    void SetXY(int a, int b) { x = a; y = b; }
    void PrintObject(){
        GotoXY(x, y);
        cout << "";  //사람모양 유니코드
    }
    friend bool HitBox(Object* T,Obstacle S);
    friend bool HitBox(Object* T, Item_Life* L);
};
class Obstacle {
protected:
    int x = 0, y = 0;
public:
    Obstacle() {};
    ~Obstacle() {};
    void O_SetXY(int a, int b) { x = a; y = b; }
    void PrintObstacle() {
        GotoXY(x, y);
        cout << ""; //똥모양 유니코드
    }
    friend bool HitBox(Object* T, Obstacle S);
};
class Item_Life {
protected:
    int x=0, y=0;
public:
    Item_Life() {};
    ~Item_Life() {};
    void L_SetXY(int a, int b) { x = a; y = b; }
    void Print_Lifeitem() {
        GotoXY(x, y);
        cout << "";//하트모양 유니코드
    }
    friend bool HitBox(Object* T, Item_Life* L);
};
//value
int level = 1;
int life = 0;
//function
bool HitBox(Object* T, Obstacle S);
bool HitBox(Object* T, Item_Life* L);
void Menupage(void);
void Playgame(void);
int Menu_(int y);
void Print_Bar(int time);
void Print_SideBar();
void Scorepage(int score);
//function
int main(void)
{
    SetConsoleSize(120, 30);//콘솔창 사이즈 조절
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
        Print_SideBar();
        int mode;
        mode = Menu_(y);
        if (mode == 1 && (GetAsyncKeyState(VK_RETURN) & 0x8000)) { Playgame(); }
        if (mode == 2 && (GetAsyncKeyState(VK_RETURN) & 0x8000)) { Clear(); break; }
        Sleep(30);
        Clear();
    }
}
int Menu_(int y) {
    GotoXY(34, 10);
    cout << "< Menu >";
    GotoXY(32,12);
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
    cout <<"score : "<< time;
    GotoXY(0, 1);
    cout << "────────────────────────────────────────────────────────────────────────────────";
    GotoXY(1, 0);
    cout << "Stop game : press the \"ESC\" key";
    GotoXY(0, 29);
    cout << "────────────────────────────────────────────────────────────────────────────────";
    Print_SideBar();
}
void Print_SideBar(void) 
{
    for (int i = 0; i < 30; i++) {
        GotoXY(80, i);
        cout << "┃";
    }
    GotoXY(84, 3);
    if (life != 0) {
        cout << " Your Life ";
        for (int i = 0; i < life; i++) {
            cout << "♥";
        }
    }
    //  <editional explain>
    //expain key
    GotoXY(81, 22);
    cout << "-< Key >" << "───────────────────────────────";
    GotoXY(84, 24);
    cout << "Move";
    for (int i = 24; i < 29; i++) {
        GotoXY(90, i);
        cout << "|";
    }
    GotoXY(85, 26);
    cout << "";//윗쪽방향키 모양 유니코드
    GotoXY(85, 27);
    cout << "";//아래쪽방향키 모양 유니코드
    GotoXY(83, 27);
    cout << "";//왼쪽방향키 모양 유니코드
    GotoXY(87, 27);
    cout << "";//오른쪽방향키 모양 유니코드
    GotoXY(93, 24);
    cout << "Pause";
    GotoXY(93, 26);
    cout << "(Coming soon fron Ver 2.1)";

    //explain item
    GotoXY(81, 15);
    cout << "-< Item >" << "─────────────────────────────";
    GotoXY(82, 17);
    cout << "";//생명아이템 모양 유니코드
    cout << " : Life +1";
}
bool HitBox(Object* T, Obstacle S)
{
    if (T->x == S.x && T->y == S.y)return true;
    else return false;
}
bool HitBox(Object* T, Item_Life* L)
{
    if (T->x == L->x && T->y == L->y)return true;
    else return false;
}
void Scorepage(int score)
{
    while (1) {
        Clear();
        Print_SideBar();
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
    double i = 1;//score point

    //Item
    life = 1;
    
    
    //
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 78);

    //obstacle
    int Ox[MAX] = {0};
    int Oy[MAX] = {2,};
    bool obs[MAX] = { false };
    Obstacle* O = new Obstacle[MAX]; //가로범위 0~78 세로범위 2~29

    //item_life
    int Lx = 0;
    int Ly = 2;
    bool l_item = false;
    Item_Life* L_Object=new Item_Life();

    while (1) {
        Clear();
        //
        i += 0.05;
        int k = (int)i;//score point
        Print_Bar(k);

        //make obstacle
        for (int j = 0; j < level; j++) {
            if (!obs[j]) {
                Ox[j] = dis(gen);
                Oy[j] = 2;
                obs[j] = true;
                break;
            }
        }
        //make item_life
        if (l_item == false&& k % 5 == 0) {
            Lx = dis(gen);
            Ly = 2;
            l_item = true;
            level++;
        }
        //Get key value
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
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { life = 0; level = 1; delete T; delete[] O; break; }

        
        //print Object;
        T->SetXY(x, y);
        T->PrintObject();
        //print Obstacle;
        for (int j = 0; j < level; j++) {
            if (obs[j]) {
                O[j].O_SetXY(Ox[j], Oy[j]);
                O[j].PrintObstacle();
                Oy[j]++;
                if (Oy[j] > 29) obs[j] = false;
            }
        }
        
        //print item
        if (l_item) {
            L_Object->L_SetXY(Lx, Ly);
            L_Object->Print_Lifeitem();
            Ly++;
            if (Ly > 29) l_item = false;
        }

        //calculate things for object
        bool C[MAX] = { false };
        for (int j = 0; j < MAX; j++) {
            C[j] = HitBox(T, O[j]);
            if (C[j] == true) {life--;}
        }
        bool LC = false;
        LC = HitBox(T, L_Object);
        if (LC == true) {  life++; }

        if (life == 0) { delete T; delete[] O; level = 1; Scorepage(k);break; }
        
        Sleep(10);
    }
}
