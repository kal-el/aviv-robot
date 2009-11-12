#include <afxdb.h>
#include <afx.h>
#include <odbcinst.h>
#include <string>
#include <vector>
#include <stdio.h>

//#include "Module.h"
//#include "Ability.h"
#include "Shop.h"
#include "Mech.h"
using namespace std;


class DBOperations {

private:
	CDatabase cd;
	CRecordset rs;

public:

	DBOperations();

	~DBOperations();

	Module getModule(std::string nome);

	vector<Module> getListaModuli();

	Ability getAbility(std::string nome);

	vector<Ability> getListaAbility();

	Mech getEnemy(std::string nome);

	vector<Mech> getListaEnemy();

	Shop getShop(std::string nome, std::string type);

	//void saveGame();

	//Game loadGame();

};



DBOperations::DBOperations() {

	LPCTSTR conStr = _T("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\Project\CPP\Prova_DB\Debug\GestioneClienti.mdb;Persist Security Info=False;");
	cd.Open(NULL, false, true, conStr, true);

}


DBOperations::~DBOperations() {

	//delete cd;
	//delete rs;
	cd.~CDatabase();
	rs.~CRecordset();

}


Module DBOperations::getModule(std::string nome) {

	string query = "SELECT * FROM Modules Where nome = '" + nome + "'";
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query), CRecordset::readOnly);

	if(rs.GetRecordCount() == 0)
		return NULL;

	rs.MoveFirst();
	Module modulo;
	CDBVariant varValue;

	rs.GetFieldValue(_T("BonusX"), varValue);
	int bonusX = varValue.m_lVal;
		
	rs.GetFieldValue(_T("BonusY"), varValue);
	int bonusY = varValue.m_lVal;

	rs.GetFieldValue(_T("BonusZ"), varValue);
	int bonusZ = varValue.m_lVal;

	rs.GetFieldValue(_T("Tipo"), varValue);
	int type = varValue.m_lVal;

	rs.GetFieldValue(_T("Classe"), varValue);
	int classMask = varValue.m_lVal;

	rs.GetFieldValue(_T("Descrizione"), varValue);
	string desc = varValue.m_pstring;

	rs.GetFieldValue(_T("PrezzoVendita"), varValue);
	double vendita = varValue.m_dblVal;

	rs.GetFieldValue(_T("PrezzoAcquisto"), varValue);
	double acquisto = varValue.m_dblVal;

	delete rs;
	delete varValue;

	return new Module(bonusX, bonusY, bonusZ, type, classMask, nome, desc, acquisto, vendita);

}


vector<Module> DBOperations::getListaModuli(){

	std::string query = "SELECT Nome FROM Modules";
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query), CRecordset::readOnly);

	if(rs.GetRecordCount() == 0)
		return NULL;

	rs.MoveFirst();
	CDBVariant varValue;

	//Module *lista = malloc(rs.GetRecordCount() * sizeof(Module));
	vector<Module> lista;

	while(!rs.IsEOF()) {

		rs.MoveNext();

		rs.GetFieldValue(_T("Nome"), varValue);
		std::string nome = varValue.m_pstring;

		lista.push_back(getModule(nome));
	}

	//delete rs;
	//delete varValue;
	rs.~CRecordset();
	varValue.~CDBVariant();

	return lista;

}


Ability DBOperations::getAbility(std::string nome) {

	string query = "SELECT * FROM Abilities Where nome = '" + nome + "'";
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query), CRecordset::readOnly);

	if(rs.GetRecordCount() == 0)
		return NULL;

	rs.MoveFirst();
	Ability ability;
	CDBVariant varValue;

	rs.GetFieldValue(_T("Id"), varValue);
	long id = varValue.m_lVal;
		
	rs.GetFieldValue(_T("Name"), varValue);
	string name = varValue.m_pstring;

	rs.GetFieldValue(_T("Description"), varValue);
	string desc = varValue.m_pstring;


	CRecordset rs2;
	string query2 = "SELECT Effects.* FROM Effects, Ability_Effect Where IDAbility = '" + itoa(id) + "' " 
		+ "AND Ablity_Effect.IDEffetto = Effects.ID";
	rs2.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query2), CRecordset::readOnly);

	vector<Effect> effetti;
	while(!rs2.IsEOF()) {
	
		rs2.MoveNext();

		rs2.GetFieldValue(_T("Nome"), varValue);
		string eff_name = varValue.m_pstring;

		rs2.GetFieldValue(_T("Target"), varValue);
		string target = varValue.m_pstring;

		rs2.GetFieldValue(_T("IfTarget"), varValue);
		string if_target = varValue.m_pstring;

		rs2.GetFieldValue(_T("IfLauncher"), varValue);
		string if_launcher = varValue.m_pstring;

		rs2.GetFieldValue(_T("Valore"), varValue);
		long valore = varValue.m_lVal;

		rs2.GetFieldValue(_T("Status"), varValue);
		string status = varValue.m_pstring;
		
		//AGGIUNGERE STATUS a Effect.h
		effetti.push_back(new Effect(eff_name, target, value, if_launcher, if_target, status);

	}

	rs.GetFieldValue(_T("Level"), varValue);
	int level = varValue.m_lVal;

	rs.GetFieldValue(_T("Class"), varValue);
	int classMask = varValue.m_lVal;

	rs.GetFieldValue(_T("Delay"), varValue);
	float delay = varValue.m_fltVal;

	rs.GetFieldValue(_T("Tipo"), varValue);
	long type = varValue.m_lVal;

	delete rs2;
	delete rs;
	delete varValue;

	//AGGIUNGERE Type a Ability.h
	return new Ability(id, name, desc, effetti, level, classMask, delay, type);
}


vector<Ability> DBOperations::getListaAbility(){

	std::string query = "SELECT * FROM Abilities";
	rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query), CRecordset::readOnly);

	if(rs.GetRecordCount() == 0)
		return NULL;

	rs.MoveFirst();
	CDBVariant varValue;

	//Ability *lista = malloc(rs.GetRecordCount() * sizeof(Ability));
	vector<Ability> lista;

	while(!rs.IsEOF()) {
		
		rs.MoveNext();

		rs.GetFieldValue(_T("Name"), varValue);
		std::string name = varValue.m_pstring;

		lista.push_back(getAbility(nome));
	}

	//delete rs;
	//delete varValue;
	rs.~CRecordset();
	varValue.~CDBVariant();

	return lista;
}


Shop DBOperations::getShop(std::string nome, std::string type) {

	string query = "SELECT * FROM Shop_Weapon Where nome = '" + nome + "'";
	
	//string overloads '==' operator
	if(type == "Item")
		query = "SELECT * FROM Shop_Item Where nome = '" + nome + "'";

	rs.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query), CRecordset::readOnly);

	if(rs.GetRecordCount() == 0)
		return NULL;

	
	rs.MoveFirst();
	CDBVariant varValue;

	//Shop *lista = malloc(rs.GetRecordCount() * sizeof(Shop));
	vector<Module> modules;

	for(int i = 0; !rs.IsEOF(); i++) {
		rs.GetFieldValue(_T("Id"), varValue);
		long id = varValue.m_lVal;

		CRecordset rs2;
		string query2 = "SELECT * FROM Modules WHERE ID = " itoa(id);
		rs2.Open(AFX_DB_USE_DEFAULT_TYPE, _T(query2), CRecordset::readOnly);

		rs.GetFieldValue(_T("Nome"), varValue);
		string name = varValue.m_pstring;

		Module m = getModule(name);
		modules.push_back(m);
		
		rs2.~CRecordset();

		rs.MoveNext();
	}

	delete rs;
	delete varValue;

	return new Shop(nome, modules);	
}

