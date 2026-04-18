#pragma once
#include <wx/wx.h>
#include "database.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
private:
    DatabaseManager db;

    void OnButtonClicked(wxCommandEvent& event);
    enum {
            ID_MyButton = 1
    };
};
