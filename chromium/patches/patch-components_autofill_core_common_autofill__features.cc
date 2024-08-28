$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_features.cc.orig	2024-08-21 22:46:14.597045700 +0000
+++ components/autofill/core/common/autofill_features.cc
@@ -673,7 +673,7 @@ BASE_FEATURE(kAutofillSilentProfileUpdat
 // Enabled by default for Mac and Windows platforms.
 BASE_FEATURE(kAutofillContentEditableChangeEvents,
              "AutofillContentEditableChangeEvents",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
