// YDAlgorithm.h : YDAlgorithm DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CYDAlgorithmApp
// �йش���ʵ�ֵ���Ϣ������� YDAlgorithm.cpp
//

class CYDAlgorithmApp : public CWinApp
{
public:
	CYDAlgorithmApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
