$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2024-08-21 22:46:11.375715000 +0000
+++ chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -83,7 +83,7 @@
 #include "ui/strings/grit/ui_strings.h"
 #include "ui/views/accessibility/view_accessibility.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
@@ -568,7 +568,7 @@ void ProfileMenuView::BuildIdentity() {
         badge_image_model, menu_title_, menu_subtitle_, management_label);
   } else {
     std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     profile_user_display_name = profile->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserDisplayName);
     profile_user_email = profile->GetPrefs()->GetString(
