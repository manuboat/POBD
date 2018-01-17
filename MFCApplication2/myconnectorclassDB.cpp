#include "stdafx.h"
#include "myconnectorclassDB.h"



myconnectorclassDB::myconnectorclassDB()
{
}


myconnectorclassDB::~myconnectorclassDB()
{
}

void myconnectorclassDB::connect() {
	connection = mysql_init(NULL); // Initialise the instance
	connection = mysql_real_connect(connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
	// The command mysql_real_connect is included in the libraries
	CString message;
	if (connection == NULL) {
		// Add debug code here
		message.Format(_T("Unable to connect"));
		AfxMessageBox(message);
	}
	else {
		message.Format(_T("Connection successful!"));
		
		// and here
	}
}

CString myconnectorclassDB::CheckName(CString ID_Name) {
	CString value;

	CString query = _T("SELECT Costumer.Costumer_Name FROM Costumer WHERE Costumer.ID_Costumer =") + ID_Name + _T("");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

void myconnectorclassDB::ListProduct() {
	
	CString val;
	

	CString query = _T("SELECT  needs.ID_Plant, needs.ID_Warehouse  FROM needs");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));
		value1.push_back(CPtoUnicode(row[1], 1251));
		
	}
	
}

void myconnectorclassDB::Query(CString query)
{
	wchar_t *p = query.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8, sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good news is
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the result
}

CString myconnectorclassDB::CPtoUnicode(const char* CPString,
	UINT CodePage)
{
	CString retValue;
	int len = MultiByteToWideChar(CodePage, 0, CPString, -1,
		NULL, 0);
	if (len == 0) { return retValue; }
	LPWSTR buffer = retValue.GetBuffer(len);
	MultiByteToWideChar(CodePage, 0, CPString, -1, buffer, len);
	retValue.ReleaseBuffer();
	return retValue;
}