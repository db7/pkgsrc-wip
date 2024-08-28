$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_ui_prefs.cc.orig	2024-08-21 22:46:11.043681000 +0000
+++ chrome/browser/ui/browser_ui_prefs.cc
@@ -72,7 +72,7 @@ void RegisterBrowserPrefs(PrefRegistrySi
   registry->RegisterIntegerPref(prefs::kDefaultBrowserDeclinedCount, 0);
   registry->RegisterTimePref(prefs::kDefaultBrowserFirstShownTime,
                              base::Time());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabel, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrl, std::string());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -179,7 +179,7 @@ void RegisterBrowserUserPrefs(user_prefs
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeFallbacks);
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeNavigations);
   registry->RegisterBooleanPref(prefs::kHttpsOnlyModeAutoEnabled, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrl, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabel, std::string());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
