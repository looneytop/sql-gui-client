#include "main_frame.h"
#include "database.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    
    wxButton* myButton = new wxButton(panel, ID_MyButton, "PePe ShEllE WaTaFa");
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->AddStretchSpacer();
    mainSizer->Add(myButton, 0, wxALL | wxALIGN_CENTER, 50);
    mainSizer->AddStretchSpacer();
    panel->SetSizer(mainSizer);
    Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this, ID_MyButton);
}
void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    if (db.open("my_database.db")) {
        db.create_table();

        if (db.add_record("Sergey User")) {
            wxMessageBox("SeX eVen!");
        } else {
            wxMessageBox("PiSyA DwA!");
        }

        db.close();

    } else {
        wxMessageBox("Не удалось создать БД");
    }


}