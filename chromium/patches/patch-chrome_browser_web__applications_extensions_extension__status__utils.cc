$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2024-11-14 01:04:05.019568200 +0000
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -25,7 +25,7 @@ namespace {
 
 const char* g_preinstalled_app_for_testing = nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(b/268221237): Remove this allow-list.
 const char kDefaultAllowedExtensionIds[] =
     "alhngdkjgnedakdlnamimgfihgkmenbh,"
@@ -107,7 +107,7 @@ bool IsExternalExtensionUninstalled(cont
   return prefs && prefs->IsExternalExtensionUninstalled(extension_id);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
