
// WordChainGUIDlg.h: 头文件
//

#pragma once
#include "afxwin.h"


// CWordChainGUIDlg 对话框
class CWordChainGUIDlg : public CDialog
{
// 构造
public:
	CWordChainGUIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORDCHAINGUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	int m_answer;
	CString m_wordAnsChain;
	CEdit m_editorAnswer;
	CString m_headChar;
	CString m_tailChar;
	BOOL m_isLongestWord;
	BOOL m_enableLoop;
	afx_msg void OnBnClickedRadioCharc();
	afx_msg void OnBnClickedRadioWordc();
	afx_msg void OnEnChangeEdit6();
	CString m_inputWords;
	afx_msg void OnBnClickedCheck1();
	CString m_inputFile;
};
