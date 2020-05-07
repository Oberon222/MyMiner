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
void Field_Init();
void Drow_Field();
void Set_Mine();
void show_Mines(int colorCode);
bool you_Win();
bool you_Are_Loser();
bool Shot(int x, int y);

void Game();
