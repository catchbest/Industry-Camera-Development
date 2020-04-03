#if !defined(AFX_SNAPSTATIC_H__C41138AE_8851_4EFB_B315_8D2D4CBB548E__INCLUDED_)
#define AFX_SNAPSTATIC_H__C41138AE_8851_4EFB_B315_8D2D4CBB548E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SnapStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSnapStatic window

class CSnapStatic : public CStatic
{
// Construction
public:
	CSnapStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnapStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	void LoadImage( BYTE *pImageData, int nCaptureWidth, int nCaptureHeight, int nBitCount );
	virtual ~CSnapStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSnapStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	BITMAPINFO    *m_pPreviewBmpInfo;
	BYTE          *m_pPreviewBmpData;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAPSTATIC_H__C41138AE_8851_4EFB_B315_8D2D4CBB548E__INCLUDED_)
