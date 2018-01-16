// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ClientDlg.h"
#include "afxdialogex.h"
#include "Login.h"


// CClientDlg dialog

IMPLEMENT_DYNAMIC(CClientDlg, CDialogEx)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Client, pParent)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CClientDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CClientDlg message handlers


void CClientDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();

	ShowWindow(SW_HIDE);

	CLogin dlg;
	dlg.DoModal();

	EndDialog(0);
}
