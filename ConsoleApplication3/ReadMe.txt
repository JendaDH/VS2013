========================================================================
    CONSOLE APPLICATION : ConsoleApplication3 Project Overview
========================================================================

AppWizard has created this ConsoleApplication3 application for you.

This file contains a summary of what you will find in each of the files that
make up your ConsoleApplication3 application.


ConsoleApplication3.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

ConsoleApplication3.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

ConsoleApplication3.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ConsoleApplication3.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////


This application is taking care of extracting all the necesary information about installed applications and prepared cross-comapre 
list for the AirApp tool that checkes this list agains predefined content on the ColdFusion server.


*****************************************************************************
Hint



In order to build a more-or-less reliable list of applications that appear in the "Programs and Feautres" in the Control Panel, you have to consider that not all applications were installed using MSI. WMI only provides the ones installed with MSI.

Here is a short summary of what I've found out:

MSI applications always have a Product Code (GUID) subkey under HKLM\...\Uninstall and/or under HKLM\...\Installer\UserData\S-1-5-18\Products. In addition, they may have a key that looks like HKLM\...\Uninstall\NotAGuid.

Non-MSI applications do not have a product code, and therefore have keys like HKLM\...\Uninstall\NotAGuid or HKCU\...\Uninstall\NotAGuid.
