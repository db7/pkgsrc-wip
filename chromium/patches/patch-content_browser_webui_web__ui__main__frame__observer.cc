$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2024-08-21 22:46:18.645461000 +0000
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -13,7 +13,7 @@
 #include "content/public/browser/navigation_handle.h"
 #include "content/public/browser/web_ui_controller.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/feature_list.h"
 #include "base/functional/callback_helpers.h"
 #include "base/logging.h"
@@ -31,7 +31,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Remove the pieces of the URL we don't want to send back with the error
 // reports. In particular, do not send query or fragments as those can have
 // privacy-sensitive information in them.
@@ -55,7 +55,7 @@ WebUIMainFrameObserver::WebUIMainFrameOb
 
 WebUIMainFrameObserver::~WebUIMainFrameObserver() = default;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void WebUIMainFrameObserver::OnDidAddMessageToConsole(
     RenderFrameHost* source_frame,
     blink::mojom::ConsoleMessageLevel log_level,
@@ -167,7 +167,7 @@ void WebUIMainFrameObserver::ReadyToComm
 
 // TODO(crbug.com/40149439) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   MaybeEnableWebUIJavaScriptErrorReporting(navigation_handle);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
