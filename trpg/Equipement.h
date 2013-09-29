#ifndef EQUIPEMENT_H_INCLUDED
#define EQUIPEMENT_H_INCLUDED

#include "Item.h"


namespace TRPG
{
	class Arme : public Item
	{
	protected:
		int attaque;
		int portee;
	public:
		Arme(const string& name, int att, int port) : Item(name), attaque(att), portee(port){}
		int getAtt() const {return attaque;}
		int getPortee() const {return portee;}
		void affiche() const {Item::affiche(); cout << "arme" << endl << "attaque : " << attaque << "portée : " << portee << endl;}
	};

	class Armure : public Item
	{
	protected:
		int defense;
	public:
		Armure(const string& name, int def) : Item(name), defense(def){}
		int getAtt() const {return defense;}
		void affiche() const {Item::affiche(); cout << "armure" << endl << "defense : " << defense << endl;}
	};
}

#endif // EQUIPEMENT_H_INCLUDED
