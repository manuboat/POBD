// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ClientDlg.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CClientDlg message handlers
