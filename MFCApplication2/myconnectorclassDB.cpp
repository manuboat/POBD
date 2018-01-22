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

void myconnectorclassDB::ListOptions(CString Name, CString Item) {

	CString query = _T("select p.IDPlant as 'id', p.Name, p.Variety, p.Type, p.MST, p.Family from Plant as p, Produced as pp where p.")+Name+(" = '")+Item+("' and p.IDPlant = pp.IDPlant");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));
		value1.push_back(CPtoUnicode(row[1], 1251));
		value2.push_back(CPtoUnicode(row[2], 1251));
		value3.push_back(CPtoUnicode(row[3], 1251));
		value4.push_back(CPtoUnicode(row[4], 1251));
		value5.push_back(CPtoUnicode(row[5], 1251));
	}

}



CString myconnectorclassDB::CheckName(CString ID_Name) {
	CString value;
	
	CString query = _T("SELECT Plant.Name FROM Plant WHERE Plant.IDPlant =") + ID_Name + _T("");
	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

CString myconnectorclassDB::GetVariety(CString ID_Name) {
	CString value;

	CString query = _T("SELECT Plant.Variety FROM Plant WHERE Plant.IDPlant =") + ID_Name + _T("");
	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}


void myconnectorclassDB::ListProduct() {

	

	CString query = _T("select p.Name as 'Name' from Plant as p, Produced as i where i.IDPlant = p.IDPlant group by Name; ");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));
		
	}
	
}

void myconnectorclassDB::ListType(){

	CString query = _T("select * from (select p.Type as 'Type' from Plant as p, Produced as i where i.IDPlant = p.IDPlant) as t	group by Type; ");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));

	}

}

void myconnectorclassDB::ListFamily() {

	CString query = _T("select * from (select p.Family as 'Family' from Plant as p, Produced as i where i.IDPlant = p.IDPlant) as t	group by Family; ");

	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));

	}

}

void myconnectorclassDB::InsertProduct() {

	CString value;

	CString query = _T("INSERT INTO Plant (`IDPlant`,`Name`,`Variety`,`Type`,`MST`,`Family`) VALUES (16,'Alface','Roxa','BIO',10,'Fruta')");
	Query(query);

}

CString myconnectorclassDB::GetUnitPrice(CString ID) {
	CString value;

	CString query = _T("select UnitPrice from Produced where IDPlant =") + ID + _T("");
	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

void myconnectorclassDB::InsertPlant(CString Name, CString Variety, CString Type, CString MST, CString Family){

	
	CString query = _T("INSERT INTO Plant (`Name`,`Variety`,`Type`,`MST`,`Family`) VALUES	( '") + Name + _T("', '") + Variety + _T("', '") + Type + _T("', '") + MST + _T("', '") + Family + _T("'); ");
	Query(query);



};

void myconnectorclassDB::InsertProduced(CString Plant, CString Farm, CString Warehouse, CString Amount, CString UnitPrice, CString Date) {


	CString query = _T("INSERT INTO Produced (`IDPlant`,`IDFarm`,`IDWarehouse`,`Amount`,`UnitPrice`,`Date`) VALUES	( '") + Plant + _T("', '") + Farm + _T("', '") + Warehouse + _T("', '") + Amount + _T("', '") + UnitPrice + _T("', '") + Date + _T("'); ");
	Query(query);



};

CString myconnectorclassDB::GetID(CString Name){
	CString value;

	CString query = _T("select IDPlant from Plant where Name ='") + Name + _T("'");
	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;

};

CString myconnectorclassDB::GetIDCostumer(CString Name) {
	CString value;

	CString query = _T("select IDCostumer from Costumer where Name ='") + Name + _T("'");
	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;

};

void myconnectorclassDB::NewEntries() {

	CString query = _T("select*from(select p.Name as'P',f.Name,w.Location as'W',pp.Amount,pp.UnitPrice,pp.Date from Plant as p,Farm as f,Warehouse as w,Produced as pp where p.IDPlant=pp.IDPlant and f.IDFarm=pp.IDFarm and w.IDWarehouse=pp.IDWarehouse)as R where W='New'");


	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));
		value1.push_back(CPtoUnicode(row[1], 1251));
		value2.push_back(CPtoUnicode(row[2], 1251));
		value3.push_back(CPtoUnicode(row[3], 1251));
		value4.push_back(CPtoUnicode(row[4], 1251));
		value5.push_back(CPtoUnicode(row[5], 1251));
	}

}


void myconnectorclassDB::ChangeWarehouse(CString WareHouse, CString Plant) {


	CString query = _T("UPDATE Produced SET IDWarehouse='")+ WareHouse +_T("' WHERE IDPLant='")+ Plant +_T("';");
	Query(query);



};

void myconnectorclassDB::GetStatus() {

	CString query = _T("select s.IDWarehouse, w.Location, concat(s.Stored/w.Capacity*100,'% ')as 'Stored', w.Capacity from(select pp.IDWarehouse, sum(pp.Amount) as 'Stored' from  Produced as pp group by pp.IDWarehouse) as s, Warehouse as w where s.IDWarehouse = w.IDWarehouse");


	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value.push_back(CPtoUnicode(row[0], 1251));
		value1.push_back(CPtoUnicode(row[1], 1251));
		value2.push_back(CPtoUnicode(row[2], 1251));
		value3.push_back(CPtoUnicode(row[3], 1251));
	}

}

void myconnectorclassDB::InsertOrder(CString Date, CString Status, CString Cost, CString ETA) {


	CString query = _T("INSERT INTO `TOrder` (`Date`,`Status`,`Cost`,`ETA`)	VALUES ('")+ Date + ("','") + Status + ("','") + Cost + ("','") + ETA + ("'); ");
	Query(query);



};

void myconnectorclassDB::InsertIncludes(CString OrderID, CString PlantID, CString FarmID, CString IDWarehouse, CString Amount) {


	CString query = _T("INSERT INTO `Include` (`IDOrder`,`IDPlant`,`IDFarm`,`IDWarehouse`,`Amount`)	VALUES ('") + OrderID + ("','") + PlantID + ("','") + FarmID + ("','") + IDWarehouse + ("','") + Amount + ("')");
	Query(query);



};

void myconnectorclassDB::InsertMakes(CString CostumerID, CString OrderID) {


	CString query = _T("INSERT INTO `Makes` (`IDCostumer`,`IDOrder`) VALUES	('")+ CostumerID +("','") + OrderID + ("')");
		Query(query);



};

CString myconnectorclassDB::GetIDOrder() {
	CString value;

	CString query = _T("SELECT * FROM TOrder ORDER BY IDOrder DESC LIMIT 1");
	Query(query);

	while ((row = mysql_fetch_row(result)) != NULL) {
		value = CPtoUnicode(row[0], 1251);
	}
	return value;

};

void myconnectorclassDB::GetIDFarmIDWare(CString IDPlant){

	CString query = _T("select IDFarm, IDWarehouse from Produced where IDPlant =")+ IDPlant +("");
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