#include "Personnage.h"

namespace TRPG
{
	Combattant::Combattant(const string& name, int lvl, int vie, int att, int def, int vit) : Personnage(name), niveau(lvl), PDV_max(vie), pdv(vie), attaque_base(att), attaque(att), defense_base(def), defense(def), vitesse_base(vit), vitesse(vit), arme(0), armure(0)
	{

	}

	void Combattant::affiche() const
	{
		cout << nom << endl;
		cout << "niveau : " << niveau << endl;
		cout << "Vie : " << pdv << endl;
		cout << "attaque : " << attaque << endl;
		cout << "defense : " << defense << endl;
		cout << "vitesse : " << vitesse << endl;
		if (arme)
			cout << "arme : " << arme->getName() << endl;
	}

	void Combattant::attaquer(Combattant* cmb) const
	{
		cmb->recevoirDegats(attaque);
	}

	void Combattant::recevoirDegats(int degats)
	{
		degats -= defense;
		if (degats < 1)
			degats = 1;
		pdv -= degats;
		if (pdv < 0)
			pdv = 0;
		if (estMort())
			cout << "est mort" << endl;
	}

	void Combattant::equiperArme( Arme* weapon)
	{
		arme = weapon;
		attaque += weapon->getAtt();
	}

	int Combattant::getDistance(Map* carte, Combattant* cmb2) const
	{
		int x, y, x2, y2;
		for (unsigned int i = 0; i < TAILLE_MAX; i++)
			for (unsigned int j = 0; j < TAILLE_MAX; j++)
			{
				if (carte->getBattler(i, j) == this)
				{
					x = i;
					y = j;
				}
				else if (carte->getBattler(i, j) == cmb2)
				{
					x2 = i;
					y2 = j;
				}
			}
		int distance = abs(x - x2) + abs(y - y2);
		return distance;
	}

	void Combattant::deplacer(Map* carte, direction dir) const
	{
		switch (dir)
		{
			case haut: break;
			case bas: break;
			case droite: break;
			case gauche: break;
		}
	}
	
	void Combattant::ajoutItem(Item* i)
	{
		if(inventaire.size() == 4)
			throw trpg_exception("Trop d'items");
		else
			inventaire.push_back(i);
	}

	void Combattant::retraitItem(Item* i)
	{
		if(inventaire.size() == 0)
			throw trpg_exception("Plus d'items");
		else
			inventaire.remove(i);
	}


}