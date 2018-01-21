// CadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "CadDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"


// CadDlg dialog

IMPLEMENT_DYNAMIC(CadDlg, CDialogEx)

CadDlg::CadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Admin, pParent)
	, m_Ware(_T(""))
{

}

CadDlg::~CadDlg()
{
}

void CadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ListBox);
	DDX_Text(pDX, IDC_EDIT1, m_Ware);
	DDX_Control(pDX, IDC_LIST1, m_Status);
}


BEGIN_MESSAGE_MAP(CadDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CadDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CadDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CadDlg message handlers
BOOL CadDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog. The framework does this automatically
	// when the application's main window is not a dialog
	     // Set small icon

									 // TODO: Add extra initialization here
							 // Ask Mfc to create/insert a column

	myconnectorclassDB MyConnection;
	MyConnection.connect();

	MyConnection.NewEntries();

	m_ListBox.InsertColumn(0,L"Plant",LVCFMT_LEFT,100);
	m_ListBox.InsertColumn(1, L"Farm", LVCFMT_CENTER, 80);
	m_ListBox.InsertColumn(2, L"Warehouse", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(3, L"Amount", LVCFMT_LEFT, 80);
	m_ListBox.InsertColumn(4, L"Unit Price", LVCFMT_LEFT, 80);
	m_ListBox.InsertColumn(5, L"Entry Date", LVCFMT_LEFT, 80);

	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		int nItem;

		nItem = m_ListBox.InsertItem(0, MyConnection.value[i]);
		m_ListBox.SetItemText(nItem, 1, MyConnection.value1[i]);
		m_ListBox.SetItemText(nItem, 2, MyConnection.value2[i]);
		m_ListBox.SetItemText(nItem, 3, MyConnection.value3[i]);
		m_ListBox.SetItemText(nItem, 4, MyConnection.value4[i]);
		m_ListBox.SetItemText(nItem, 5, MyConnection.value5[i]);
	}
	

	MyConnection.GetStatus();

	m_Status.InsertColumn(0, L"IDWarehouse", LVCFMT_LEFT, 100);
	m_Status.InsertColumn(1, L"Location", LVCFMT_CENTER, 80);
	m_Status.InsertColumn(2, L"Stored", LVCFMT_LEFT, 100);
	m_Status.InsertColumn(3, L"Capacity", LVCFMT_LEFT, 80);
	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		int nItem;

		nItem = m_Status.InsertItem(0, MyConnection.value[i]);
		m_Status.SetItemText(nItem, 1, MyConnection.value1[i]);
		m_Status.SetItemText(nItem, 2, MyConnection.value2[i]);
		m_Status.SetItemText(nItem, 3, MyConnection.value3[i]);
		
	}
	

	return TRUE; // return TRUE unless you set the focus to a control
}




void CadDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	int row = m_ListBox.GetSelectionMark();

	if (row < 0)

		return;

	m_Item = m_ListBox.GetItemText(row, 0);

	

	*pResult = 0;
}


void CadDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	myconnectorclassDB Myconnection;
	Myconnection.connect();
	
	CString value = Myconnection.GetID(m_Item);

	Myconnection.ChangeWarehouse(m_Ware, value);

	myconnectorclassDB MyConnection;
	MyConnection.connect();

	MyConnection.NewEntries();

	m_ListBox.DeleteAllItems();

	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		int nItem;

		nItem = m_ListBox.InsertItem(0, MyConnection.value[i]);
		m_ListBox.SetItemText(nItem, 1, MyConnection.value1[i]);
		m_ListBox.SetItemText(nItem, 2, MyConnection.value2[i]);
		m_ListBox.SetItemText(nItem, 3, MyConnection.value3[i]);
		m_ListBox.SetItemText(nItem, 4, MyConnection.value4[i]);
		m_ListBox.SetItemText(nItem, 5, MyConnection.value5[i]);
	}

	MyConnection.GetStatus();

	m_Status.InsertColumn(0, L"IDWarehouse", LVCFMT_LEFT, 100);
	m_Status.InsertColumn(1, L"Location", LVCFMT_CENTER, 80);
	m_Status.InsertColumn(2, L"Stored", LVCFMT_LEFT, 100);
	m_Status.InsertColumn(3, L"Capacity", LVCFMT_LEFT, 80);
	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		int nItem;

		nItem = m_Status.InsertItem(0, MyConnection.value[i]);
		m_Status.SetItemText(nItem, 1, MyConnection.value1[i]);
		m_Status.SetItemText(nItem, 2, MyConnection.value2[i]);
		m_Status.SetItemText(nItem, 3, MyConnection.value3[i]);

	}
	UpdateData(FALSE);
	CString message;
	message.Format(_T("Warehouse Changed"));
	AfxMessageBox(message);
}
