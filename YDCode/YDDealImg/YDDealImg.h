// YDDealImg.h : YDDealImg DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CYDDealImgApp
// �йش���ʵ�ֵ���Ϣ������� YDDealImg.cpp
//

class CYDDealImgApp : public CWinApp
{
public:
	CYDDealImgApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
