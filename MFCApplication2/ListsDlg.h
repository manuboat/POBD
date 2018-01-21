#pragma once
#include <vector>
#include <string>
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"

using namespace std;

// CListsDlg dialog
class CListsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CListsDlg)

public:
	CListsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CListsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Lists };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float v_output;
	afx_msg void OnEnChangeEdit1();
	BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnStnClickedClock();
	CListCtrl m_listCtrl;
	CString Costumer;
	void LoadListBox();
	CListBox m_listBox;

protected:
	
public:
	CString m_ItemSelected;
	afx_msg void OnLbnSelchangeList2();
	CString m_Select_ID;
	
	CString m_Quantity;
	CString m_Total_Price;
	afx_msg void OnBnClickedButtonAddCart();
	
	afx_msg void OnEnChangeEditSelectId();
	
	afx_msg void OnEnChangeEditQuantity();
	CString m_timer;
	CString M_timer;
	BOOL v_FlagCheck3;
	CString Search;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	float m_Unit_Price;
	CString Date;
	afx_msg void OnBnClickedButton1();
	CDateTimeCtrl m_DateTime;
	int rdn(int y, int m, int d);

	int iYear;
	int iMonth;
	int iDay;
};
