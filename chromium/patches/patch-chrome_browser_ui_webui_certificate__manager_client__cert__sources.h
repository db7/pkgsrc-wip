$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2024-08-21 22:46:11.556733600 +0000
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -15,7 +15,7 @@ class Profile;
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreatePlatformClientCertSource();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
