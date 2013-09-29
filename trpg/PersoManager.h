#include <list>
#include "Personnage.h"

namespace TRPG
{
	class PersoManager
	{
	private:
		list<Personnage*> persos;
		static PersoManager* instance;
		PersoManager(){}
		PersoManager(const PersoManager& pm);
		PersoManager& operator=(const PersoManager& pm);
	
	public:
	
		static PersoManager* getInstance();
		static void releaseInstance();
	

	};
}