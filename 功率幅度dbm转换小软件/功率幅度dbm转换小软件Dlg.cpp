
// 功率幅度dbm转换小软件Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "功率幅度dbm转换小软件.h"
#include "功率幅度dbm转换小软件Dlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 0;//标志

// C功率幅度dbm转换小软件Dlg 对话框



C功率幅度dbm转换小软件Dlg::C功率幅度dbm转换小软件Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DBM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C功率幅度dbm转换小软件Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C功率幅度dbm转换小软件Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &C功率幅度dbm转换小软件Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &C功率幅度dbm转换小软件Dlg::OnBnClickedRadio1)
	ON_EN_CHANGE(IDC_EDIT2, &C功率幅度dbm转换小软件Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &C功率幅度dbm转换小软件Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &C功率幅度dbm转换小软件Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &C功率幅度dbm转换小软件Dlg::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT3, &C功率幅度dbm转换小软件Dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// C功率幅度dbm转换小软件Dlg 消息处理程序

BOOL C功率幅度dbm转换小软件Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CButton* radio = (CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);//设置默认选项按钮

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C功率幅度dbm转换小软件Dlg::OnPaint()
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
HCURSOR C功率幅度dbm转换小软件Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C功率幅度dbm转换小软件Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C功率幅度dbm转换小软件Dlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 0;
}


void C功率幅度dbm转换小软件Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C功率幅度dbm转换小软件Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	CString str;
	//获取输入数据
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	float   input;
	input = _tstof(str);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);//阻值
	float  r;
	r = _tstof(str);
	float vpp, pdbm, pmw;
	CString s;
	if (flag == 0) {//输入为Vpp
		vpp = input;
		pmw = pow(vpp, 2)*125 / r;
		pdbm = 10*log10f(pmw);
		s.Format("Pmw: %f \r\nPdbm: %f\r\n", pmw, pdbm);
	}
	else if(flag == 1){//输入为dbm
		pdbm = input;
		pmw = pow(10, pdbm / 10);
		vpp = sqrt(r*pmw / 125);
		s.Format("Pmw: %f \r\nVpp: %f\r\n", pmw, vpp);
	}
	else{//输入为pmw
		pmw = input;
		pdbm = 10*log10f(pmw);
		vpp = sqrt(r*pmw / 125);
		s.Format("Pdbm: %f \r\nVpp: %f\r\n", pdbm, vpp);
	}
	//显示输出窗数据	
	GetDlgItem(IDC_EDIT2)->SetWindowTextA(s);
}


void C功率幅度dbm转换小软件Dlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 1;
}


void C功率幅度dbm转换小软件Dlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 2;
}


void C功率幅度dbm转换小软件Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
