
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
	int za;
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
	vector<CString> ListProduct();


	myconnectorclassDB();
	virtual ~myconnectorclassDB();
};

