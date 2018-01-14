// ListsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ListsDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"


// CListsDlg dialog

IMPLEMENT_DYNAMIC(CListsDlg, CDialogEx)

CListsDlg::CListsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Lists, pParent)
	, v_FlagCheck1(FALSE)
	, v_FlagCheck2(FALSE)
	, v_output(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CListsDlg::~CListsDlg()
{
}

void CListsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, v_FlagCheck1);
	DDX_Check(pDX, IDC_CHECK2, v_FlagCheck2);
	DDX_Text(pDX, IDC_EDIT1, v_output);
}


BEGIN_MESSAGE_MAP(CListsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CListsDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CListsDlg::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CListsDlg message handlers


void CListsDlg::OnBnClickedCheck1()
{
	CString list;
	vector<CString> list1;
	CString s;

	myconnectorclassDB MyConnection;
	MyConnection.connect();

	UpdateData(TRUE);
	list = MyConnection.ListProduct();
	v_output.Format(_T("\r\n%s"), list);
	UpdateData(FALSE);
	
	// TODO: Add your control notification handler code here
	/*short p = 124;
	v_output = CString("Gray") + CString("Cat");
	CString s;
	s.Format(_T("\r\nThe Total is %d"), p);
	v_output += s;
	UpdateData(false);*/

}


void CListsDlg::OnBnClickedCheck2()
{
	//UpdateData(true);
	// TODO: Add your control notification handler code here
	//short p = 150;
	//v_output = CString("Brown") + CString("Cat");
	//CString s;
	//s.Format(_T("\r\nThe Total is %d"), p);
	//v_output += s;
	//UpdateData(false);
}
