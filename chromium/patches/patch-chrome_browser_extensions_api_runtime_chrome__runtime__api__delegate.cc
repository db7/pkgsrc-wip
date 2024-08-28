$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc.orig	2024-08-21 22:46:08.904461400 +0000
+++ chrome/browser/extensions/api/runtime/chrome_runtime_api_delegate.cc
@@ -284,7 +284,11 @@ bool ChromeRuntimeAPIDelegate::GetPlatfo
   } else if (strcmp(os, "linux") == 0) {
     info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else if (strcmp(os, "openbsd") == 0) {
-    info->os = extensions::api::runtime::PlatformOs::kOpenbsd;
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "freebsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
+  } else if (strcmp(os, "netbsd") == 0) {
+    info->os = extensions::api::runtime::PlatformOs::kLinux;
   } else {
     NOTREACHED_IN_MIGRATION() << "Platform not supported: " << os;
     return false;
