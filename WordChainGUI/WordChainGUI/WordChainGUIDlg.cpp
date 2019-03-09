
// WordChainGUIDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "WordChainGUI.h"
#include "WordChainGUIDlg.h"
#include "afxdialogex.h"
#include "WordChaindll.h"
#include "AnswerDisplayDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CWordChainGUIDlg 对话框



CWordChainGUIDlg::CWordChainGUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_WORDCHAINGUI_DIALOG, pParent)
	, m_answer(0)
	, m_wordAnsChain(_T(""))
	, m_headChar(_T(""))
	, m_tailChar(_T(""))
	, m_isLongestWord(TRUE)
	, m_enableLoop(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordChainGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOWANS, m_wordAnsChain);
	DDX_Control(pDX, IDC_SHOWANS, m_editorAnswer);
	DDX_Text(pDX, IDC_HEADCHAR, m_headChar);
	DDV_MaxChars(pDX, m_headChar, 1);
	DDX_Text(pDX, IDC_TAILCHAR, m_tailChar);
	DDV_MaxChars(pDX, m_tailChar, 1);
}

BEGIN_MESSAGE_MAP(CWordChainGUIDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CWordChainGUIDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CWordChainGUIDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CWordChainGUIDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_CHARC, &CWordChainGUIDlg::OnBnClickedRadioCharc)
	ON_BN_CLICKED(IDC_RADIO_WORDC, &CWordChainGUIDlg::OnBnClickedRadioWordc)
END_MESSAGE_MAP()


// CWordChainGUIDlg 消息处理程序

BOOL CWordChainGUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	((CButton *)GetDlgItem(IDC_RADIO_WORDC))->SetCheck(TRUE);//选上
	((CButton *)GetDlgItem(IDC_RADIO_CHARC))->SetCheck(FALSE);//不选上
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
	
}

void CWordChainGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWordChainGUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWordChainGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CWordChainGUIDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CWordChainGUIDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CWordChainGUIDlg::OnBnClickedOk()
{
	UpdateData(true);
	// TODO: 在此添加控件通知处理程序代码
	char *words[1000] = { "abc","cbb","bmm","mcd","dak","kao","jm","mssssssdfsdfssdadkk","jd","pp" };
	char *result[1000];
	char head = m_headChar.GetAt(0);
	char tail = m_tailChar.GetAt(0);
	if (m_isLongestWord)
	{
		m_answer = gen_chain_word(words, 10, result, head,tail, 1);
	}
	else
	{
		m_answer = gen_chain_char(words, 10, result, head, tail, 1);
	}
	CString str;
	for (int i = 0; i < m_answer; i++)
	{
		str += result[i];
		str += "\r\n";
	}
	m_wordAnsChain = str;
	AfxMessageBox(_T("css"));
	UpdateData(false);
}




void CWordChainGUIDlg::OnBnClickedRadioCharc()
{
	m_isLongestWord = false;
}


void CWordChainGUIDlg::OnBnClickedRadioWordc()
{
	m_isLongestWord = true;
}
