// LutStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "LutStatic.h"


// CLutStatic

IMPLEMENT_DYNAMIC(CLutStatic, CStatic)

CLutStatic::CLutStatic()
{
	m_hKSJTableMaker = NULL;
}

CLutStatic::~CLutStatic()
{
}

BEGIN_MESSAGE_MAP(CLutStatic, CStatic)
	//{{AFX_MSG_MAP(CSnapStatic)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CLutStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here
	if (m_hKSJTableMaker)
		KSJTableMaker_Draw(m_hKSJTableMaker);
	// Do not call CStatic::OnPaint() for painting messages
}

void CLutStatic::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_hKSJTableMaker == NULL)    return;

	if (nFlags & MK_LBUTTON)
	{
		int    X = point.x - m_ptLButtonDown.x;
		int    Y = point.y - m_ptLButtonDown.y;

		KSJTableMaker_MoveEditPoint(m_hKSJTableMaker, X, Y);

		m_ptLButtonDown.x = point.x;
		m_ptLButtonDown.y = point.y;
	}
	else
	{
		KSJTableMaker_IsPassEditPoint(m_hKSJTableMaker, point.x, point.y);
	}

	CStatic::OnMouseMove(nFlags, point);
}

void CLutStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_hKSJTableMaker == NULL)    return;

	m_ptLButtonDown = point;

	KSJTableMaker_IsHitEditPoint(m_hKSJTableMaker, point.x, point.y);

	CStatic::OnLButtonDown(nFlags, point);
}

// CLutStatic 消息处理程序


