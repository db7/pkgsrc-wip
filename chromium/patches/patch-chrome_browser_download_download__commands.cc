$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/download/download_commands.cc.orig	2024-11-14 01:04:03.444552400 +0000
+++ chrome/browser/download/download_commands.cc
@@ -26,7 +26,7 @@
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -166,7 +166,7 @@ void DownloadCommands::ExecuteCommand(Co
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   if (!model_)
