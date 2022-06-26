// Options.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Options.h"


// Options 对话框

IMPLEMENT_DYNAMIC(Options, CDialogEx)

Options::Options(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Options::~Options()
{
}

void Options::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Options, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Options::OnBnClickedCancel)
END_MESSAGE_MAP()


// Options 消息处理程序


void Options::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	DestroyWindow();
}
