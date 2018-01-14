#pragma once
#include <vector>
#include <string>

using namespace std;

class Table
{
public:
	vector<long> Mobile;
	vector<string> Name, Mail;

	Table();
	virtual ~Table();
};

