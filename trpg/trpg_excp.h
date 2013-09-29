#ifndef TRPG_EXCP_H_INCLUDED
#define TRPG_EXCP_H_INCLUDED

#include <exception>

using namespace std;

namespace TRPG
{
	class trpg_exception : public exception
	{
		string info;
	public:
		trpg_exception(const string& str):info(str){}
		const char* what()const{return info.c_str(); }
	};
}

#endif // TRPG_EXCP_H_INCLUDED