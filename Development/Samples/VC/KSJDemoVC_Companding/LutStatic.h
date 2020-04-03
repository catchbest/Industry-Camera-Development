#pragma once


// CLutStatic

class CLutStatic : public CStatic
{
	DECLARE_DYNAMIC(CLutStatic)

public:
	CLutStatic();
	virtual ~CLutStatic();
	HANDLE    m_hKSJTableMaker;
	POINT     m_ptLButtonDown;
protected:
	//{{AFX_MSG(CSnapStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


