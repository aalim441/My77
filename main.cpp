#include <afxwin.h>
#include <atlimage.h>
#include <afxdlgs.h>
CString str;
class CMainFrame : public CFrameWnd {
public:
	CMainFrame() {
		Create(NULL, L"Hi");
	}
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};
class CMyApp : public CWinApp {
	BOOL InitInstance() {
		CMainFrame* Frm = new CMainFrame();
		m_pMainWnd = Frm;
		Frm->ShowWindow(1);
		CFileDialog dlg(true);
		if (IDOK == dlg.DoModal()) {
			str = dlg.GetPathName();
		}
		return true;
	}
}; 
CMyApp App;  BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
ON_WM_PAINT()
END_MESSAGE_MAP()


void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	CImage img;
	img.Load(L"iu.jpg");
	img.Draw(dc, 0, 0);

	//CBrush b;
	//b.CreateSolidBrush(RGB(0, 0, 220));
	//dc.SelectObject(&b);
	//dc.Rectangle(0, 0, 50, 50);	
}
