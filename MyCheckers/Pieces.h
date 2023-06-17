#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Pieces
{
public:
	
	virtual bool isKing() = 0;
	int color; //
private:

};

class Checkers:public Pieces 
{
public:
	bool isKing() override
	{ return false; }
};
class Kings :public Pieces
{	public:
	bool isKing() override
	{ return true; }
};

