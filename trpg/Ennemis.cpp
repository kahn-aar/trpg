#include "Ennemis.h"
#include <random>

namespace TRPG
{
	Empereur::Empereur(const std::string& name, int lvl) : Ennemis(name, lvl, 0, 0, 0, 0, 500, 5)
	{
		random_device rd;
		attaque_base = rd()%5;
		defense_base = rd()%5;
		vitesse_base = rd()%3;
		pdv = rd()%15;
		if (lvl != 1)
			for (int i = 0; i < lvl; i++)
			{
				attaque_base += rd()%3;
				defense_base += rd()%3;
				vitesse_base += rd()%1;
				pdv += rd()%2;
			}
		attaque = attaque_base;
		defense = defense_base;
		vitesse = vitesse_base;
		PDV_max = pdv;
	}

	void Empereur::lvlUp()
	{
		random_device rd;

		niveau += 1;
		int addatt = rd()%3;
		int adddef = rd()%3;
		int addvit = rd()%1;
		int addpdv = rd()%2;
		attaque_base += addatt;
		defense_base += adddef;
		vitesse_base += addvit;
		pdv += addpdv;
		attaque += addatt;
		defense += adddef;
		vitesse += addvit;
		PDV_max += addpdv;

	}

	void Empereur::affiche() const
	{
		cout << "Empereur " << endl;
		Combattant::affiche();
	}
}