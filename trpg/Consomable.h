#ifndef CONSOMABLE_H_INCLUDED
#define CONSOMABLE_H_INCLUDED

#include "Item.h"

namespace TRPG
{
	class Consomable : public Item
	{
	protected:

	public:
		Consomable(const string& name) : Item(name){}
	};

	class Potion : public Consomable
	{
	protected:
		int soin;

	public:
		Potion(const string& name, int heal) : Consomable(name), soin(heal){}
	};
}

#endif // CONSOMABLE_H_INCLUDED