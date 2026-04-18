#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
private:
    void OnButtonClicked(wxCommandEvent& event);
    enum {
            ID_MyButton = 1
    };
};
