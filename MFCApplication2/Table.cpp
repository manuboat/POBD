#include "stdafx.h"
#include "Table.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <Cstring>


Table::Table()
{


	CString message;
	vector<string> text_file;

	ifstream ifs("Contactos.txt");
	if (ifs.fail())
	{
		message.Format(_T("Unable to read the datafile"));
		AfxMessageBox(message);
		exit(1);
	}

	string temp, temp1, temp2;
	long temp3;
	while (getline(ifs, temp))
		text_file.push_back(temp);

	for (unsigned int i = 0; i < text_file.size(); i++) {
		istringstream ss(text_file[i]);
		ss >> temp1 >> temp2 >> temp3;
		Name.push_back(temp1);
		Mail.push_back(temp2);
		Mobile.push_back(temp3);
	}
	ifs.close();
}


Table::~Table()
{
}
