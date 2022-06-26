
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <time.h>
#include"resource.h"

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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, sm(0)
	, ma(0)
	, mun(0)
	, showR(_T(""))
	, Rece(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_small, sm);
	DDX_Text(pDX, IDC_max, ma);
	DDX_Text(pDX, IDC_mun, mun);
	DDX_Text(pDX, IDC_SHOW, showR);
	DDX_Check(pDX, IDC_Recover, Rece);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
//	ON_BN_CLICKED(IDC_start, &CMFCApplication1Dlg::OnBnClickedstart)
ON_BN_CLICKED(IDC_start, &CMFCApplication1Dlg::OnBnClickedstart)
ON_BN_CLICKED(IDC_OPTION, &CMFCApplication1Dlg::OnBnClickedOption)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	DestroyWindow();
}


void CMFCApplication1Dlg::OnBnClickedstart()
{
	// TODO: 在此添加控件通知处理程序代码
	int times = 0;
	srand(time(0));
	CString wri{},so{"result:"};
	DWORD unsed{};
	UpdateData();
	if (sm>=ma)
	{
		MessageBox(L"biger");
		return;
	}
	if (ma - sm <= mun && Rece)
	{
		MessageBox(L"cover");
		return;
	}
	HANDLE fi = CreateFile(L"text.txt", GENERIC_WRITE| GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (Rece)
	{
		for (int i = 0; i < mun; i++)
		{
			int result = rand() % ma + sm;
			wri.Format(_T("%d"), result);
			if (so.Find(wri)+1)
			{
				i--;
				continue;
			}
			if (i == mun - 1)
			{
				so += wri;
				WriteFile(fi, wri, sizeof(TCHAR) * wri.GetLength(), &unsed, 0);
				break;
			}
			if (times==15)
			{
				wri += "\r\n";
				times = 0;
			}
			else
			{
				wri += ",";
			}
			so += wri;
			WriteFile(fi, wri, sizeof(TCHAR) * wri.GetLength(), &unsed, 0);
			times++;
		}
	}
	else
	{
		for (int i = 0; i < mun; i++)
		{
			int result = rand() % ma + sm;
			wri.Format(_T("%d"), result);
			if (i == mun - 1)
			{
				so += wri;
				WriteFile(fi, wri, sizeof(TCHAR) * wri.GetLength(), &unsed, 0);
				break;
			}
			if (times == 15)
			{
				wri += "\r\n";
				times = 0;
			}
			else
			{
				wri += ",";
			}
			so += wri;
			WriteFile(fi, wri, sizeof(TCHAR) * wri.GetLength(), &unsed, 0);
			times++;
		}
	}
	
	GetDlgItem(IDC_SHOW)->SetWindowTextW(so);
}


void CMFCApplication1Dlg::OnBnClickedOption()
{
	// TODO: 在此添加控件通知处理程序代码


}
