#pragma once


// CHexEdit

class CHexEdit : public CEdit
{
	DECLARE_DYNAMIC(CHexEdit)

public:
	CHexEdit();
	virtual ~CHexEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


