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
{

}

CAdministratorDlg::~CAdministratorDlg()
{
}

void CAdministratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdministratorDlg, CDialogEx)
END_MESSAGE_MAP()


// CAdministrator message handlers
