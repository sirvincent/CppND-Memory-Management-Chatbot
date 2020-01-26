#ifndef CHATGUI_H_
#define CHATGUI_H_

#define wxUSE_STATTEXT 1
#define wxUSE_STATBMP 1
#define wxUSE_TEXTCTRL 1

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/windowid.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

#include <memory>


class ChatLogic; // forward declaration

// middle part of the window containing the dialog between user and chatbot
class ChatBotPanelDialog : public wxScrolledWindow
{
private:
    // control elements
    wxBoxSizer *_dialogSizer;
    wxBitmap _image;

    //// STUDENT CODE
    ////

    std::unique_ptr<ChatLogic> _chatLogic;

    ////
    //// EOF STUDENT CODE

public:
    // constructor / destructor
    ChatBotPanelDialog(wxWindow *parent, wxWindowID id);
    ~ChatBotPanelDialog();

    // getter / setter
    // TODO: correct?
    ChatLogic *GetChatLogicHandle() { return _chatLogic.get(); }

    // events
    void paintEvent(wxPaintEvent &evt);
    void paintNow();
    void render(wxDC &dc);

    // proprietary functions
    void AddDialogItem(wxString text, bool isFromUser = true);
    void PrintChatbotResponse(std::string response);

    DECLARE_EVENT_TABLE()
};

// dialog item shown in ChatBotPanelDialog
class ChatBotPanelDialogItem : public wxPanel
{
private:
    // control elements
    wxStaticBitmap *_chatBotImg;
    wxStaticText *_chatBotTxt;

public:
    // constructor / destructor
    ChatBotPanelDialogItem(wxPanel *parent, wxString text, bool isFromUser);
};

// frame containing all control elements
class ChatBotFrame : public wxFrame
{
private:
    // control elements
    ChatBotPanelDialog *_panelDialog;
    wxTextCtrl *_userTextCtrl;

    // events
    void OnEnter(wxCommandEvent &WXUNUSED(event));

public:
    // constructor / desctructor
    ChatBotFrame(const wxString &title);
};

// control panel for background image display
class ChatBotFrameImagePanel : public wxPanel
{
    // control elements
    wxBitmap _image;

public:
    // constructor / desctructor
    ChatBotFrameImagePanel(wxFrame *parent);

    // events
    void paintEvent(wxPaintEvent &evt);
    void paintNow();
    void render(wxDC &dc);

    DECLARE_EVENT_TABLE()
};

// wxWidgets app that hides main()
class ChatBotApp : public wxApp
{
public:
    // events
    virtual bool OnInit();
};

#endif /* CHATGUI_H_ */
