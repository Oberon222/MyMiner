#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <list>
#include <fstream>
using namespace std;



void InitSizeI(int a);
void InitSizeJ(int b);
void InitCountMine(int c);
void FieldInit();
void DrowField();
void Set_Mine();
void showMines(int colorCode);
bool youWin();
bool youAreLoser();
bool Shot(int x, int y);

void Game();
