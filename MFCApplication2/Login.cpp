// Login.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Login.h"
#include "afxdialogex.h"
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>
#include "LoginTxt.h"
#include <Cstring>
#include "CadDlg.h"
#include "ProducerDlg.h"
#include "ClientDlg.h"
#include <iomanip>
#include "ListsDlg.h"

using namespace std;


// CLogin dialog

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Login, pParent)
	
	, m_username(_T(""))
	, m_password(_T(""))
{
	str1 = "Administrator";
	str2 = "Client";
	str3 = "Producer";

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, m_comboBoxCtrl);
	DDX_Text(pDX, IDC_EDIT_Username, m_username);
	DDX_Text(pDX, IDC_EDIT_Password, m_password);
}



BOOL CLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_comboBoxCtrl.AddString(str1);
	m_comboBoxCtrl.AddString(str2); 
	m_comboBoxCtrl.AddString(str3);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLogin::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_Login, &CLogin::OnBnClickedButtonLogin)
	ON_EN_CHANGE(IDC_EDIT_Password, &CLogin::OnEnChangeEditPassword)
	ON_BN_CLICKED(IDC_BUTTON_Register, &CLogin::OnBnClickedButtonRegister)
END_MESSAGE_MAP()


// CLogin message handlers


void CLogin::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CLogin::OnBnClickedButtonLogin()
{
	CLoginTxt People;

	CString message;
	bool Flag(false);
	//Query: Given a Name, find the respective City of Birth and Birth Year
	UpdateData(true);

	CString m_type;
	m_comboBoxCtrl.GetLBText(m_comboBoxCtrl.GetCurSel(), m_type);

	for (unsigned int i = 0; i < People.user.size(); i++)
	{
		if (People.user[i].c_str() == m_username && People.pass[i].c_str() == m_password && People.type[i].c_str() == m_type )
		{
			if (People.type[i].c_str() == str1){
				//ShowWindow(SW_HIDE);

				CadDlg Admin;
				Admin.DoModal();
				
				//EndDialog(0);
		        }
			if (People.type[i].c_str() == str2) {
				ShowWindow(SW_HIDE);

				CListsDlg Client;
				Client.Costumer = m_username;
				Client.DoModal();

				EndDialog( 0 );
				
			}
			if (People.type[i].c_str() == str3) {
				ShowWindow(SW_HIDE);

				ProducerDlg Producer;
				Producer.DoModal();
				
				EndDialog(0);
			}
			Flag = true;
			break;
		}
	}
	if (Flag == false)
	{
		message.Format(_T("Error! Try different credencials!"));
		AfxMessageBox(message);
	}
	UpdateData(false);

}


void CLogin::OnEnChangeEditPassword()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CLogin::OnBnClickedButtonRegister()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString message;
	CString m_type;
	bool Flag(false);
	m_comboBoxCtrl.GetLBText(m_comboBoxCtrl.GetCurSel(), m_type);

	if (m_type == CString("Administrator"))
	{
		message.Format(_T("Not possible to register as Administrator!"));
		AfxMessageBox(message);
	}
	else{

		
	CLoginTxt People;

	for (unsigned int i = 0; i < People.user.size(); i++)
	{
		if (People.user[i].c_str() == m_username)
		{
			message.Format(_T("Username already exists!!"));
			AfxMessageBox(message);
			Flag = true;
			break;
		}
	}
		if(Flag == false){
			wofstream outfile;
			outfile.open("Login.txt", ios::app);
			outfile << (LPCTSTR)m_username << " " << (LPCTSTR)m_password << " " << (LPCTSTR)m_type << "\n";
			outfile.close();

			message.Format(_T("Registered!!"));
			AfxMessageBox(message);
		}
	

	
	}
	UpdateData(FALSE);
}
