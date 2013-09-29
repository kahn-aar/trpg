#ifndef HEROS_H_INCLUDED
#define HEROS_H_INCLUDED

#include "Personnage.h"
#include <random>

namespace TRPG
{
	class Heros : public Combattant
	{
	protected:
		int xp;
		int xp_next;
	public:
		Heros(const string& name, int lvl, int vie, int att, int def, int vit) : Combattant(name, lvl, vie, att, def, vit), xp(0){}
		int getXp() const {return xp;}
		int getXpNext() const {return xp_next;}
		void setXpNext(int newXp) {xp_next = newXp;}
		void addXp(int newXp);
		virtual void lvlUp()=0;
	};

	class Guerrier : public Heros
	{
	private:

	public:
		Guerrier(const string& name, int lvl=1);
		void lvlUp();
		void affiche() const;
	};
}

#endif // HEROS_H_INCLUDED