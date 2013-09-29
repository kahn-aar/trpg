#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED



#include <string>
#define TAILLE_MAX 30
#include <iostream>
#include <list>
#include "trpg_excp.h"
#include "Equipement.h"
#include "Map.h"
using namespace std;



namespace TRPG
{
	class Map;

	typedef enum direction direction;
	enum direction{haut, bas, droite, gauche};

	class Personnage
	{
	protected:
		string nom;
	public:
		Personnage(const string& name) : nom(name) {}
		string getName() const {return nom;}
		void setName(const string& name) {nom = name;}
	};

	class NPC : public Personnage
	{
	private:
		string dialogue;
	public:
		NPC(const string& name, const string& dial) : Personnage(name), dialogue(dial){}
		string getDialogue() const {return dialogue;}
	};

	class Combattant : public Personnage
	{
	protected:
		int niveau;
		int PDV_max;
		int pdv;
		int attaque_base;
		int attaque;
		int defense_base;
		int defense;
		int vitesse_base;
		int vitesse;
		int dist_depl;
		Arme* arme;
		Armure* armure;
		list<Item*> inventaire;

	public:
		Combattant(const string& name, int lvl, int vie, int att, int def, int vit);
		int getLvl() const {return niveau;}
		int getPdvMax() const {return PDV_max;}
		int getAtt() const {return attaque;}
		int getDef() const {return defense;}
		int getVit() const {return vitesse;}
		int getDistDepl() const {return dist_depl;}
		//Etc...
		Arme* getArme() const {return arme;}
		Armure* getArmure() const {return armure;}
		void affiche() const;
		bool estMort() const {return pdv == 0;}

		void attaquer(Combattant* cmb) const;
		void recevoirDegats(int degats);
		
		void equiperArme(Arme* weapon);

		int getDistance(Map* carte, Combattant* cmb2) const;
		void deplacer(Map* carte, direction dir) const;
		void ajoutItem(Item* i);
		void retraitItem(Item* i);

		bool operator<(const Combattant& batt) const {return vitesse < batt.getVit();}
		bool operator>(const Combattant& batt) const {return vitesse > batt.getVit();}
	};
}

#endif // PERSONNAGE_H_INCLUDED