#pragma once
#include "afxcmn.h"


// CadDlg dialog

class CadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CadDlg)

public:
	CadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CadDlg();
	virtual BOOL OnInitDialog();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Admin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListBox;
	CString m_Item;

	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_Ware;
	afx_msg void OnBnClickedButton1();
	CListCtrl m_Status;
};
