
// ���ʷ���dbmת��С���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ʷ���dbmת��С���.h"
#include "���ʷ���dbmת��С���Dlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int flag = 0;//��־

// C���ʷ���dbmת��С���Dlg �Ի���



C���ʷ���dbmת��С���Dlg::C���ʷ���dbmת��С���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DBM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ʷ���dbmת��С���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C���ʷ���dbmת��С���Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &C���ʷ���dbmת��С���Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &C���ʷ���dbmת��С���Dlg::OnBnClickedRadio1)
	ON_EN_CHANGE(IDC_EDIT2, &C���ʷ���dbmת��С���Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &C���ʷ���dbmת��С���Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &C���ʷ���dbmת��С���Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &C���ʷ���dbmת��С���Dlg::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT3, &C���ʷ���dbmת��С���Dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// C���ʷ���dbmת��С���Dlg ��Ϣ�������

BOOL C���ʷ���dbmת��С���Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CButton* radio = (CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);//����Ĭ��ѡ�ť

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C���ʷ���dbmת��С���Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ʷ���dbmת��С���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C���ʷ���dbmת��С���Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C���ʷ���dbmת��С���Dlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 0;
}


void C���ʷ���dbmת��С���Dlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C���ʷ���dbmת��С���Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	CString str;
	//��ȡ��������
	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	float   input;
	input = _tstof(str);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);//��ֵ
	float  r;
	r = _tstof(str);
	float vpp, pdbm, pmw;
	CString s;
	if (flag == 0) {//����ΪVpp
		vpp = input;
		pmw = pow(vpp, 2)*125 / r;
		pdbm = 10*log10f(pmw);
		s.Format("Pmw: %f \r\nPdbm: %f\r\n", pmw, pdbm);
	}
	else if(flag == 1){//����Ϊdbm
		pdbm = input;
		pmw = pow(10, pdbm / 10);
		vpp = sqrt(r*pmw / 125);
		s.Format("Pmw: %f \r\nVpp: %f\r\n", pmw, vpp);
	}
	else{//����Ϊpmw
		pmw = input;
		pdbm = 10*log10f(pmw);
		vpp = sqrt(r*pmw / 125);
		s.Format("Pdbm: %f \r\nVpp: %f\r\n", pdbm, vpp);
	}
	//��ʾ���������	
	GetDlgItem(IDC_EDIT2)->SetWindowTextA(s);
}


void C���ʷ���dbmת��С���Dlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 1;
}


void C���ʷ���dbmת��С���Dlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 2;
}


void C���ʷ���dbmת��С���Dlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
