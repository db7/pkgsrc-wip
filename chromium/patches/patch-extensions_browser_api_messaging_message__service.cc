$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/messaging/message_service.cc.orig	2024-08-21 22:46:19.940594000 +0000
+++ extensions/browser/api/messaging/message_service.cc
@@ -78,7 +78,7 @@ namespace {
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -551,7 +551,7 @@ void MessageService::OpenChannelToNative
     return;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool has_permission = extension->permissions_data()->HasAPIPermission(
       mojom::APIPermissionID::kNativeMessaging);
   if (!has_permission) {
