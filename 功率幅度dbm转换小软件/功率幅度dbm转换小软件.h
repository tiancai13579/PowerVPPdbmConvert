
// ���ʷ���dbmת��С���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ʷ���dbmת��С���App: 
// �йش����ʵ�֣������ ���ʷ���dbmת��С���.cpp
//

class C���ʷ���dbmת��С���App : public CWinApp
{
public:
	C���ʷ���dbmת��С���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ʷ���dbmת��С���App theApp;