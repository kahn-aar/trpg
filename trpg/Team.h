#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "Map.h"
#include "Heros.h"
#include <list>

namespace TRPG
{
	class Team
	{
	protected:
		list<Heros*> equipe;
		list<Item*> objets;
		int lvlTotal;
		int avgLvl;
	public:
		Team() : lvlTotal(0), avgLvl(0){}
		void ajoutHeros(Heros* h){equipe.push_back(h); lvlTotal += h->getLvl(); avgLvl = lvlTotal/getNbHeros();}
		void ajoutItem(Item* i){objets.push_back(i);}
		void supprHeros(Heros* h){equipe.remove(h); lvlTotal -= h->getLvl(); avgLvl = lvlTotal/getNbHeros();}
		void supprItem(Item* i){objets.remove(i);}
		int getNbHeros() const {return equipe.size();}
		int getNbItems() const {return objets.size();}
		bool morts() const;
		void operator<<(Heros* h){ajoutHeros(h);}
		void operator<<(Item* i){ajoutItem(i);}
		void affiche() const;

		class iterator
		{
			//friend class Team;
			list<Heros*>::iterator itList;
		public:
			iterator();
			iterator(list<Heros*>::iterator it) : itList(it){}
			iterator operator++() {++itList; return itList;}
			iterator operator--() {--itList; return itList;}
			iterator operator++(int) {return itList++;}
			iterator operator--(int) {return itList--;}
			Heros* operator*() {return *itList;}
			bool operator==(const iterator& it) const {return itList == it.itList;}
			bool operator!=(const iterator& it) const {return itList != it.itList;}
		};
		iterator begin(){return iterator(equipe.begin());}
		iterator end() {return iterator(equipe.end());}
	};
}

#endif // TEAM_H_INCLUDED