// MyEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "MyEdit.h"


// CHexEdit

IMPLEMENT_DYNAMIC(CHexEdit, CEdit)

CHexEdit::CHexEdit()
{

}

CHexEdit::~CHexEdit()
{
}


BEGIN_MESSAGE_MAP(CHexEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CHexEdit 消息处理程序




void CHexEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if ((nChar >= _T('0') && nChar <= _T('9')) ||
		(nChar >= _T('a') && nChar <= _T('f')) ||
		(nChar >= _T('A') && nChar <= _T('F')) ||
		nChar == VK_BACK ||
		nChar == VK_DELETE)      
	{
	
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
}

