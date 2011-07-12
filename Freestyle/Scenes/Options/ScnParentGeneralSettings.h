#pragma once

#include "../../Tools/Generic/xboxtools.h"
#include "../../Tools/Generic/tools.h"

class CScnParentGeneralSettings : CXuiSceneImpl
{
public:

	enum GeneralSettingType 
	{
		GeneralSettings,
		TeamFSD,
		Updates,
		Weather,
		Reset,
		SettingListSize,
	};

	// Game List Setting Controls
	CXuiList m_SettingList;
	CXuiTextElement m_SettingTitle;
	CXuiControl m_SettingFocus, m_Back;

	CXuiScene m_SettingScenes[5];

	int currentSelection;
	bool inChild;

	// Implement Class
    XUI_IMPLEMENT_CLASS( CScnParentGeneralSettings, L"ScnParentGeneralSettings", XUI_CLASS_SCENE )

	XUI_BEGIN_MSG_MAP()
		XUI_ON_XM_INIT(OnInit)
        XUI_ON_XM_NOTIFY_PRESS( OnNotifyPress )
		XUI_ON_XM_NOTIFY_SELCHANGED( OnNotifySelChanged )
		XUI_ON_XM_NOTIFY_SET_FOCUS( OnNotifySetFocus )
	XUI_END_MSG_MAP()

	// Constructor / Destructor
	CScnParentGeneralSettings();
	~CScnParentGeneralSettings();

	HRESULT OnInit(XUIMessageInit *pInitData, BOOL& bHandled);
	HRESULT OnNotifyPress( HXUIOBJ hObjPressed, BOOL& bHandled );
	HRESULT OnNotifySelChanged( HXUIOBJ hObjSource, XUINotifySelChanged* pNotifySelChangedData, BOOL& bHandled );
	HRESULT OnNotifySetFocus( HXUIOBJ hObjSource, XUINotifyFocus *pNotifyFocusData, BOOL& bHandled );

	HRESULT InitializeChildren( void );
	void ShowSetting(int value);
};