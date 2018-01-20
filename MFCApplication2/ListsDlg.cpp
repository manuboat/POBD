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
	, v_output(0)
	, m_timer(_T(""))
	, m_ItemSelected(_T(""))
	, m_Select_ID(_T(""))
	
	, m_Quantity(_T(""))
	, m_Total_Price(_T(""))	
	, M_timer(_T(""))
	, m_Unit_Price(0)
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
	DDX_Text(pDX, IDC_EDIT1, v_output);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	DDX_Control(pDX, IDC_LIST2, m_listBox);
	DDX_Text(pDX, IDC_EDIT2, m_ItemSelected);
	DDX_Text(pDX, IDC_EDIT_Select_ID, m_Select_ID);

	DDX_Text(pDX, IDC_EDIT_Quantity, m_Quantity);
	DDX_Text(pDX, IDC_EDIT_Total_Price, m_Total_Price);
	DDX_Text(pDX, IDC_STATIC_TXT, m_timer);
	DDX_Text(pDX, IDC_EDIT4, M_timer);
	DDX_Text(pDX, IDC_EDIT_Unit_Price, m_Unit_Price);
}


BEGIN_MESSAGE_MAP(CListsDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CListsDlg::OnEnChangeEdit1)
	ON_WM_TIMER()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CListsDlg::OnDtnDatetimechangeDatetimepicker1)
	ON_LBN_SELCHANGE(IDC_LIST2, &CListsDlg::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_BUTTON_Add_Cart, &CListsDlg::OnBnClickedButtonAddCart)
	ON_EN_CHANGE(IDC_EDIT_Select_ID, &CListsDlg::OnEnChangeEditSelectId)
	ON_EN_CHANGE(IDC_EDIT_Quantity, &CListsDlg::OnEnChangeEditQuantity)
	ON_BN_CLICKED(IDC_RADIO3, &CListsDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO1, &CListsDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CListsDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CListsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


BOOL CListsDlg::OnInitDialog() {
CDialogEx::OnInitDialog();


m_listCtrl.InsertColumn(0, L"ID", LVCFMT_LEFT, 100);
m_listCtrl.InsertColumn(1, L"Name", LVCFMT_LEFT, 100);
m_listCtrl.InsertColumn(2, L"Variety", LVCFMT_LEFT, 80);
m_listCtrl.InsertColumn(3, L"Price", LVCFMT_LEFT, 80);
m_listCtrl.InsertColumn(4, L"Qt", LVCFMT_LEFT, 80);
m_listCtrl.InsertColumn(5, L"Total", LVCFMT_LEFT, 80);

// Set the icon for this dialog. The framework does this automatically
// when the application's main window is not a dialog    // Set small icon

								 // TODO: Add extra initialization here
/*								 // Ask Mfc to create/insert a column
myconnectorclassDB MyConnection;
MyConnection.connect();

MyConnection.ListProduct();

m_listCtrl.InsertColumn(
	0,              // Rank/order of item 
	L"ID",          // Caption for this header 
	LVCFMT_LEFT,    // Relative position of items under header 
	100);           // Width of items under header

m_listCtrl.InsertColumn(1, L"Name", LVCFMT_LEFT, 100);
m_listCtrl.InsertColumn(2, L"Variety", LVCFMT_LEFT, 80);
m_listCtrl.InsertColumn(3, L"Type", LVCFMT_LEFT, 80);
m_listCtrl.InsertColumn(4, L"MST", LVCFMT_LEFT, 80);

for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
int nItem;

nItem = m_listCtrl.InsertItem(0, MyConnection.value[i]);
m_listCtrl.SetItemText(nItem, 1, MyConnection.value1[i]);
m_listCtrl.SetItemText(nItem, 2, MyConnection.value2[i]);
m_listCtrl.SetItemText(nItem, 3, MyConnection.value3[i]);
m_listCtrl.SetItemText(nItem, 4, MyConnection.value4[i]);
}*/


return TRUE; // return TRUE unless you set the focus to a control
}

void CListsDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CListsDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialogEx::OnTimer(nIDEvent);
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default 
	CTime CurrentTime = CTime::GetCurrentTime();

	int iHours = CurrentTime.GetHour();
	int iMinutes = CurrentTime.GetMinute();
	int iSeconds = CurrentTime.GetSecond();
	CString strHours, strMinutes, strSeconds;

	if (iHours < 10)
		strHours.Format(_T("0%d"), iHours);
	else
		strHours.Format(_T("%d"), iHours);

	if (iMinutes < 10)
		strMinutes.Format(_T("0%d"), iMinutes);
	else
		strMinutes.Format(_T("%d"), iMinutes);

	if (iSeconds < 10)
		strSeconds.Format(_T("0%d"), iSeconds);
	else
		strSeconds.Format(_T("%d"), iSeconds);

	M_timer.Format(_T("%s:%s:%s"), strHours, strMinutes, strSeconds);

	UpdateData(FALSE);
	
}


void CListsDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CListsDlg::OnStnClickedClock()
{
	// TODO: Add your control notification handler code here
}




void CListsDlg::OnLbnSelchangeList2()
{
	CString s;
	// TODO: Add your control notification handler code here
	m_listBox.GetText(m_listBox.GetCurSel(), m_ItemSelected);
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	MyConnection.ListOptions( Search ,m_ItemSelected);

	m_ItemSelected = CString("|ID\t|Name\t\t|Variety\t\t|Type\t\t|MST\t\t|Family");
	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		s = CString("\r\n") + MyConnection.value[i] + "\t" + MyConnection.value1[i] + "\t\t" + MyConnection.value2[i] + "\t\t" + MyConnection.value3[i] + "\t\t" + MyConnection.value4[i] + "\t\t" + MyConnection.value5[i];
		m_ItemSelected += s;
	}


	UpdateData(FALSE);
}


void CListsDlg::OnBnClickedButtonAddCart()
{
	// TODO: Add your control notification handler code here
	CString r_Price;
	r_Price.Format(_T("%.2f"), m_Unit_Price);
	myconnectorclassDB Myconnector;
	Myconnector.connect();



	

		int nItem;

		nItem = m_listCtrl.InsertItem(0, m_Select_ID);
		m_listCtrl.SetItemText(nItem, 1, r_Price);
		m_listCtrl.SetItemText(nItem, 2, r_Price);
		m_listCtrl.SetItemText(nItem, 3, r_Price);
		m_listCtrl.SetItemText(nItem, 4, m_Quantity);
		m_listCtrl.SetItemText(nItem, 5, m_Total_Price);

		UpdateData(TRUE);
		float i;
		i = _wtof(m_Quantity);
		float f;
		f = i*m_Unit_Price;
		v_output += f;
		m_Select_ID.Empty();
		m_Quantity.Empty();
		m_Unit_Price = 0;
		m_Total_Price.Empty();
		UpdateData(FALSE);
}





void CListsDlg::OnEnChangeEditSelectId()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
	UpdateData(TRUE);
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	CString value;
	if(m_Select_ID.IsEmpty()==0){
	
	value = MyConnection.GetUnitPrice(m_Select_ID);
	m_Unit_Price = _wtof(value);
	UpdateData(FALSE);
	}
}


void CListsDlg::OnEnChangeEditQuantity()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);

	float i1;
	i1 = _wtof(m_Quantity);

	float f2;
	f2 = i1*m_Unit_Price;

	m_Total_Price.Format(_T("%.2f"),f2);
	
	UpdateData(FALSE);
}



void CListsDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	m_listBox.ResetContent();
	Search = CString("Name");
	UpdateData(TRUE);

		myconnectorclassDB MyConnection;
		MyConnection.connect();

		MyConnection.ListProduct();

		for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
			m_listBox.AddString(MyConnection.value[i]);
		}

	UpdateData(FALSE);
}


void CListsDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	Search = CString("Type");
	m_listBox.ResetContent();
	UpdateData(TRUE);
	myconnectorclassDB MyConnection;
	MyConnection.connect();

	MyConnection.ListType();

	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		m_listBox.AddString(MyConnection.value[i]);
	}
	UpdateData(FALSE);
}

void CListsDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	Search = CString("Family");
	m_listBox.ResetContent();
	UpdateData(TRUE);
	myconnectorclassDB MyConnection;
	MyConnection.connect();

	MyConnection.ListFamily();

	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		m_listBox.AddString(MyConnection.value[i]);
	}
	UpdateData(FALSE);
}




void CListsDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	myconnectorclassDB Myconnector;
	Myconnector.connect();
	Myconnector.InsertProduct();

}

