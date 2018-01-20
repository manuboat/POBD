// Administrator.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Administrator.h"
#include "afxdialogex.h"


// CAdministrator dialog

IMPLEMENT_DYNAMIC(CAdministratorDlg, CDialogEx)

CAdministratorDlg::CAdministratorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Administrator, pParent)
	, m_Name(_T(""))
{

}

CAdministratorDlg::~CAdministratorDlg()
{
}

void CAdministratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
}


BEGIN_MESSAGE_MAP(CAdministratorDlg, CDialogEx)
END_MESSAGE_MAP()


// CAdministrator message handlers
void CAboutDlg::OnBnClickedButtonLoadpng()
{
	// TODO: Add your control notification handler code here
}