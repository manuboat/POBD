// ContactDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ContactDlg.h"
#include "afxdialogex.h"
#include "Table.h"
#include <Cstring> 


// CContactDlg dialog

IMPLEMENT_DYNAMIC(CContactDlg, CDialogEx)

CContactDlg::CContactDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Contact, pParent)
	, m_name(_T(""))
	, m_mail(_T(""))
	, m_mobile(0)
	, m_file(_T(""))
{

}

CContactDlg::~CContactDlg()
{
}

void CContactDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_mail);
	DDX_Text(pDX, IDC_EDIT3, m_mobile);
	DDX_Text(pDX, IDC_EDIT4, m_file);
}


BEGIN_MESSAGE_MAP(CContactDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CContactDlg::OnBnClickedButtonQuery)
END_MESSAGE_MAP()


// CContactDlg message handlers


void CContactDlg::OnBnClickedButtonQuery()
{
	// TODO: Add your control notification handler code here
	CString message;
	bool Flag(false);

	UpdateData(true);
	Table People;

	for (unsigned int i = 0; i < People.Name.size(); i++) {
		if (People.Name[i].c_str() == m_name) {
			m_mail = People.Mail[i].c_str();
			m_mobile = People.Mobile[i];
			Flag = true;
			break;
		}
	}
	
	if (Flag == false){
		message.Format(_T("Unable to find person"));
		AfxMessageBox(message);
	}
	UpdateData(false);

	}
