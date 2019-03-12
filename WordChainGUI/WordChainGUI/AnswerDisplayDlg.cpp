// AnswerDisplayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WordChainGUI.h"
#include "AnswerDisplayDlg.h"
#include "afxdialogex.h"


// AnswerDisplayDlg 对话框

IMPLEMENT_DYNAMIC(AnswerDisplayDlg, CDialogEx)

AnswerDisplayDlg::AnswerDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ANSDIALOG, pParent)
	, m_ansLength(0)
	, m_wordStr("")
	, m_outFilename("")
{

}

AnswerDisplayDlg::~AnswerDisplayDlg()
{
}

void AnswerDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, m_ansLength);
	DDX_Text(pDX, IDC_EDIT1, m_wordStr);
	DDX_Text(pDX, IDC_EDIT2, m_outFilename);
}




BEGIN_MESSAGE_MAP(AnswerDisplayDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AnswerDisplayDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// AnswerDisplayDlg 消息处理程序


void output_file(CString& filename, CString &output)
{
	CFile file;
	file.Open(filename, CFile::modeCreate | CFile::modeWrite);
	int len = output.GetLength();
	//strlen(output);
	file.Write(output,len*sizeof(short int));
	file.Close();

}


void AnswerDisplayDlg::OnBnClickedButton1()
{
	UpdateData(true);
	output_file(m_outFilename,m_wordStr);

	UpdateData(false);

}
