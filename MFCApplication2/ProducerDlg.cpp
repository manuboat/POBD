// ProducerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ProducerDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"

// ProducerDlg dialog

IMPLEMENT_DYNAMIC(ProducerDlg, CDialogEx)

ProducerDlg::ProducerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Producer, pParent)
	, m_Name(_T(""))
	, m_Type(_T(""))
	, m_MST(_T(""))
	, m_Family(_T(""))
	, m_ID(_T(""))
	, m_Amount(_T(""))
	, v_FlagCheck(FALSE)
{

}

ProducerDlg::~ProducerDlg()
{
}

void ProducerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_Variety);
	DDX_Text(pDX, IDC_EDIT4, m_Type);
	DDX_Text(pDX, IDC_EDIT5, m_MST);
	DDX_Text(pDX, IDC_EDIT6, m_Family);
	DDX_Text(pDX, IDC_EDIT7, m_ID);
	DDX_Text(pDX, IDC_EDIT8, m_Amount);
	DDX_Check(pDX, IDC_CHECK3, v_FlagCheck);
}


BEGIN_MESSAGE_MAP(ProducerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ProducerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ProducerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK3, &ProducerDlg::OnBnClickedCheck3)
END_MESSAGE_MAP()


// ProducerDlg message handlers


void ProducerDlg::OnBnClickedButton2()
{

	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	myconnectorclassDB Myconnection;
	Myconnection.connect();

	

	Myconnection.InsertPlant(m_Name, m_Variety, m_Type, m_MST, m_Family );
	IDPlant = Myconnection.GetID(m_Name);


	CTime CurrentTime = CTime::GetCurrentTime();

	int iDay = CurrentTime.GetDay();
	int iMonth = CurrentTime.GetMonth();
	int iYear = CurrentTime.GetYear();
	CString strDay, strMonth, strYear,m_Date;

	
		strDay.Format(_T("%d"), iDay);
	
		strMonth.Format(_T("%d"), iMonth);
	
		strYear.Format(_T("%d"), iYear);
	

	m_Date.Format(_T("%s/%s/%s"), strYear, strMonth, strDay);





	CString IDWarehouse;
	IDWarehouse = "0";
	CString UnitPrice;
	UnitPrice = "10";
	Myconnection.InsertProduced(IDPlant, m_ID , IDWarehouse,m_Amount, UnitPrice, m_Date);
	
	


	UpdateData(FALSE);
}


void ProducerDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_Amount.Empty();
	m_Family.Empty();
	m_ID.Empty();
	m_MST.Empty();
	m_Type.Empty();
	m_Variety.Empty();
	m_Name.Empty();
	UpdateData(FALSE);
}


void ProducerDlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (v_FlagCheck == (BOOL)true)
	{
		GetDlgItem(IDC_EDIT3)->EnableWindow(true);
		GetDlgItem(IDC_EDIT4)->EnableWindow(true);
		GetDlgItem(IDC_EDIT5)->EnableWindow(true);
		GetDlgItem(IDC_EDIT6)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT6)->EnableWindow(false);
	}
	UpdateData(FALSE);
}
