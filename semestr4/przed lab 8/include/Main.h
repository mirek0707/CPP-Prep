#pragma once
#include<iostream>
#include<string>
using namespace std; 
class HP
{
public:
	HP()=default;
	HP(int h)
	{
		_hp=h;
	}
	string print() const
	{
		return "[" + std::to_string(_hp) + " HP]";
	}
	~HP(){}
private:
	int _hp;
};

class GameObj
{
public:
	GameObj()=default;
	GameObj(const string id):ID(id){}
	virtual ~GameObj()
	{

	}
	string id() const
	{
		return ID;
	}
	virtual string print() const 
	{
		return ID;
	}
	friend std::ostream &operator <<(std::ostream& s, const GameObj& go);
private:
	string ID;
};
std::ostream &operator <<(std::ostream& s, const GameObj& go)
{
	s<<go.print();
	return s;
}

class Character : virtual public GameObj
{
public:
	Character(HP &hp, const string n) : GameObj(""), health(hp), name(n){}
	string hp() const
	{
		return health.print();
	}
	string Name() const
	{
		return name;
	}
private:
	HP health;
	string name;

};

class Hurting : virtual public GameObj
{
public:
	Hurting(HP &hp) : GameObj(""), health(hp){}
	string hp() const
	{
		return health.print();
	}
	string print() const 
	{
		return "Jego uderzenie odbiera: "+Hurting::hp();
	}
private:
	HP health;
};

class Player : public Character
{
public:
	Player()=default;
	Player(HP hp, const std::string name, const std::string id) : GameObj(id), Character(hp, name) {}
	string print() const override
	{
		return "Player "+Name()+", ma "+Character::hp();
	}
};

class Bomb : public Hurting
{
public:
	Bomb()=default;
	Bomb(HP hp, const std::string id) : GameObj(id), Hurting(hp) {}
	string print() const override
	{
		return Hurting::print();
	}
};

class Boss : public Character, public Hurting
{
public:
	Boss()=default;
	Boss(HP hp1, const string name, HP hp2, const std::string id) : GameObj(id), Character(hp1, name), Hurting(hp2) {}
	string print() const override
	{
		return "Bad guy: "+Name()+", ma "+Character::hp()+'\n'+Hurting::print();
	}

};
