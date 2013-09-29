#ifndef ENNEMIS_H_INCLUDED
#define ENNEMIS_H_INCLUDED

#include "Personnage.h"

namespace TRPG
{
	class Ennemis : public Combattant
	{
	protected:
		int xp;
		int grade;

	public:
		Ennemis(const std::string& name, int lvl, int vie, int att, int def, int vit, int x, int grad) : Combattant(name, lvl, vie, att, def, vit), xp(x), grade(grad){}
		int getXp() const {return xp;}
		int getGrade() const {return grade;}
		void setXp(int x) {xp = x;}
		void setGrade(int g) {grade = g;}
		virtual std::string getClass() const=0;
	};

	class Empereur : public Ennemis
	{
	private:

	public:
		Empereur(const std::string& name, int lvl=1);
		std::string getClass() const {return "Empereur";}
		void lvlUp();
		void affiche() const;
	};
}

#endif // ENNEMIS_H_INCLUDED