// ProducerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ProducerDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"
#include "Login.h"
#include <random>

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
	, v_ID(_T(""))
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
	DDX_Text(pDX, IDC_EDIT9, v_ID);
	DDX_Control(pDX, IDC_EDIT9, c_ID);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
}


BEGIN_MESSAGE_MAP(ProducerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ProducerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ProducerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK3, &ProducerDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDOK, &ProducerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ProducerDlg message handlers


BOOL ProducerDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog. The framework does this automatically
	// when the application's main window is not a dialog
	// Set small icon

	// TODO: Add extra initialization here
	// Ask Mfc to create/insert a column

	myconnectorclassDB MyConnection;
	MyConnection.connect();

	MyConnection.ListPlant();

	m_ListBox.InsertColumn(0, L"ID", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(1, L"Plant", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(2, L"Variety", LVCFMT_CENTER, 80);
	m_ListBox.InsertColumn(3, L"Type", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(4, L"MST", LVCFMT_LEFT, 80);
	m_ListBox.InsertColumn(5, L"Family", LVCFMT_LEFT, 80);

	for (unsigned int i = 0; i < MyConnection.value.size(); i++) {
		int nItem;

		nItem = m_ListBox.InsertItem(0, MyConnection.value[i]);
		m_ListBox.SetItemText(nItem, 1, MyConnection.value1[i]);
		m_ListBox.SetItemText(nItem, 2, MyConnection.value2[i]);
		m_ListBox.SetItemText(nItem, 3, MyConnection.value3[i]);
		m_ListBox.SetItemText(nItem, 4, MyConnection.value4[i]);
		m_ListBox.SetItemText(nItem, 5, MyConnection.value5[i]);
	}


	


	return TRUE; // return TRUE unless you set the focus to a control
}


void ProducerDlg::OnBnClickedButton2()
{
	myconnectorclassDB Myconnection;
	Myconnection.connect();

	UpdateData(TRUE);

	if (v_FlagCheck == (BOOL)true){
	// TODO: Add your control notification handler code here

	Myconnection.InsertPlant(m_Name, m_Variety, m_Type, m_MST, m_Family );
	IDPlant = Myconnection.GetID(m_Name);
	}
	if(v_FlagCheck == (BOOL)false) {

	IDPlant= v_ID;
	}

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
		
	std::random_device seeder;
	//then make a mersenne twister engine
	std::mt19937 engine(seeder());
	//then the easy part... the distribution
	std::uniform_int_distribution<int> dist(1, 10);
	//then just generate the integer like this:
	int Price = dist(engine);

	UnitPrice.Format(_T("%i"),Price);
	Myconnection.InsertProduced(IDPlant, m_ID , IDWarehouse,m_Amount, UnitPrice, m_Date);
	
	

	Myconnection.ListPlant();

	m_ListBox.InsertColumn(0, L"ID", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(1, L"Plant", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(2, L"Variety", LVCFMT_CENTER, 80);
	m_ListBox.InsertColumn(3, L"Type", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(4, L"MST", LVCFMT_LEFT, 80);
	m_ListBox.InsertColumn(5, L"Family", LVCFMT_LEFT, 80);

	for (unsigned int i = 0; i < Myconnection.value.size(); i++) {
		int nItem;

		nItem = m_ListBox.InsertItem(0, Myconnection.value[i]);
		m_ListBox.SetItemText(nItem, 1, Myconnection.value1[i]);
		m_ListBox.SetItemText(nItem, 2, Myconnection.value2[i]);
		m_ListBox.SetItemText(nItem, 3, Myconnection.value3[i]);
		m_ListBox.SetItemText(nItem, 4, Myconnection.value4[i]);
		m_ListBox.SetItemText(nItem, 5, Myconnection.value5[i]);
	}
	


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
	v_ID.Empty();
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
		GetDlgItem(IDC_EDIT9)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_EDIT3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT6)->EnableWindow(false);
		GetDlgItem(IDC_EDIT9)->EnableWindow(true);
	}
	UpdateData(FALSE);
}


void ProducerDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);

	CLogin Login;
	Login.DoModal();

	EndDialog(0);
	CDialogEx::OnOK();
}
