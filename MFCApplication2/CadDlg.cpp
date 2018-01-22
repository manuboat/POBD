// CadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "CadDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"
#include "Login.h"


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
	DDX_Control(pDX, IDC_LIST3, m_ListBox1);
	DDX_Control(pDX, IDC_LIST4, m_ListBox2);
}


BEGIN_MESSAGE_MAP(CadDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CadDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CadDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CadDlg message handlers
BOOL CadDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog. The framework does this automatically
	// when the application's main window is not a dialog
	     // Set small icon




	m_ListBox1.InsertColumn(0, L"IDCostumer", LVCFMT_LEFT, 100);
	m_ListBox1.InsertColumn(1, L"Name", LVCFMT_LEFT, 100);
	m_ListBox1.InsertColumn(2, L"Consumption", LVCFMT_CENTER, 80);
	m_ListBox1.InsertColumn(3, L"Phone", LVCFMT_LEFT, 100);
	m_ListBox1.InsertColumn(4, L"Mail", LVCFMT_LEFT, 80);

	int nItem;
	
	nItem = m_ListBox1.InsertItem(0, L"4");
	m_ListBox1.SetItemText(nItem, 1, L"Ruben");
	m_ListBox1.SetItemText(nItem, 2, L"80");
	m_ListBox1.SetItemText(nItem, 3, L"934562324");
	m_ListBox1.SetItemText(nItem, 4, L"rubentecnico@gmail.com");

	nItem = m_ListBox1.InsertItem(0, L"1");
	m_ListBox1.SetItemText(nItem, 1, L"Manel");
	m_ListBox1.SetItemText(nItem, 2, L"60");
	m_ListBox1.SetItemText(nItem, 3, L"91645463324");
	m_ListBox1.SetItemText(nItem, 4, L"pingodoce@gmail.com");

	nItem = m_ListBox1.InsertItem(0, L"6");
	m_ListBox1.SetItemText(nItem, 1, L"Jose");
	m_ListBox1.SetItemText(nItem, 2, L"50");
	m_ListBox1.SetItemText(nItem, 3, L"943262324");
	m_ListBox1.SetItemText(nItem, 4, L"joseguerra@gmail.com");
	
	

									 // TODO: Add extra initialization here



	m_ListBox2.InsertColumn(0, L"IDFarm", LVCFMT_LEFT, 100);
	m_ListBox2.InsertColumn(1, L"Name", LVCFMT_LEFT, 100);
	m_ListBox2.InsertColumn(2, L"Supplied", LVCFMT_CENTER, 80);
	m_ListBox2.InsertColumn(3, L"Owner", LVCFMT_LEFT, 100);
	m_ListBox2.InsertColumn(4, L"Address", LVCFMT_LEFT, 80);
	m_ListBox2.InsertColumn(5, L"Date", LVCFMT_LEFT, 80);
	
	nItem = m_ListBox2.InsertItem(0, L"2");
	m_ListBox2.SetItemText(nItem, 1, L"Quinta Jose");
	m_ListBox2.SetItemText(nItem, 2, L"58");
	m_ListBox2.SetItemText(nItem, 3, L"David");
	m_ListBox2.SetItemText(nItem, 4, L"Algarve");
	m_ListBox2.SetItemText(nItem, 4, L"2018/01/22");

	nItem = m_ListBox2.InsertItem(0, L"1");
	m_ListBox2.SetItemText(nItem, 1, L"Herdade Vale da Rosa");
	m_ListBox2.SetItemText(nItem, 2, L"44");
	m_ListBox2.SetItemText(nItem, 3, L"Manel");
	m_ListBox2.SetItemText(nItem, 4, L"Alentejo");
	m_ListBox2.SetItemText(nItem, 4, L"2018/01/12");

	nItem = m_ListBox2.InsertItem(0, L"3");
	m_ListBox2.SetItemText(nItem, 1, L"WesternComboys");
	m_ListBox2.SetItemText(nItem, 2, L"22");
	m_ListBox2.SetItemText(nItem, 3, L"Duarte");
	m_ListBox2.SetItemText(nItem, 4, L"Texas");
	m_ListBox2.SetItemText(nItem, 4, L"2018/01/22");

	nItem = m_ListBox2.InsertItem(0, L"4");
	m_ListBox2.SetItemText(nItem, 1, L"Ze Wars");
	m_ListBox2.SetItemText(nItem, 2, L"9");
	m_ListBox2.SetItemText(nItem, 3, L"Jose");
	m_ListBox2.SetItemText(nItem, 4, L"Fundão");
	m_ListBox2.SetItemText(nItem, 4, L"2018/01/20");
	
									 
								 
									 
									 
									 
									 // Ask Mfc to create/insert a column

	myconnectorclassDB MyConnection;
	MyConnection.connect();

	MyConnection.NewEntries();

	m_ListBox.InsertColumn(0, L"ID", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(1,L"Plant",LVCFMT_LEFT,100);
	m_ListBox.InsertColumn(2, L"Farm", LVCFMT_CENTER, 80);
	m_ListBox.InsertColumn(3, L"Warehouse", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(4, L"Amount", LVCFMT_LEFT, 80);
	m_ListBox.InsertColumn(5, L"Unit Price", LVCFMT_LEFT, 80);
	m_ListBox.InsertColumn(6, L"Entry Date", LVCFMT_LEFT, 80);

	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		int nItem;

		nItem = m_ListBox.InsertItem(0, MyConnection.value[i]);
		m_ListBox.SetItemText(nItem, 1, MyConnection.value1[i]);
		m_ListBox.SetItemText(nItem, 2, MyConnection.value2[i]);
		m_ListBox.SetItemText(nItem, 3, MyConnection.value3[i]);
		m_ListBox.SetItemText(nItem, 4, MyConnection.value4[i]);
		m_ListBox.SetItemText(nItem, 5, MyConnection.value5[i]);
		m_ListBox.SetItemText(nItem, 6, MyConnection.value6[i]);
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

	Myconnection.ChangeWarehouse(m_Ware, m_Item);

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


void CadDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);

	CLogin Login;
	Login.DoModal();

	EndDialog(0);
	CDialogEx::OnOK();
}
