﻿#pragma once
#include "afxdialogex.h"


// Options 对话框

class Options : public CDialogEx
{
	DECLARE_DYNAMIC(Options)

public:
	Options(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Options();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
