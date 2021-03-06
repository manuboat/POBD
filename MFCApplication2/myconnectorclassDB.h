
#pragma once
#include "my_global.h"
#include "mysql.h"
#include <vector>
#include <string>
#include <CString>

using namespace std;

class myconnectorclassDB
{
private:
#define SERVER "db.ist.utl.pt"
#define USER "ist170940"
#define PASSWORD "gjbx9812"
#define DATABASE "ist170940"

	void Query(CString query);
	MYSQL *connection;

public:
	
	MYSQL_ROW row; // Another object based on the existing
				   // library, this one stores a single row from queries
	MYSQL_RES *result; // and this one the entire result
					   // from a query
	void connect(); // Connection function. Notice how
					// this is public, but the connection itself is
					// private.
	CString CPtoUnicode(const char* CPString, UINT CodePage);
	// Converts data from MySQL format to MFC's CString.
	// My Queries
	CString CheckName(CString ID_Name);
	void ListProduct();
	void ListType();
	void InsertProduct();
	void ListPlant();
	void ListFamily();
	void ListOptions(CString Name, CString Item);
	CString GetUnitPrice(CString ID);
	void InsertPlant(CString Name, CString Variety, CString Type, CString MST, CString Family);
	void InsertProduced(CString Plant, CString Farm, CString Warehouse, CString Amount, CString UnitPrice, CString Date);
	CString GetID(CString Name);
	vector<CString> value;
	vector<CString> value1;
	vector<CString> value2;
	vector<CString> value3;
	vector<CString> value4;
	vector<CString> value5;
	vector<CString> value6;
	CString GetIDCostumer(CString Name);
	void GetStatus();
	void NewEntries();
	void ChangeWarehouse(CString m_Ware,CString value);
	CString GetIDOrder();
	void GetIDFarmIDWare(CString IDPlant);
	void InsertOrder(CString Date, CString Status, CString Cost, CString ETA);
	void InsertIncludes(CString OrderID, CString PlantID, CString FarmID, CString IDWarehouse, CString Amount);
	void InsertMakes(CString CostumerID, CString OrderID);
	myconnectorclassDB();
	virtual ~myconnectorclassDB();
	CString GetVariety(CString m_Select_ID);
};

