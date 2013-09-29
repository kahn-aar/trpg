#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

namespace TRPG
{
	class Item
	{
	protected:
		string nom;
	public:
		Item(const string& name) : nom(name){}
		string getName() const {return nom;}
		virtual void affiche() const {cout << nom << endl;}
	};
}

#endif // ITEM_H_INCLUDED