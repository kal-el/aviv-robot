#include <string>
#include "Module.h"


class Shop {

private:
	string name;
	Module products[];
public:
	Shop(string nome, Module merci[]);

	~Shop();

	Module *getProductList();

	Module getModule(string nome);

}