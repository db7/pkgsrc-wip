$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig	2024-12-03 23:32:49.613842200 +0000
+++ third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -20,7 +20,7 @@
 #include "core/fxge/fx_font.h"
 #include "core/fxge/systemfontinfo_iface.h"
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS) && !BUILDFLAG(IS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -173,9 +173,8 @@ class CLinuxPlatform : public CFX_GEModu
   std::unique_ptr<SystemFontInfoIface> CreateDefaultSystemFontInfo() override {
     auto pInfo = std::make_unique<CFX_LinuxFontInfo>();
     if (!pInfo->ParseFontCfg(CFX_GEModule::Get()->GetUserFontPaths())) {
-      pInfo->AddPath("/usr/share/fonts");
-      pInfo->AddPath("/usr/share/X11/fonts/Type1");
-      pInfo->AddPath("/usr/share/X11/fonts/TTF");
+      pInfo->AddPath("/usr/X11R6/lib/X11/fonts/Type1");
+      pInfo->AddPath("/usr/X11R6/lib/X11/fonts/TTF");
       pInfo->AddPath("/usr/local/share/fonts");
     }
     return pInfo;
