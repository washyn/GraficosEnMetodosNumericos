#include "PlanoXY.h"

HINSTANCE hInst;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_PAINT:
        {

            HDC hdc;
            PAINTSTRUCT paint_struct;
            RECT r;
            GetClientRect(hwndDlg, &r);
            hdc = BeginPaint(hwndDlg,&paint_struct);


            PuntoI p_ini(0,0);
            PuntoI p_fin(r.right,r.bottom);
            // SE CREA UNA INSTANCIA DE LA CLASE PLANOO
            PlanoXY plano1(hdc,20,p_ini,p_fin);


            EndPaint(hwndDlg,&paint_struct);
        }

        case WM_INITDIALOG:
        {
        }
        return TRUE;

        case WM_CLOSE:
        {
            EndDialog(hwndDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
            }
        }
        return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}