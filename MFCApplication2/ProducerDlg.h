#pragma once
#include "afxwin.h"


// ProducerDlg dialog

class ProducerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ProducerDlg)

public:
	ProducerDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ProducerDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Producer };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
	CString m_Variety;
	CString m_Type;
	CString m_MST;
	CString m_Family;
	CString m_ID;
	CString m_Amount;
	afx_msg void OnBnClickedButton2();
	CString IDPlant;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCheck3();
	BOOL v_FlagCheck;
};
