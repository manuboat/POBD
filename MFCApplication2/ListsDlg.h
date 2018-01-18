#pragma once
#include <vector>
#include <string>
#include "afxcmn.h"
#include "afxwin.h"

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
	BOOL v_FlagCheck1;
	BOOL v_FlagCheck2;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	CString v_output;
	afx_msg void OnEnChangeEdit1();
	BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnStnClickedClock();
	CListCtrl m_listCtrl;
	
	void LoadListBox();
	CListBox m_listBox;

protected:
	
public:
	CString m_ItemSelected;
	afx_msg void OnLbnSelchangeList2();
	CString m_Select_ID;
	CString m_Unit_Price;
	CString m_Quantity;
	CString m_Total_Price;
	afx_msg void OnBnClickedButtonAddCart();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnEnChangeEditSelectId();
	
	afx_msg void OnEnChangeEditQuantity();
	CString m_timer;
	CString M_timer;
};
