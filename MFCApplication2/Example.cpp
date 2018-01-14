// Example.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Example.h"
#include "afxdialogex.h"


// CExample dialog

IMPLEMENT_DYNAMIC(CExample, CDialogEx)

CExample::CExample(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CExample::~CExample()
{
}

void CExample::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExample, CDialogEx)
	ON_NOTIFY(TCN_KEYDOWN, IDC_TAB1, &CExample::OnTcnKeydownTab1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CExample::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CExample message handlers


void CExample::OnTcnKeydownTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMTCKEYDOWN* pTCKeyDown = reinterpret_cast<NMTCKEYDOWN*>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CExample::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
