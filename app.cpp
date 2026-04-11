#include <app.h>
#include <main_frame.h>
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* main_frame = new MainFrame("C++ GUI");
    main_frame->SetClientSize(800, 600);
    main_frame->Center();
    main_frame->Show();
    return true;
}