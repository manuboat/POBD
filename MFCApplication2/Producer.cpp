// Producer.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Producer.h"
#include "afxdialogex.h"


// CProducer dialog

IMPLEMENT_DYNAMIC(CProducerDlg, CDialogEx)

CProducerDlg::CProducerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Producer, pParent)
	
{

}

CProducerDlg::~CProducerDlg()
{
}


void CProducerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(CProducerDlg, CDialogEx)
	
END_MESSAGE_MAP()

BOOL CProducerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}
