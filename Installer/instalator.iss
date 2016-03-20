; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{5FE9CE1B-F664-4385-B1D6-6B41CCCB82EF}
AppName=The Hutries
AppVersion=1.1.1
;AppVerName=The Hutries 1.1.1
AppPublisher=ROMJO Studio
AppPublisherURL=https://github.com/MarcinJozwik/theHutries
AppSupportURL=https://github.com/MarcinJozwik/theHutries
AppUpdatesURL=https://github.com/MarcinJozwik/theHutries
DefaultDirName={pf}\The Hutries
DisableProgramGroupPage=yes
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "D:\Dokumenty\Marcin\the Hutries\GIT\theHutries\bin\Release\Launcher.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Dokumenty\Marcin\the Hutries\GIT\theHutries\bin\Release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\Dokumenty\Marcin\the Hutries\GIT\theHutries\bin\Release\readme.txt"; DestDir: "{app}"; Flags: isreadme

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\The Hutries"; Filename: "{app}\Launcher.exe"
Name: "{commondesktop}\The Hutries"; Filename: "{app}\Launcher.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\The Hutries"; Filename: "{app}\Launcher.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\Launcher.exe"; Description: "{cm:LaunchProgram,The Hutries}"; Flags: nowait postinstall skipifsilent

