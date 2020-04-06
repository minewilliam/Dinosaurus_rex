#ifndef GAME2D_H
#define GAME2D_H

#include <fstream>
#include <iostream>
#include <ctime>
#include "vecteur.h"
#include <random>
#include <pthread.h> //Find Equivalent for Qt

using namespace std;

struct Coord
{
	void operator+=(Coord v) {x += v.x; y += v.y;}
	void operator-=(Coord v) {x -= v.x; y -= v.y;}
	Coord operator+(const Coord v) {return {x + v.x , y + v.y};}
    int x, y;
};

struct Sprite2D
{
	Coord size = {0,0};
	Coord position = {0,0};
};

template<typename T>
struct List
{
	T* next = NULL;
    T* previous = NULL;
};

struct Texture : public Sprite2D
{
	Texture(char* name, Coord size);
	~Texture() {}

	char* getName() {return _name;}
	char** map;

	private:
	void load();
	char* _name;
};

#endif