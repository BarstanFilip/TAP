#pragma once
class Punct
{
private:
	double x; //abscisa
	double y;//ordonata
public:
	Punct(double x, double y);
	Punct(const Punct& other);
	~Punct();

	friend double distanta(const Punct & punct1, const Punct & punct22);
};

